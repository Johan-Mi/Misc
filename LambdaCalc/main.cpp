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
struct Variable;

struct Expression {
	union {
		std::unique_ptr<Lambda> lambdaPtr;
		std::unique_ptr<Application> applicationPtr;
		std::string variable;
	};
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
		default:
			break;
		}
	}
	~Expression() {}
};

struct Variable {
	std::string name;
};

struct Lambda {
	Variable arg;
	Expression body;

	Lambda(const Lambda& other) : arg(other.arg), body(other.body) {}
};

void subsituteVar(Expression&, std::string, Expression);
struct Application {
	Lambda func;
	Expression arg;

	Expression eval() {
		Expression ret(func.body);
		subsituteVar(func.body, func.arg.name, arg);
		return ret;
	}
};

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
	default:
		break;
	}
}

struct Token {
	TokenType type;
	std::string string;

	Token(TokenType type) : type(type) {}
	Token(const std::string& string) : string(string) {}
};



int main() {
	std::string input;
	std::getline(std::cin, input);

	std::vector<Token> tokens;
	std::string current;

	auto pushCurrent = [&](){
		if(current.length() != 0) {
			if(current == "lambda")
				tokens.push_back(TokenType::Lambda);
			else
				tokens.emplace_back(current);
			current.clear();
		}
	};

	for(unsigned i = 0; i < input.length(); i++) {
		if(input[i] == '(') {
			pushCurrent();
			tokens.emplace_back(TokenType::Lbracket);
		} else if(input[i] == ')') {
			pushCurrent();
			tokens.emplace_back(TokenType::Rbracket);
		} else if(input[i] == '.') {
			pushCurrent();
			tokens.emplace_back(TokenType::Dot);
		} else if(input[i] == ' ') {
			pushCurrent();
		} else {
			current += input[i];
		}
	}

	return 0;
}
