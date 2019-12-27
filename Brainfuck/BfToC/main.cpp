#include <stdlib.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>

std::vector<std::string> output;

int main() {
	std::ifstream fileInput("program.bf");
	std::string program((std::istreambuf_iterator<char>(fileInput)), std::istreambuf_iterator<char>());
	fileInput.close();

	output.push_back("#include <stdlib.h>\n#include <stdio.h>");
	output.push_back("int main(void) {");
	output.push_back("unsigned short ptr = 0;");
	output.push_back("unsigned char memory[65536] = {0};");

	for(unsigned int progCounter = 0; progCounter < program.length() - 1; progCounter++) {
		switch(program[progCounter]) {
		case '.':
			output.push_back("putchar(memory[ptr]);");
			break;
		case ',':
			output.push_back("memory[ptr] = getchar();");
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
				if(changeAmount == 1)
					output.push_back("memory[ptr]++;");
				else if(changeAmount == -1)
					output.push_back("memory[ptr]--;");
				else if(changeAmount > 0)
					output.push_back("memory[ptr] += " + std::to_string(changeAmount) + ';');
				else if(changeAmount < 0)
					output.push_back("memory[ptr] -= " + std::to_string(-changeAmount) + ';');
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
				if(changeAmount > 0) {
					if(changeAmount == 1)
						output.push_back("ptr++;");
					else
						output.push_back("ptr += " + std::to_string(changeAmount) + ';');
				} else if(changeAmount < 0) {
					if(changeAmount == -1)
						output.push_back("ptr--;");
					else
						output.push_back("ptr -= " + std::to_string(-changeAmount) + ';');
				}
			}
			break;
		case '[':
			if((program[progCounter + 1] == '-' || program[progCounter + 1] == '+') && program[progCounter + 2] == ']') {
				progCounter += 2;
				output.push_back("memory[ptr] = 0;");
			} else {
				output.push_back("while(memory[ptr]) {");
			}
			break;
		case ']':
			output.push_back("}");
			break;
		default:
			break;
		}
	}



	if(output[4][0] == 'm') {
		if(output[4] == "memory[ptr]++;")
			output[4] == "memory[0] = 1;";
		else if(output[4] == "memory[ptr]--;")
			output[4] = "memory[0] = 65535;";
		else if(output[4][12] == '+')
			output[4] = "memory[0] = " + output[4].substr(15);
	}



	output.push_back("return EXIT_SUCCESS;");
	output.push_back("}");

	std::ofstream outputFile("output.c");
	int indentation = 0;
	for(const auto& line : output) {
		if(line[0] == '}')
			indentation--;
		if(line[0] == 'r')
			outputFile << '\n';
		for(int i = 0; i < indentation; i++)
			outputFile << '\t';
		outputFile << line << '\n';
		if(line[0] == 'w' || line[0] == 'i')
			indentation++;
		if(line[0] == '#' || (line[0] == 'u' && line[9] == 'c'))
			outputFile << '\n';
	}
	outputFile.close();

	return EXIT_SUCCESS;
}
