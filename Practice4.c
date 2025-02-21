#include <stdio.h>
#include <stdint.h>
#include <locale>
#define DBG 0
#define _CRT_SECURE_NO_WARNINGS
auto ConvertDecimalToBinary(int iInputVal) -> char* {
	if ((iInputVal >= -1 && iInputVal <= 1)) {
		return NULL;
	}

	char symbols[] = "01";
	char result[128] = { 0 };
	int iPos = 0;
	while (iInputVal > 0) {
		int iMod = iInputVal % 2;
		result[iPos] = symbols[iMod];
		iInputVal /= 2;
		++iPos;
	}
	result[iPos] = '\0';
	return result;
}

int __cdecl main(int argc, char** argv) {
	setlocale(LC_ALL, "ru");
	int iInput{}, iSystem{};
	printf_s("������� �����: ");
	scanf_s("%i", &iInput);
	auto r = ConvertDecimalToBinary(iInput);
	int bitarraysize = strlen(r);
	if (bitarraysize > 0) {
		int* bitarray = (int*)malloc(bitarraysize * sizeof(int));
		if (bitarray == NULL) {
			return 1;
		}

		for (int i = 0; i < bitarraysize; ++i)
		{
			bitarray[i] = r[i] == '1' ? 1 : 0;
		}

		printf("�������� ���:\n");

		for (int i = 0; i < bitarraysize; i++)
			printf_s("| %d ", bitarray[i]);

		printf("|");

		printf("��� ��������:\n");

		///����� ���������:
		///������� ������������ ���� = 2 ^ k, ��� k = 0..������ ��������� ����
		///TODO

		free(bitarray);
	}
#if defined _DEBUG && DBG == 1
	printf_s("����������� ��������� ���� �����: %i", bitarraysize);
#endif
	return 0;
}