//
// Created by Алексей Куриганов on 16.04.2025.
//
#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Стек переполнен!\n");
        return;
    }
    s->data[++(s->top)] = value;
    printf("Элемент %d добавлен в стек.\n", value);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Стек пуст, удаление невозможно!\n");
        return;
    }
    printf("Элемент %d удалён из стека.\n", s->data[(s->top)--]);
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Стек пуст.\n");
        return;
    }
    printf("Текущее состояние стека:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}

int main() {
    Stack s;
    init(&s);
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
            push(&s, value);
            break;
            case 2:
                pop(&s);
            break;
            case 3:
                display(&s);
            break;
            case 4:
                return 0;
            default:
                printf("Неверный выбор. Повторите попытку.\n");
        }
    }
}
