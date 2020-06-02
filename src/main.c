//main -> converter -> calulation <-> calc ->output

#include <stdio.h>
#include "include/converter.h"
#include "include/rework.h"

int main(int argc, char *argv[]) //Параметры функции main [] - для доступа к отдельным символам
{                                //argc равно двум
    char *array_char;
    int array_count = counter(argv);

    array_char = argv[1]; // Вывести в отдельную функцию

    double result = string_rework(array_char, array_count); //Вычисления
    printf("\nРезультат - %.4f\n\n", result);

    return 0;
}
