/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <locale.h>

void ConvertDecimalToSomeSystem(int iInputVal, int iSystem) {
	if (iInputVal <= 0) {
		printf("Inputed value less or equal zero\n");
		return;
	}
	
	if (iSystem == 10){
	    printf("Result: %i", iInputVal);
	    return;
	}
	
	if (!(iSystem >= 2 && iSystem <= 36)) {
		printf("Inputed system not in range, valid range: 2-36\n");
		return;
	}

	char symbols[] = "0123456789ABCDEF";
	char result[128];
	int iPos = 0;
	while (iInputVal > 0) {
		int iMod = iInputVal % iSystem;
		result[iPos++] = symbols[iMod];
		iInputVal /= iSystem;
	}
	
	printf("Result: ");
	for (int i = iPos - 1; i >= 0; i--){
	    putchar(result[i]);
	}
	return;
}

int main() {
	int iInput = 0;
	int iSystem = 0;
	printf("Enter value: ");
	scanf("%i", &iInput);
	printf("Into which system should the number be converted: ");
	scanf("%i", &iSystem);
	ConvertDecimalToSomeSystem(iInput, iSystem);
	return 0;
}