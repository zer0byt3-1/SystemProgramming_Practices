// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int __cdecl main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	int num;
	int bytes;
	char signOption;

	printf("Введите целое число: ");
	scanf_s("%d", &num);

	printf("Введите количество байт для хранения числа (1, 2, 4): ");
	scanf_s("%d", &bytes);

	printf("Введите тип числа (s для знакового, u для беззнакового): ");
	scanf_s("%c", &signOption);

	int signedFlag = (signOption == 's') ? 1 : 0;

	if (canStoreNumber(num, bytes, signedFlag)) {
		int bits = bytes * 8;
		if (signedFlag) {
			printf("Двоичный код числа %d (знаковое): ", num);
			printBinary((unsigned int)(num & ((1 << bits) - 1)), bits);
		}
		else {
			printf("Двоичный код числа %d (беззнаковое): ", num);
			printBinary((unsigned int)num, bits);
		}
	}
	else {
		printf("Число %d не может быть помещено в %d байт в %s формате.\n",
			num, bytes, (signedFlag ? "знаковом" : "беззнаковом"));
	}
	return 0;
}