#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

std::string output;
int indentation = 0;

void addLine(const std::string& s) {
	for(int i = 0; i < indentation; i++)
		output += '\t';
	output += s;
	output += '\n';
}

void emptyLine() {
	output += '\n';
}

int main() {
	std::ifstream fileInput("program.bf");
	std::string program((std::istreambuf_iterator<char>(fileInput)), std::istreambuf_iterator<char>());
	fileInput.close();

	addLine("#include <stdio.h>");
	emptyLine();
	addLine("int main() {");
	indentation++;
	addLine("unsigned short ptr = 0;");
	addLine("unsigned char memory[65536] = {0};");
	emptyLine();

	for(unsigned int progCounter = 0; progCounter < program.length() - 1; progCounter++) {
		switch(program[progCounter]) {
		case '.':
			addLine("putchar(memory[ptr]);");
			break;
		case ',':
			addLine("memory[ptr] = getchar();");
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
					addLine("memory[ptr]++;");
				else if(changeAmount == -1)
					addLine("memory[ptr]--;");
				else if(changeAmount > 0)
					addLine("memory[ptr] += " + std::to_string(changeAmount) + ';');
				else if(changeAmount < 0)
					addLine("memory[ptr] -= " + std::to_string(-changeAmount) + ';');
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
						addLine("ptr++;");
					else
						addLine("ptr += " + std::to_string(changeAmount) + ';');
				} else if(changeAmount < 0) {
					if(changeAmount == -1)
						addLine("ptr--;");
					else
						addLine("ptr -= " + std::to_string(-changeAmount) + ';');
				}
			}
			break;
		case '[':
			if((program[progCounter + 1] == '-' || program[progCounter + 1] == '+') && program[progCounter + 2] == ']') {
				progCounter += 2;
				addLine("memory[ptr] = 0;");
			} else {
				addLine("while(memory[ptr]) {");
				indentation++;
			}
			break;
		case ']':
			indentation--;
			addLine("}");
			break;
		default:
			break;
		}
	}

	emptyLine();
	addLine("return 0;");
	indentation--;
	addLine("}");

	std::ofstream outputFile("output.c");
	outputFile << output;
	outputFile.close();

	return 0;
}
