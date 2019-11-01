#include <utility>
#include <typeinfo>

enum class ValueType {
	Int, Float, Bool
};

struct Value {
	ValueType type;
	union {
		int vInt;
		float vFloat;
		bool vBool;
	};
};

template<class T> ValueType valueTypeFromType;
template<> ValueType valueTypeFromType<int> = ValueType::Int;
template<> ValueType valueTypeFromType<float> = ValueType::Float;
template<> ValueType valueTypeFromType<bool> = ValueType::Bool;

const std::type_info& TypeFromValueType(ValueType v) {
	switch(v) {
	case ValueType::Int:	return typeid(int);
	case ValueType::Float:	return typeid(float);
	case ValueType::Bool:	return typeid(bool);
	}
}

template<class T1, class T2> const std::type_info& additionTypePromotion = typeid(T1{} + T2{});



struct Expression {
	virtual Expression* Eval() = 0;
};

struct ExprValue : Expression {
	Expression* Eval() override {
		return new ExprValue(*this);
	}

	Value value;
};

struct ExprAdd : Expression {
	Expression* left;
	Expression* right;

	Expression* Eval() override {
		delete std::exchange(left, left->Eval());
		delete std::exchange(right, right->Eval());
		ExprValue* retVal = new ExprValue;
		retVal->value.type = valueTypeFromType<additionTypePromotion<TypeFromValueType(((ExprValue*)left)->value.type), TypeFromValueType(((ExprValue*)right)->value.type)>>;
	}
};

struct ExprSub : Expression {
	Expression* left;
	Expression* right;
};

struct ExprMul : Expression {
	Expression* left;
	Expression* right;
};

struct ExprDiv : Expression {
	Expression* left;
	Expression* right;
};

struct ExprEqual : Expression {
	Expression* left;
	Expression* right;
};

struct ExprNotEqual : Expression {
	Expression* left;
	Expression* right;
};

struct ExprGreater : Expression {
	Expression* left;
	Expression* right;
};

struct ExprLess : Expression {
	Expression* left;
	Expression* right;
};

int main() {


	return 0;
}
