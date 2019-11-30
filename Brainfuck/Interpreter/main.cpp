#include <string>
#include <fstream>
#include <streambuf>
#include <stdio.h>

constexpr int memSize = 32768;

int main() {
	std::ifstream fileInput("program.bf");
	std::string program((std::istreambuf_iterator<char>(fileInput)), std::istreambuf_iterator<char>());
	fileInput.close();

	unsigned char memory[memSize] = {0};
	unsigned int progCounter = 0;
	int memPos = 0;

	while(progCounter < program.length() - 1) {
		switch(program[progCounter]) {
		case '+':
			memory[memPos]++;
			progCounter++;
			break;
		case '-':
			memory[memPos]--;
			progCounter++;
			break;
		case '>':
			++memPos %= memSize;
			progCounter++;
			break;
		case '<':
			if(!memPos--)
				memPos = memSize - 1;
			progCounter++;
			break;
		case '.':
			putchar(memory[memPos]);
			progCounter++;
			break;
		case ',':
			memory[memPos] = getchar();
			progCounter++;
			break;
		case '[':
			if(memory[memPos] == 0) {
				int bracketCount = 0;
				do {
					if(program[progCounter] == '[')
						bracketCount++;
					else if(program[progCounter] == ']')
						bracketCount--;
					progCounter++;
				} while(bracketCount);
			} else {
				progCounter++;
			}
			break;
		case ']':
			{
				int bracketCount = 0;
				do {
					if(program[progCounter] == '[')
						bracketCount++;
					else if(program[progCounter] == ']')
						bracketCount--;
					progCounter--;
				} while(bracketCount);
			}
			progCounter++;
			break;
		}
	}

	return 0;
}
