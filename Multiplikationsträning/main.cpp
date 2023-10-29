#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::mt19937 rng(time(0));

    std::vector<int> tables;
    std::cout << "Tabeller: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int buffer;
    while (stream >> buffer) {
        tables.push_back(buffer);
    }

    int min;
    int max;
    std::cout << "Lägsta talet: ";
    std::cin >> min;
    std::cout << "Högsta talet: ";
    std::cin >> max;

    int questionCount;
    std::cout << "Antal uppgifter: ";
    std::cin >> questionCount;

    int correct = 0;
    int incorrect = 0;

    while (questionCount--) {
        std::cout << '\n';
        int a = rng() % (max - min + 1) + min;
        int b = tables[rng() % tables.size()];
        if (rng() % 2) {
            std::cout << a << " * " << b << " = ";
        } else {
            std::cout << b << " * " << a << " = ";
        }

        int guess;
        if (!(std::cin >> guess)) {
            return 0;
        }
        if (guess == a * b) {
            std::cout << "Rätt!\n";
            correct++;
        } else {
            std::cout << "Fel! Rätt svar är " << a * b << ".\n";
            incorrect++;
        }
    }

    std::cout << "\nAntal rätt: " << correct << "\nAntal fel: " << incorrect;

    return 0;
}
