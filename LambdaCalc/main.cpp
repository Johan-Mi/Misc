#include <memory>
#include <string>
#include <iostream>
#include <vector>

enum class ExprType {
	Lambda, Application, Variable
};

enum class TokenType {
	Lbracket, Rbracket, Dot, Lambda, Variable
};

struct Lambda;
struct Application;
struct Expression;
struct Token;
struct Parser;

void subsituteVar(Expression&, std::string, Expression);
void subsituteVar(Lambda&, std::string, Expression);
void subsituteVar(Application&, std::string, Expression);

std::string toString(const Lambda&);
std::string toString(const Application&);
std::string toString(const Expression&);

struct Expression {
	std::unique_ptr<Lambda> lambdaPtr;
	std::unique_ptr<Application> applicationPtr;
	std::string variable;
	ExprType type;

	Expression() {}
	Expression(const Expression& other) : type(other.type) {
		switch(type) {
			case ExprType::Lambda:
				lambdaPtr = std::make_unique<Lambda>(*(other.lambdaPtr));
				break;
			case ExprType::Application:
				applicationPtr = std::make_unique<Application>(*(other.applicationPtr));
				break;
			case ExprType::Variable:
				variable = other.variable;
				break;
		}
	}

	Expression& operator=(const Expression& other) {
		type = other.type;
		switch(type) {
			case ExprType::Lambda:
				lambdaPtr = std::make_unique<Lambda>(*(other.lambdaPtr));
				break;
			case ExprType::Application:
				applicationPtr = std::make_unique<Application>(*(other.applicationPtr));
				break;
			case ExprType::Variable:
				variable = other.variable;
				break;
		}

		return *this;
	}
};

struct Lambda {
	std::string arg;
	Expression body;

	Lambda() {}
	Lambda(const std::string arg, const Expression& body) : arg(arg), body(body) {}
	Lambda(const Lambda& other) : arg(other.arg), body(other.body) {}
};

struct Application {
	Lambda func;
	Expression arg;

	Expression eval() {
		Expression ret(func.body);
		subsituteVar(func.body, func.arg, arg);
		return ret;
	}
};

std::string toString(const Expression& expression) {
	switch(expression.type) {
		case ExprType::Lambda:
			return toString(*(expression.lambdaPtr));
		case ExprType::Application:
			return toString(*(expression.applicationPtr));
		case ExprType::Variable:
			return expression.variable;
		default:
			return "";
	}
}

void subsituteVar(Lambda& target, std::string varName, Expression expr) {
	subsituteVar(target.body, varName, expr);
}
void subsituteVar(Application& target, std::string varName, Expression expr) {
	subsituteVar(target.func, varName, expr);
	subsituteVar(target.arg, varName, expr);
}
void subsituteVar(Expression& target, std::string varName, Expression expr) {
	switch(target.type) {
		case ExprType::Lambda:
			subsituteVar(*(target.lambdaPtr), varName, expr);
			break;
		case ExprType::Application:
			subsituteVar(*(target.applicationPtr), varName, expr);
		case ExprType::Variable:
			break;
	}
}

std::string toString(const Lambda& lambda) {
	return "λ" + lambda.arg + '.' + toString(lambda.body);
}

std::string toString(const Application& application) {
	return '(' + toString(application.func) + ' ' + toString(application.arg) + ')';
}

struct Token {
	TokenType type;
	std::string string;

	Token(TokenType type) : type(type) {}
	Token(const std::string& string) : string(string) {}
	Token(TokenType type, const std::string& string) : type(type), string(string) {}
};

struct Parser {
	std::vector<Token> tokens;
	int pos = 0;

	bool Parse(Expression* result) {
		if(pos >= tokens.size())
			return false;

		int backup = pos;
		Expression tempExpr1, tempExpr2;

		std::clog << "Checking for variable\n";
		if(tokens[pos].type == TokenType::Variable) {
			std::clog << "Found variable\n";
			result->type = ExprType::Variable;
			result->variable = tokens[pos++].string;
			std::clog << "Assigned variable to result\n";
			return true;
		}

		pos = backup;

		std::clog << "Checking for lambda\n";
		if(tokens[pos++].type == TokenType::Lambda 
				&& Parse(&tempExpr1)
				&& tempExpr1.type == ExprType::Variable
				&& tokens[pos++].type == TokenType::Dot
				&& Parse(&tempExpr2)) {
			std::clog << "Found lambda\n";
			result->type = ExprType::Lambda;
			result->lambdaPtr = std::make_unique<Lambda>(tempExpr1.variable, tempExpr2);
			return true;
		}

		pos = backup;

		std::clog << "Checking for application\n";
		if(Parse(&tempExpr1)
				&& tempExpr1.type == ExprType::Lambda
				&& Parse(&tempExpr2)) {
			std::clog << "Found application\n";
			result->type = ExprType::Application;
			result->applicationPtr = std::make_unique<Application>();
			result->applicationPtr->func = *(tempExpr1.lambdaPtr);
			result->applicationPtr->arg = tempExpr2;
			return true;
		}

		pos = backup;

		std::clog << "Checking for brackets\n";
		if(tokens[pos++].type == TokenType::Lbracket
				&& Parse(&tempExpr1)
				&& tokens[pos++].type == TokenType::Rbracket) {
			std::clog << "Found brackets\n";
			*result = tempExpr1;
			return true;
		}

		pos = backup;

		return false;
	}
};



int main() {
	std::string input;
	std::cout << "> ";
	std::getline(std::cin, input);

	Parser parser;
	std::string current;

	auto pushCurrent = [&](){
		if(current.length() != 0) {
			if(current == "lambda")
				parser.tokens.emplace_back(TokenType::Lambda);
			else
				parser.tokens.emplace_back(TokenType::Variable, current);
			current.clear();
		}
	};

	for(unsigned i = 0; i < input.length(); i++) {
		switch(input[i]) {
			case '(':
				pushCurrent();
				parser.tokens.emplace_back(TokenType::Lbracket);
				break;
			case ')':
				pushCurrent();
				parser.tokens.emplace_back(TokenType::Rbracket);
				break;
			case '.':
				pushCurrent();
				parser.tokens.emplace_back(TokenType::Dot);
				break;
			case ' ':
				pushCurrent();
				break;
			default:
				current += input[i];
				break;
		}
	}
	pushCurrent();

	Expression ret;
	if(parser.Parse(&ret)) {
		std::cout << toString(ret) << '\n';
	} else {
		std::cout << "Error\n";
	}

	return 0;
}
