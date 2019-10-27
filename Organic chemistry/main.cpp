#include <string>
#include <iostream>
#include <unordered_map>
#include <string_view>

void fail() {
	std::cout << "Ogiltigt ämne\n\n";
	exit(0);
}

int main() {
	std::cout << "Skriv ett organiskt ämne: ";
	std::string input;
	std::cin >> input;
	std::cout << '\n';

	for(char& c : input) {
		if(c >= 'A' && c <= 'Z')
			c += 32;
	}

	enum class Prefix {
		Met = 1, Et, Prop, But, Pent, Hex, Hept, Okt, Non, Dek
	} prefix;
	
	if(input == "kalkon") {
		std::cout << "Gobbel gobbel\n\n                    .--.\n    {\\             / q {\\\n    { `\\           \\ (-(~`\n   { '.{`\\          \\ \\ )\n   {'-{ ' \\  .-\"\"'-. \\ \\\n   {._{'.' \\/       '.) \\\n   {_.{.   {`            |\n   {._{ ' {   ;'-=-.     |\n    {-.{.' {  ';-=-.`    /\n     {._.{.;    '-=-   .'\n      {_.-' `'.__  _,-'\n               |||`\n              .='==,\n\n";
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

	unsigned int carbonCount = (unsigned int)prefix;
	unsigned int hydrogenCount;

	switch(suffix) {
	case Suffix::Alkan:
		hydrogenCount = 2 * carbonCount + 2;
		break;
	case Suffix::Alken:
		hydrogenCount = 2 * carbonCount;
		break;
	case Suffix::Alkyn:
		hydrogenCount = 2 * carbonCount - 2;
		break;
	default:
		std::cout << "Alkoholer och syror är inte implementerade än\n\n";
		exit(0);
	}

	std::cout << 'C';
	if(carbonCount != 1)
		std::cout << std::to_string(carbonCount);
	std::cout << 'H' << std::to_string(hydrogenCount) << "\n\n";

	switch(suffix) {
	case Suffix::Alkan:
		std::cout << "  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << "\n  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "| ";
		std::cout << "\nH-";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "C-";
		std::cout << "H\n  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "| ";
		std::cout << "\n  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		break;
	
	case Suffix::Alken:
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << '\n';
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "| ";
		std::cout << "\nC="; 
		for(unsigned int i = 0; i < carbonCount - 1; i++)
			std::cout << "C-";
		std::cout << "H\n|   ";
		for(unsigned int i = 0; i < carbonCount - 2; i++)
			std::cout << "| ";
		std::cout << "\nH   ";;
		for(unsigned int i = 0; i < carbonCount - 2; i++)
			std::cout << "H ";
		break;

	case Suffix::Alkyn:
		if(prefix != Prefix::Et) {
			std::cout << "      ";
			for(unsigned int i = 0; i < carbonCount - 2; i++)
				std::cout << "H ";
			std::cout << "\n      ";
			for(unsigned int i = 0; i < carbonCount - 2; i++)
				std::cout << "| ";
			std::cout << '\n';
		}
		std::cout << "H-C≡";
		for(unsigned int i = 0; i < carbonCount - 1; i++) {
			std::cout << "C-";
		}
		std::cout << 'H';
		if(prefix != Prefix::Et) {
			std::cout << "\n      ";
			for(unsigned int i = 0; i < carbonCount - 2; i++)
				std::cout << "| ";
			std::cout << "\n      ";
			for(unsigned int i = 0; i < carbonCount - 2; i++)
				std::cout << "H ";
		}
		break;

	default:
		break;
	}

	std::cout << "\n\n";

	return 0;
}
