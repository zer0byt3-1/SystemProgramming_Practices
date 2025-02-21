/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void printBinary(unsigned int num, int bits) {
	for (int i = bits - 1; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
}

int canStoreNumber(int num, int bytes, int signedFlag) {
	int maxSize = signedFlag ? (1 << (bytes * 8 - 1)) - 1 : (1 << (bytes * 8)) - 1;
	int minSize = signedFlag ? -(1 << (bytes * 8 - 1)) : 0;

	if (signedFlag) {
		return (num <= maxSize && num >= minSize);
	}
	else {
		return (num >= minSize && num <= maxSize);
	}
}

int main()
{
	int num;
	int bytes;
	int signedFlag;

	printf("Enter an integer number: ");
	scanf("%d", &num);

	printf("Enter the number of bytes to store the number (1, 2, 4): ");
	scanf("%d", &bytes);

	printf("Enter the number type (1 for signed, 0 for unsigned): ");
	scanf("%d", &signedFlag);
	if (canStoreNumber(num, bytes, signedFlag)) {
		int bits = bytes * 8;
		if (signedFlag) {
			printf("Binary code of the number %d (signed): ", num);
			printBinary((unsigned int)(num & ((1 << bits) - 1)), bits);
		}
		else {
			printf("Binary code of number %d (unsigned): ", num);
			printBinary((unsigned int)num, bits);
		}
	}
	else {
		printf("The number %d cannot be put into %d bytes in %s format.\n",
			num, bytes, (signedFlag ? "signed" : "unsigned"));
	}
	return 0;
}