//
// Created by Алексей Куриганов on 16.04.2025.
//

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Стек переполнен!\n");
        return;
    }
    stack[++top] = value;
    printf("Элемент %d добавлен в стек.\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("Стек пуст, удаление невозможно!\n");
        return;
    }
    printf("Элемент %d удалён из стека.\n", stack[top--]);
}

void display() {
    if (isEmpty()) {
        printf("Стек пуст.\n");
        return;
    }
    printf("Текущее состояние стека:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nВыберите операцию:\n");
        printf("1. Добавить элемент (push)\n");
        printf("2. Удалить элемент (pop)\n");
        printf("3. Показать стек\n");
        printf("4. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите значение: ");
            scanf("%d", &value);
            push(value);
            break;
            case 2:
                pop();
            break;
            case 3:
                display();
            break;
            case 4:
                return 0;
            default:
                printf("Неверный выбор. Повторите попытку.\n");
        }
    }
}

