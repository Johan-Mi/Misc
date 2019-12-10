#include <memory>
#include <string>
#include <iostream>
#include <vector>

enum class ExprType {
	Lambda, Application, Variable
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

void replaceVariable(Expression&, std::string, Expression);
struct Application {
	Lambda func;
	Expression arg;

	Expression eval() {
		Expression ret(func.body);
		replaceVariable(func.body, func.arg.name, arg);
		return ret;
	}
};

void replaceVariable(Lambda& target, std::string varName, Expression expr) {
	replaceVariable(target.body, varName, expr);
}
void replaceVariable(Application& target, std::string varName, Expression expr) {
	replaceVariable(target.func, varName, expr);
	replaceVariable(target.arg, varName, expr);
}
void replaceVariable(Expression& target, std::string varName, Expression expr) {
	switch(target.type) {
	case ExprType::Lambda:
		replaceVariable(*(target.lambdaPtr), varName, expr);
		break;
	case ExprType::Application:
		replaceVariable(*(target.applicationPtr), varName, expr);
	default:
		break;
	}
}



int main() {
	std::string input;
	std::getline(std::cin, input);

	std::vector<std::string> tokens;

	std::string current;
	for(unsigned i = 0; i < input.length(); i++) {
		if(input[i] == '(' || input[i] == ')' || input[i] == '.') {
			if(!current.empty()) {
				tokens.push_back(current);
				current.clear();
			}
			tokens.emplace_back(1, input[i]);
		} else if(input[i] == ' ') {
			if(!current.empty()) {
				tokens.push_back(current);
				current.clear();
			}
		} else {
			current += input[i];
		}
	}
	if(!current.empty())
		tokens.push_back(current);

	for(const auto& token : tokens)
		std::cout << token << '\n';

	return 0;
}
