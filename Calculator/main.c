#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool eval(char*, float*);
bool handleNumber(char*, float*);
bool handleAddition(char*, float*);

int main() {
	char input[256];
	scanf("%s", &input);

	float num;
	if(eval(&input, &num))
		printf("Result: %f\n", num);
	else
		printf("Error!\n");

	return 0;
}

bool eval(char* str, float* num) {
	return handleNumber(str, num)
		|| handleAddition(str, num);
}

bool handleNumber(char* str, float* num) {
	return sscanf(str, "%f", num);
}

bool handleAddition(char* str, float* num) {
	char strLeft[256], strRight[256];
	if(!sscanf(str, "%s+%s", &strLeft, &strRight))
		return false;

	float numLeft, numRight;
	if(!handleNumber(&strLeft, &numLeft))
		return false;
	if(!handleNumber(&strRight, &numRight))
		return false;

	*num = numLeft + numRight;

	return true;
}
