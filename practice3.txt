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
    for (int i = 0; i < index; i++) {
        if (result[i] == '1') {
            decimal += base;
        }
        base *= 2; // Move to the next base (2^1, 2^2, ...)
    }
    printf("New value: %d\n", decimal);
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