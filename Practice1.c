// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <stdio.h>
#include <stdint.h>
#include <locale>

void ConvertDecimalToSomeSystem(int iInputVal, int iSystem) {
	if ((iInputVal >= -1 && iInputVal <= 1)) {
		printf_s("Зачем?\n");
		return;
	}

	char symbols[] = "0123456789";
	char result[128]{};
	int iPos = 0;
	while (iInputVal > 0) {
		int iMod = iInputVal % iSystem;
		result[++iPos] = symbols[iMod];
		iInputVal /= iSystem;
	}
	result[iPos] = '\0';

	printf_s("%s", result);
	return;
}

int __cdecl main(int argc, char** argv) {
	setlocale(LC_ALL, "ru");
	int iInput{}, iSystem{};
	printf_s("Введите число: ");
	scanf_s("%i", &iInput);
	printf_s("В какую систему надо перевести число: ");
	scanf_s("%i", &iSystem);
	ConvertDecimalToSomeSystem(iInput, iSystem);
	return 0;
}