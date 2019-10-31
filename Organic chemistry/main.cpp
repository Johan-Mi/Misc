#include <string>
#include <iostream>
#include <unordered_map>
#include <string_view>
#include <iomanip>

[[noreturn]]void fail() {
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
	input[0] -= 32;

	std::string_view inputView(input);

	enum class Prefix {
		Met = 1, Et, Prop, But, Pent, Hex, Hept, Okt, Non, Dek
	} prefix;

	if(inputView.rfind("Met", 0) == 0) {
		prefix = Prefix::Met;
		inputView.remove_prefix(3);
	} else if(inputView.rfind("Et", 0) == 0) {
		prefix = Prefix::Et;
		inputView.remove_prefix(2);
	} else if(inputView.rfind("Prop", 0) == 0) {
		prefix = Prefix::Prop;
		inputView.remove_prefix(4);
	} else if(inputView.rfind("But", 0) == 0) {
		prefix = Prefix::But;
		inputView.remove_prefix(3);
	} else if(inputView.rfind("Pent", 0) == 0) {
		prefix = Prefix::Pent;
		inputView.remove_prefix(4);
	} else if(inputView.rfind("Hex", 0) == 0) {
		prefix = Prefix::Hex;
		inputView.remove_prefix(3);
	} else if(inputView.rfind("Hept", 0) == 0) {
		prefix = Prefix::Hept;
		inputView.remove_prefix(4);
	} else if(inputView.rfind("Okt", 0) == 0) {
		prefix = Prefix::Okt;
		inputView.remove_prefix(3);
	} else if(inputView.rfind("Non", 0) == 0) {
		prefix = Prefix::Non;
		inputView.remove_prefix(3);
	} else if(inputView.rfind("Dek", 0) == 0) {
		prefix = Prefix::Dek;
		inputView.remove_prefix(3);
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

	if(suffixMap.find(inputView) == suffixMap.end())
		fail();

	suffix = suffixMap.at(inputView);

	if(prefix == Prefix::Met && (suffix == Suffix::Alken || suffix == Suffix::Alkyn))
		fail();

	unsigned int carbonCount = static_cast<unsigned int>(prefix);
	unsigned int hydrogenCount;
	unsigned int oxygenCount = 0;
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
	case Suffix::Alkohol:
		hydrogenCount = 2 * carbonCount + 2;
		oxygenCount = 1;
		lineLength = 2 * carbonCount + 5;
		break;
	case Suffix::Syra:
		hydrogenCount = 2 * carbonCount;
		oxygenCount = 2;
		lineLength = 2 * carbonCount + 3;
		break;;
	default:
		exit(0);
	}
	
	std::string formula{};
	if(suffix == Suffix::Syra) {
		if(prefix != Prefix::Met)	 {
			formula = "CH3";
			if(prefix != Prefix::Et) {
				if(prefix != Prefix::Prop)
					formula += '(';
				formula += "CH2";
				if(prefix != Prefix::Prop) {
					formula += ')';
					formula += std::to_string(static_cast<int>(prefix) - 2);
				}
			}
		}
		formula += "COOH";
	} else {
		formula = "C";
		if(carbonCount != 1)
			formula += std::to_string(carbonCount);
		formula += 'H';
		formula	+= std::to_string(hydrogenCount - (oxygenCount == 1));
		if(oxygenCount) {
			formula += 'O';
			if(oxygenCount == 1)
				formula += 'H';
			else
				formula += std::to_string(oxygenCount);
		}
	}

	if(input.length() > lineLength)
		lineLength = input.length();
	if(formula.length() > lineLength)
		lineLength = formula.length();

	std::cout << "┌";
	for(unsigned int i = 0; i < lineLength; i++)
		std::cout << "─";
	std::cout << "┐\n│" << std::setw(lineLength) << std::left << input << "│\n├";
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
		for(unsigned int i = 0; i < lineLength; i++)
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
		for(unsigned int i = 0; i < lineLength; i++)
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
		for(unsigned int i = 0; i < lineLength; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	case Suffix::Alkohol:
		std::cout << "│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << "   │\n│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << "   │\n│H─";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "C─";
		std::cout << "O-H│\n│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << "   │\n│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << "   │\n└";
		for(unsigned int i = 0; i < lineLength; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	case Suffix::Syra:
		std::cout << "│  ";
		for(unsigned int i = 0; i < carbonCount - 1; i++)
			std::cout << "H ";
		std::cout << "O  ";
		for(unsigned int i = 0; i < lineLength - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << "│\n│  ";
		for(unsigned int i = 0; i < carbonCount - 1; i++)
			std::cout << "│ ";
		std::cout << "‖  ";
		for(unsigned int i = 0; i < lineLength - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << "│\n│H─";
		for(unsigned int i = 0; i < carbonCount - 1; i++)
			std::cout << "C─";
		std::cout << "C  ";
		for(unsigned int i = 0; i < lineLength - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << "│\n│  ";
		for(unsigned int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		for(unsigned int i = 0; i < lineLength - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << " │\n│  ";
		for(unsigned int i = 0; i < carbonCount - 1; i++)
			std::cout << "H ";
		std::cout << "O─H";
		for(unsigned int i = 0; i < lineLength - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << "│\n└";
		for(unsigned int i = 0; i < lineLength; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	default:
		exit(0);
	}

	std::cout << "\n\n";

	return 0;
}
