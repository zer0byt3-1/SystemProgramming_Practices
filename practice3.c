/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
void SearchBinary(int num)
{
    int num0 = num;
    int num1 = num;
    // Array to store digits
    int digits[64];
    int count = 0;

    // Decompose number into digits
    do {
        digits[count] = num0 % 10; // Get last digit
        num0 /= 10;                 // Remove last digit
        count++;
    } while (num0 > 0);

    // Print digits in reverse order
    printf("Digits: ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", digits[i]);
    }
    printf("\n");
    
	char symbols[] = "01";
	int result[64];
	int index = 0;

	while (num1 > 0)
	{
		int remainder = num1 % 2;
		result[index++] = symbols[remainder];
		num1 /= 2;
	}
	
	printf("Result:");
	for (int i = index - 1; i >= 0; i--)
	{
		putchar(result[i]);
	}
	
	putchar('\n');
	int summa = 0;
	for (int i = count - 1; i >= 0; i--) {
	    int val = digits[i];
	    summa += val;
	}
	printf("summa = %d, index = %d", summa, index);
	putchar('\n');
	if (summa % 2 == 0) {
	    result[index++] = '0';
	}
	else {
	    result[index++] = '1';
	}
	printf("summa = %d, index = %d", summa, index);
	putchar('\n');
	printf("Second result:");
	for (int i = 0; i < index; i++)
	{
		putchar(result[i]);
	}    
	
	putchar('\n');
	int decimal = 0;
    int base = 1; // 2^0
    for (int i = index - 1; i >= 0; i--) {
        if (result[i] == '1') {
            decimal += base;
        }
        base *= 2; // Move to the next base (2^1, 2^2, ...)
    }
    printf("New number: %d\n", decimal);
    // Array to store digits
    int digits0[64];
    int count0 = 0;
    int num2 = decimal;
    int num3 = decimal;
    // Decompose number into digits
    do {
        digits0[count0] = num2 % 10; // Get last digit
        num2 /= 10;                 // Remove last digit
        count0++;
    } while (num2 > 0);

    // Print digits in reverse order
    printf("New digits: ");
    for (int i = count0 - 1; i >= 0; i--) {
        printf("%d ", digits0[i]);
    }
    printf("\n");
	int result0[64];
	int index0 = 0;

	while (num3 > 0)
	{
		int remainder = num3 % 2;
		result0[index0++] = symbols[remainder];
		num3 /= 2;
	}
	
	printf("New Result:");
	for (int i = index0 - 1; i >= 0; i--)
	{
		putchar(result0[i]);
	}
	
	putchar('\n');
	int summa0 = 0;
	for (int i = count0 - 1; i >= 0; i--) {
	    int val0 = digits0[i];
	    summa0 += val0;
	}
	printf("summa0 = %d, index0 = %d", summa0, index0);
	putchar('\n');
	if (summa0 % 2 == 0) {
	    result0[index0++] = '0';
	}
	else {
	    result0[index0++] = '1';
	}
	printf("summa0 = %d, index0 = %d", summa0, index0);
	putchar('\n');
	printf("New second result:");
	for (int i = 0; i < index0; i++)
	{
		putchar(result0[i]);
	}
	putchar('\n');
	int decimal0 = 0;
    int base0 = 1; // 2^0
    for (int i = index0 - 1; i >= 0; i--) {
        if (result0[i] == '1') {
            decimal0 += base0;
        }
        base0 *= 2; // Move to the next base (2^1, 2^2, ...)
    }
    printf("New second number: %d\n", decimal0);
}

int main()
{
	int inputval = 0;
	scanf("%i", &inputval);
	if (inputval < 0) {
		printf("Error: Inputed value below zero.");
		return 1;
	}

	SearchBinary(inputval);
	return 0;
}