#include <stdlib.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>

enum TokenType {Output, Input, Inc, Move, LoopBegin, LoopEnd};

struct Token {
	TokenType type;
	int value;
};

std::vector<Token> output;

int main() {
	std::ifstream fileInput("program.bf");
	std::string program((std::istreambuf_iterator<char>(fileInput)), std::istreambuf_iterator<char>());
	fileInput.close();

	for(unsigned progCounter = 0; progCounter < program.length(); progCounter++) {
		switch(program[progCounter]) {
		case '.':
			output.push_back({Output});
			break;
		case ',':
			output.push_back({Input});
			break;
		case '+':
		case '-':
			{
				int changeAmount = 0;
				while(program[progCounter] != '<' && program[progCounter] != '>' && program[progCounter] != ',' && program[progCounter] != '.' && program[progCounter] != '[' && program[progCounter] != ']' && progCounter < program.length() - 1) {
					if(program[progCounter] == '+')
						changeAmount++;
					else if(program[progCounter] == '-')
						changeAmount--;	
					progCounter++;
				}
				progCounter--;
				if(changeAmount)
					output.push_back({Inc, changeAmount});
			}
			break;
		case '>':
		case '<':
			{
				int changeAmount = 0;
				while(program[progCounter] != '+' && program[progCounter] != '-' && program[progCounter] != ',' && program[progCounter] != '.' && program[progCounter] != '[' && program[progCounter] != ']') {
					if(program[progCounter] == '>')
						changeAmount++;
					else if(program[progCounter] == '<')
						changeAmount--;	
					progCounter++;
				}
				progCounter--;
				if(changeAmount)
					output.push_back({Move, changeAmount});
			}
			break;
		case '[':
			output.push_back({LoopBegin});
			break;
		case ']':
			output.push_back({LoopEnd});
			break;
		default:
			break;
		}
	}

	std::ofstream outputFile("output.c");
	unsigned indentation = 1;

	outputFile << "#include <stdlib.h>\n#include <stdio.h>\n\nint main(void) {\n\tunsigned short ptr = 0;\n\tunsigned char memory[65536] = {0};\n\n";
	for(unsigned i = 0; i < output.size(); i++) {
		if(output[i].type == LoopEnd)
			indentation--;
		for(unsigned j = 0; j < indentation; j++)
			outputFile << '\t';
		switch(output[i].type) {
			case Output:
				outputFile << "putchar(memory[ptr]);";
				break;
			case Input:
				outputFile << "memory[ptr] = getchar();\n";
				break;
			case Inc:
				if(output[i].value == 1)
					outputFile << "memory[ptr]++;\n";
				else if(output[i].value == -1)
					outputFile << "memory[ptr]--;\n";
				else if(output[i].value > 0)
					outputFile << "memory[ptr] += " << output[i].value << ";\n";
				else if(output[i].value < 0)
					outputFile << "memory[ptr] -= " << -output[i].value << ";\n";
				break;
			case Move:
				if(output[i].value == 1)
					outputFile << "ptr++;\n";
				else if(output[i].value == -1)
					outputFile << "ptr--;\n";
				else if(output[i].value > 0)
					outputFile << "ptr += " << output[i].value << ";\n";
				else if(output[i].value < 0)
					outputFile << "ptr -= " << -output[i].value << ";\n";
				break;
			case LoopBegin:
				outputFile << "while(memory[ptr]) {\n";
				indentation++;
				break;
			case LoopEnd:
				outputFile << "}\n";
				break;
			default:
				break;
		}
	}
	outputFile << "\n\treturn EXIT_SUCCESS;\n}";

	outputFile.close();

	return EXIT_SUCCESS;
}
