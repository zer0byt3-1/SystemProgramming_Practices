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
    if (!(num >= 0 && num <= 65535)) {
        printf("Entered value: %d not in range (0-65535)", num);
        return;
    }
    
    char symbols[] = "01";
    int num0 = num;
    int index = 0;
    char result[128];
	while (num0 > 0) {
		int remainder = num0 % 2;
		result[index++] = symbols[remainder];
		num0 /= 2;
	}
	printf("Result:");
	for (int i = index - 1; i >= 0; i--) {
		putchar(result[i]);
	}
	
	int controlbitsposs[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
}

int main()
{
	int inputval = 0;
	scanf("%i", &inputval);
	SearchBinary(inputval);
	return 0;
}