#include <iostream>
#include <random>
#include <string>

int main() {
	std::mt19937 rng(time(0));

	int min;
	int max;

	std::cout << "Lägsta talet: ";
	std::cin >> min;
	std::cout << "Högsta talet: ";
	std::cin >> max;

	while(true) {
		std::cout << '\n';
		int a = rng() % (max - min) + min;
		int b = rng() % (max - min) + min;
		std::cout << a << " * " << b << " = ";
		std::string guess;
		std::cin >> guess;
		try {
			if(std::stoi(guess) == a * b)
				std::cout << "Rätt!\n";
			else
				std::cout << "Fel! Rätt svar är " << a * b << ".\n";
		} catch(std::invalid_argument e) {
			return 0;
		}
	}

	return 0;
}
