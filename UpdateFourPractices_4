#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функция определяет, является ли число степенью двойки.
int isPowerOfTwo(int x) {
    return (x & (x - 1)) == 0;
}

// Функция для вывода двоичного представления числа.
void printBinary(unsigned int num) {
    int bits = (num == 0) ? 1 : (int)floor(log2(num)) + 1;
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    unsigned int inputNumber;
    printf("Введите целое число: ");
    if (scanf("%u", &inputNumber) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    
    // Вывод исходного числа и его двоичного представления
    printf("\nИсходное число: %u\n", inputNumber);
    printf("Двоичный код исходного числа: ");
    printBinary(inputNumber);
    printf("\n");
    
    // Вычисляем количество информационных бит (m)
    int m = (inputNumber == 0) ? 1 : (int)floor(log2(inputNumber)) + 1;
    
    // Определяем минимальное количество контрольных бит (r): выполняется условие (m + r + 1) <= 2^r.
    int r = 0;
    while ((m + r + 1) > (1 << r)) {
        r++;
    }
    
    printf("\nКоличество информационных бит (m): %d\n", m);
    printf("Необходимое количество контрольных бит (r): %d\n", r);
    
    // Общее количество бит в коде Хэмминга
    int totalBits = m + r;
    // Массив для кода. Нумерация позиций начинаем с 1 (от 1 до totalBits)
    int *hammingCode = (int *)calloc(totalBits + 1, sizeof(int));
    if (hammingCode == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    // Заполнение информационными битами: в позиции, не являющиеся степенью двойки, записываем биты исходного числа.
    int dataIndex = m - 1;  // Начинаем с самого значимого бита
    for (int pos = 1; pos <= totalBits; pos++) {
        if (isPowerOfTwo(pos)) {
            printf("Позиция %d отведена под контрольный бит.\n", pos);
        } else {
            int bit = (inputNumber >> dataIndex) & 1;
            hammingCode[pos] = bit;
            printf("Запись информационного бита %d (значение %d) в позицию %d.\n", m - dataIndex, bit, pos);
            dataIndex--;
        }
    }
    
    // Вычисляем и заполняем контрольные биты
    for (int i = 0; i < r; i++) {
        int controlPos = 1 << i; // Позиция контрольного бита = 2^i
        int parity = 0;
        printf("\nВычисление контрольного бита для позиции %d:\n", controlPos);
        // Проходим по битам, которые контролируются текущим контрольным битом.
        // Шаг равен 2*controlPos, внутри каждого отрезка обрабатываем controlPos бит.
        for (int j = controlPos; j <= totalBits; j += 2 * controlPos) {
            for (int k = j; k < j + controlPos && k <= totalBits; k++) {
                parity ^= hammingCode[k];
                printf("  Проверка позиции %d, бит = %d, промежуточный XOR = %d\n", k, hammingCode[k], parity);
            }
        }
        hammingCode[controlPos] = parity;
        printf("Установлен контрольный бит %d на позиции %d\n", parity, controlPos);
    }
    
    // Вывод итогового кода Хэмминга
    printf("\nИтоговый код Хэмминга: ");
    for (int i = 1; i <= totalBits; i++) {
        printf("%d", hammingCode[i]);
    }
    printf("\n");
    
    free(hammingCode);
    return 0;
}
