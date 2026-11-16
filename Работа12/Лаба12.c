#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

struct employee {
    char fam[30];
    char name[30];
    char pos[30];
    double zp;
};

double calc(double a, int n) {
    double sum = 0.0;
    double chlen = 1.0;
    int i, j;

    for (i = 0; i <= n; i++) {
        chlen = 1.0;
        for (j = 0; j <= i; j++) {
            chlen = chlen / (a + j);
        }
        sum = sum + chlen;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    FILE* f;
    double num, a1, a2, h, a;
    int n, mode, count, i;
    char fname[20];

    printf("Задание 1\n");
    printf("Введи число: ");
    scanf("%lf", &num);

    strcpy(fname, "number.txt");
    f = fopen(fname, "w");
    if (f == NULL) {
        printf("Ошибка!\n");
        return 0;
    }
    fprintf(f, "%.2f\n", num);
    fclose(f);

    f = fopen(fname, "a");
    if (f != NULL) {
        fprintf(f, "12.56\n");
        fclose(f);
    }
    printf("Файл number.txt создан и дополнен.\n\n");

    printf("Задание 2\n");
    printf("Введи a1: ");
    scanf("%lf", &a1);
    printf("Введи a2: ");
    scanf("%lf", &a2);
    printf("Введи шаг h: ");
    scanf("%lf", &h);
    printf("Введи n: ");
    scanf("%d", &n);
    printf("Режим (1-новый,2-дописать): ");
    scanf("%d", &mode);

    strcpy(fname, "temp.txt");
    if (mode == 1) {
        f = fopen(fname, "w");
    }
    else {
        f = fopen(fname, "a");
    }

    if (f == NULL) {
        printf("Ошибка файла!\n");
        return 0;
    }

    fprintf(f, "a\t\tResult\n");
    a = a1;
    while (a <= a2 + 0.0001) {
        fprintf(f, "%.2f\t\t%.6f\n", a, calc(a, n));
        a = a + h;
    }
    fclose(f);
    printf("Результат в temp.txt\n\n");

    printf("Задание 3\n");
    struct employee spisok[10];
    printf("Сколько сотрудников? ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("Сотрудник %d: ", i + 1);
        scanf("%s %s %s %lf", spisok[i].fam, spisok[i].name, spisok[i].pos, &spisok[i].zp);
    }

    f = fopen("staff.txt", "w");
    if (f == NULL) {
        printf("Ошибка!\n");
        return 0;
    }

    for (i = 0; i < count; i++) {
        fprintf(f, "%s %s %s %.2f\n", spisok[i].fam, spisok[i].name, spisok[i].pos, spisok[i].zp);
    }
    fclose(f);

    printf("Данные в staff.txt\n");
    getchar(); getchar();
    return 0;
}