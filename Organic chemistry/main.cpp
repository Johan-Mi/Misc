#include <string>
#include <iostream>
#include <unordered_map>
#include <string_view>
#include <iomanip>

void fail();

int main() {
	std::cout << "Skriv ett organiskt ämne: ";
	std::string input;
	std::cin >> input;
	std::cout << '\n';

	for(char& c : input) {
		if(c >= 'A' && c <= 'Z')
			c += 32;
	}

	std::string formattedName = input;
	formattedName[0] -= 32;

	enum class Prefix {
		Met = 1, Et, Prop, But, Pent, Hex, Hept, Okt, Non, Dek
	} prefix;
	
	if(input == "kalkon") {
		std::cout << "Gobbel gobbel\n\n                    .--.\n    {\\             / q {\\\n    { `\\           \\ (-(~`\n   { '.{`\\          \\ \\ )\n   {'-{ ' \\  .-\"\"'-. \\ \\\n   {._{'.' \\/       '.) \\\n   {_.{.   {`            │\n   {._{ ' {   ;'-=-.     │\n    {-.{.' {  ';-=-.`    /\n     {._.{.;    '-=-   .'\n      {_.-' `'.__  _,-'\n               │││`\n              .='==,\n\n";
		exit(0);
	} else if(input.rfind("met", 0) == 0) {
		prefix = Prefix::Met;
		input = std::string(input.c_str() + 3);
	} else if(input.rfind("et", 0) == 0) {
		prefix = Prefix::Et;
		input = std::string(input.c_str() + 2);
	} else if(input.rfind("prop", 0) == 0) {
		prefix = Prefix::Prop;
		input = std::string(input.c_str() + 4);
	} else if(input.rfind("but", 0) == 0) {
		prefix = Prefix::But;
		input = std::string(input.c_str() + 3);
	} else if(input.rfind("pent", 0) == 0) {
		prefix = Prefix::Pent;
		input = std::string(input.c_str() + 4);
	} else if(input.rfind("hex", 0) == 0) {
		prefix = Prefix::Hex;
		input = std::string(input.c_str() + 3);
	} else if(input.rfind("hept", 0) == 0) {
		prefix = Prefix::Hept;
		input = std::string(input.c_str() + 4);
	} else if(input.rfind("okt", 0) == 0) {
		prefix = Prefix::Okt;
		input = std::string(input.c_str() + 3);
	} else if(input.rfind("non", 0) == 0) {
		prefix = Prefix::Non;
		input = std::string(input.c_str() + 3);
	} else if(input.rfind("dek", 0) == 0) {
		prefix = Prefix::Dek;
		input = std::string(input.c_str() + 3);
	} else {
		fail();
	}	

	enum class Suffix {
		Alkan, Alken, Alkyn, Alkohol, Syra
	} suffix;

	const std::unordered_map<std::string_view, const Suffix> suffixMap {
		{"an", Suffix::Alkan},
		{"en", Suffix::Alken},
		{"yn", Suffix::Alkyn},
		{"anol", Suffix::Alkohol},
		{"ansyra", Suffix::Syra}
	};

	if(suffixMap.find(input) == suffixMap.end())
		fail();

	suffix = suffixMap.at(input);

	if(prefix == Prefix::Met && (suffix == Suffix::Alken || suffix == Suffix::Alkyn))
		fail();

	unsigned int carbonCount = static_cast<unsigned int>(prefix);
	unsigned int hydrogenCount;
	unsigned int lineLength;

	switch(suffix) {
	case Suffix::Alkan:
		hydrogenCount = 2 * carbonCount + 2;
		lineLength = 2 * carbonCount + 3;
		break;
	case Suffix::Alken:
		hydrogenCount = 2 * carbonCount;
		lineLength = 2 * carbonCount + 1;
		break;
	case Suffix::Alkyn:
		hydrogenCount = 2 * carbonCount - 2;
		lineLength = 2 * carbonCount + 3;
		break;
	default:
		std::cout << "Alkoholer och syror är inte implementerade än\n\n";
		exit(0);
	}
	
	std::string formula = "C";
	if(carbonCount != 1)
		formula += std::to_string(carbonCount);
	formula += 'H';
	formula	+= std::to_string(hydrogenCount);

	std::cout << "┌";
	for(unsigned int i = 0; i < lineLength; i++)
		std::cout << "─";
	std::cout << "┐\n│" << std::setw(lineLength) << std::left << formattedName << "│\n├";
	for(unsigned int i = 0; i < lineLength; i++)
		std::cout << "─";
	std::cout << "┤\n│" << std::setw(lineLength) << formula << "│\n╞";
	for(unsigned int i = 0; i < lineLength; i++)
		std::cout << "═";
	std::cout << "╡\n";


	switch(suffix) {
	case Suffix::Alkan:
		std::cout << "│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << " │\n│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << " │\n│H─";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "C─";
		std::cout << "H│\n│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << " │\n│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << " │\n└";
		for(unsigned int i = 0; i < 2 * carbonCount + 3; i++)
			std::cout << "─";
		std::cout << "┘";
		break;
	
	case Suffix::Alken:
		std::cout << "│";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << " │\n│";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << " │\n│C═";
		for(unsigned int i = 0; i < carbonCount - 1; i++)
			std::cout << "C─";
		std::cout << "H│\n││   ";
		for(unsigned int i = 0; i < carbonCount - 2; i++)
			std::cout << "│ ";
		std::cout << " │\n│H   ";;
		for(unsigned int i = 0; i < carbonCount - 2; i++)
			std::cout << "H ";
		std::cout << " │\n└";
		for(unsigned int i = 0; i < 2 * carbonCount + 1; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	case Suffix::Alkyn:
		if(prefix != Prefix::Et) {
			std::cout << "│      ";
			for(unsigned int i = 0; i < carbonCount - 2; i++)
				std::cout << "H ";
			std::cout << " │\n│      ";
			for(unsigned int i = 0; i < carbonCount - 2; i++)
				std::cout << "│ ";
			std::cout << " │\n";
		}
		std::cout << "│H─C≡";
		for(unsigned int i = 0; i < carbonCount - 1; i++) {
			std::cout << "C─";
		}
		std::cout << "H│\n";
		if(prefix != Prefix::Et) {
			std::cout << "│      ";
			for(unsigned int i = 0; i < carbonCount - 2; i++)
				std::cout << "│ ";
			std::cout << " │\n│      ";
			for(unsigned int i = 0; i < carbonCount - 2; i++)
				std::cout << "H ";
			std::cout << " │\n";
		}
		std::cout << "└";
		for(unsigned int i = 0; i < 2 * carbonCount + 3; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	default:
		break;
	}

	std::cout << "\n\n";

	return 0;
}

void fail() {
	std::cout << "Ogiltigt ämne\n\n";
	exit(0);
}
