//main -> analys -> CharToDigit -> calulation <-> calc ->output

#include <stdio.h>
#include "include/converter.h"
#include "include/rework.h"

int main(int argc, char *argv[]) //Параметры функции main [] - для доступа к отдельным символам
{                                //argc равно двум
    int array_char = converter(argv);

    double result = string_rework(argv, array_char); //Из реворка в калкулэйшн
    printf("\nРезультат - %.4f\n\n", result);

    return 0;
}
