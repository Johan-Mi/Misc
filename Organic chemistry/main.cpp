#include <string>
#include <iostream>
#include <unordered_map>
#include <string_view>
#include <iomanip>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

[[noreturn]]void fail() {
	std::cout << "Ogiltigt ämne\n\n";
	exit(0);
}

void writeWchar(wchar_t c) {
	mbstate_t state;
	memset(&state, 0, sizeof(state));
	char mbbuf[MB_CUR_MAX];
	size_t nbytes = wcrtomb(mbbuf, c, &state);
	if(!(nbytes == (size_t)-1 || nbytes > (size_t)MB_CUR_MAX))
		[[maybe_unused]] auto discard = write(STDIN_FILENO, mbbuf, nbytes);
}

int main() {
	setlocale(LC_ALL, "");

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
		Alkan, Alken, Alkyn, Alkohol, Syra, Aldehyd
	} suffix;

	const std::unordered_map<std::string_view, const Suffix> suffixMap {
		{"an", Suffix::Alkan},
		{"en", Suffix::Alken},
		{"yn", Suffix::Alkyn},
		{"anol", Suffix::Alkohol},
		{"ansyra", Suffix::Syra},
		{"anal", Suffix::Aldehyd}
	};

	if(suffixMap.find(inputView) == suffixMap.end())
		fail();

	suffix = suffixMap.at(inputView);

	if(prefix == Prefix::Met && (suffix == Suffix::Alken || suffix == Suffix::Alkyn))
		fail();

	int carbonCount = static_cast<int>(prefix);
	int hydrogenCount;
	int oxygenCount = 0;
	int picWidth;
	int picHeight = 5;

	switch(suffix) {
	case Suffix::Alkan:
		hydrogenCount = 2 * carbonCount + 2;
		picWidth = 2 * carbonCount + 3;
		break;
	case Suffix::Alken:
		hydrogenCount = 2 * carbonCount;
		picWidth = 2 * carbonCount + 1;
		break;
	case Suffix::Alkyn:
		hydrogenCount = 2 * carbonCount - 2;
		picWidth = 2 * carbonCount + 3;
		if(prefix == Prefix::Et)
			picHeight = 1;
		break;
	case Suffix::Alkohol:
		hydrogenCount = 2 * carbonCount + 2;
		oxygenCount = 1;
		picWidth = 2 * carbonCount + 5;
		break;
	case Suffix::Syra:
		hydrogenCount = 2 * carbonCount;
		oxygenCount = 2;
		picWidth = 2 * carbonCount + 3;
		break;
	case Suffix::Aldehyd:
		hydrogenCount = 2 * carbonCount;
		oxygenCount = 1;
		picWidth = 2 * carbonCount + 1;
		break;
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
		formula	+= std::to_string(hydrogenCount - (suffix == Suffix::Alkohol));
		if(oxygenCount) {
			formula += 'O';
			if(suffix == Suffix::Alkohol)
				formula += 'H';
			else {
				if(oxygenCount != 1)
					formula += std::to_string(oxygenCount);
			}
		}
	}

	if(input.length() > picWidth)
		picWidth = input.length();
	if(formula.length() > picWidth)
		picWidth = formula.length();

	auto pic = new wchar_t*[picHeight];
	for(int i = 0; i < picHeight; i++) {
		pic[i] = new wchar_t[picWidth];	
		for(int j = 0; j < picWidth; j++)
			pic[i][j] = L' ';
	}

	switch(suffix) {
	case Suffix::Alkan:
		pic[2][0] = L'H';
		pic[2][1] = L'─';
		pic[2][picWidth - 1] = L'H';
		for(int i = 0; i < 2 * carbonCount; i += 2) {
			pic[0][i + 2] = L'H';
			pic[1][i + 2] = L'│';
			pic[2][i + 2] = L'C';
			pic[3][i + 2] = L'│';
			pic[4][i + 2] = L'H';
			pic[2][i + 3] = L'─';
		}
		break;

	case Suffix::Alken:
		pic[0][0] = L'H';
		pic[1][0] = L'│';
		pic[2][0] = L'C';
		pic[3][0] = L'│';
		pic[4][0] = L'H';
		pic[2][1] = L'═';
		pic[0][2] = L'H';
		pic[1][2] = L'│';
		pic[2][2] = L'C';
		pic[2][picWidth - 2] = L'─';
		pic[2][picWidth - 1] = L'H';
		for(int i = 0; i < 2 * carbonCount - 4; i += 2) {
			pic[0][i + 4] = L'H';
			pic[1][i + 4] = L'│';
			pic[2][i + 4] = L'C';
			pic[3][i + 4] = L'│';
			pic[4][i + 4] = L'H';
			pic[2][i + 3] = L'─';
		}
		break;
	
	default:
		break;
	}

	std::cout << "┌";
	for(int i = 0; i < picWidth; i++)
		std::cout << "─";
	std::cout << "┐\n│" << std::setw(picWidth) << std::left << input << "│\n├";
	for(int i = 0; i < picWidth; i++)
		std::cout << "─";
	std::cout << "┤\n│" << std::setw(picWidth) << formula << "│\n╞";
	for(int i = 0; i < picWidth; i++)
		std::cout << "═";
	std::cout << "╡\n";

	for(int i = 0; i < picHeight; i++) {
		std::cout << "│" << std::flush;
		for(int j = 0; j < picWidth; j++)
			writeWchar(pic[i][j]);
		std::cout << "│\n";
	}

	std::cout << "└";
	for(int i = 0; i < picWidth; i++)
		std::cout << "─";
	std::cout << "┘\n\n";

/*
	switch(suffix) {
	case Suffix::Alkan:
		std::cout << "│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << " │\n│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << " │\n│H─";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "C─";
		std::cout << "H│\n│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << " │\n│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << " │\n└";
		for(int i = 0; i < picWidth; i++)
			std::cout << "─";
		std::cout << "┘";
		break;
	
	case Suffix::Alken:
		std::cout << "│";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << " │\n│";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << " │\n│C═";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "C─";
		std::cout << "H│\n││   ";
		for(int i = 0; i < carbonCount - 2; i++)
			std::cout << "│ ";
		std::cout << " │\n│H   ";;
		for(int i = 0; i < carbonCount - 2; i++)
			std::cout << "H ";
		std::cout << " │\n└";
		for(int i = 0; i < picWidth; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	case Suffix::Alkyn:
		if(prefix != Prefix::Et) {
			std::cout << "│      ";
			for(int i = 0; i < carbonCount - 2; i++)
				std::cout << "H ";
			std::cout << " │\n│      ";
			for(int i = 0; i < carbonCount - 2; i++)
				std::cout << "│ ";
			std::cout << " │\n";
		}
		std::cout << "│H─C≡";
		for(int i = 0; i < carbonCount - 1; i++) {
			std::cout << "C─";
		}
		std::cout << "H│\n";
		if(prefix != Prefix::Et) {
			std::cout << "│      ";
			for(int i = 0; i < carbonCount - 2; i++)
				std::cout << "│ ";
			std::cout << " │\n│      ";
			for(int i = 0; i < carbonCount - 2; i++)
				std::cout << "H ";
			std::cout << " │\n";
		}
		std::cout << "└";
		for(int i = 0; i < picWidth; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	case Suffix::Alkohol:
		std::cout << "│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << "   │\n│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << "   │\n│H─";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "C─";
		std::cout << "O─H│\n│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		std::cout << "   │\n│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "H ";
		std::cout << "   │\n└";
		for(int i = 0; i < picWidth; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	case Suffix::Syra:
		std::cout << "│  ";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "H ";
		std::cout << "O  ";
		for(int i = 0; i < picWidth - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << "│\n│  ";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "│ ";
		std::cout << "‖  ";
		for(int i = 0; i < picWidth - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << "│\n│H─";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "C─";
		std::cout << "C  ";
		for(int i = 0; i < picWidth - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << "│\n│  ";
		for(int i = 0; i < carbonCount; i++)
			std::cout << "│ ";
		for(int i = 0; i < picWidth - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << " │\n│  ";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "H ";
		std::cout << "O─H";
		for(int i = 0; i < picWidth - (2 * carbonCount + 3); i++)
			std::cout << ' ';
		std::cout << "│\n└";
		for(int i = 0; i < picWidth; i++)
			std::cout << "─";
		std::cout << "┘";
		break;

	case Suffix::Aldehyd:
		std::cout << "│  ";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "H ";
		std::cout << 'O';
		for(int i = 0; i < picWidth - (2 * carbonCount + 1); i++)
			std::cout << ' ';
		std::cout << "│\n│  ";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "│ ";
		std::cout << "‖";
		for(int i = 0; i < picWidth - (2 * carbonCount + 1); i++)
			std::cout << ' ';
		std::cout << "│\n│H─";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "C─";
		std::cout << 'C';
		for(int i = 0; i < picWidth - (2 * carbonCount + 1); i++)
			std::cout << ' ';
		std::cout << "│\n│  ";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "│ ";
		std::cout << "│";
		for(int i = 0; i < picWidth - (2 * carbonCount + 1); i++)
			std::cout << ' ';
		std::cout << "│\n│  ";
		for(int i = 0; i < carbonCount - 1; i++)
			std::cout << "H ";
		std::cout << 'H';
		for(int i = 0; i < picWidth - (2 * carbonCount + 1); i++)
			std::cout << ' ';
		std::cout << "│\n└";
		for(int i = 0; i < picWidth; i++)
			std::cout << "─";
		std::cout << "┘";
		break;
	

	default:
		exit(0);
	}
*/

	std::cout << "\n\n";

	for(int i = 0; i < picHeight; i++)
		delete[] pic[i];
	delete pic;	

	return 0;
}
