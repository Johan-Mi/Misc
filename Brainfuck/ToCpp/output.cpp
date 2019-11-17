#include <iostream>

int main() {
	unsigned short ptr = 0;
	unsigned char memory[65536] = {0};

	memory[ptr] += 8;
	while(memory[ptr]) {
		ptr++;
		memory[ptr]++;
		ptr++;
		memory[ptr] += 4;
		ptr -= 2;
		memory[ptr]--;
	}

	ptr++;
	memory[ptr] += 2;
	ptr += 2;
	memory[ptr]++;
	ptr--;
	while(memory[ptr]) {
		memory[ptr]--;
		while(memory[ptr]) {
			ptr += 2;
			memory[ptr]++;
			ptr -= 2;
			memory[ptr]--;
		}

		memory[ptr]++;
		ptr += 2;
	}

	ptr++;
	memory[ptr]++;
	while(memory[ptr]) {
		memory[ptr]--;
		ptr -= 3;
		while(memory[ptr]) {
			memory[ptr]--;
			ptr++;
			while(memory[ptr]) {
				memory[ptr]++;
				memory[ptr] = 0;
				memory[ptr]++;
				ptr++;
				memory[ptr] += 2;
				ptr += 3;
				memory[ptr]--;
				ptr -= 2;
			}

			ptr--;
			while(memory[ptr])
				ptr--;

			ptr += 2;
			memory[ptr] += 6;
			while(memory[ptr]) {
				ptr -= 2;
				memory[ptr] += 5;
				ptr += 2;
				memory[ptr]--;
			}

			memory[ptr]++;
			ptr -= 2;
			memory[ptr] += 2;
			std::cout << memory[ptr];
			memory[ptr] = 0;
			ptr -= 2;
		}

		ptr++;
		std::cout << memory[ptr];
		ptr++;
		memory[ptr]++;
		while(memory[ptr]) {
			ptr += 2;
		}

		ptr++;
		memory[ptr]++;
	}


	return 0;
}
