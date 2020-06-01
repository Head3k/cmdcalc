//main -> analys -> CharToDigit -> calulation <-> calc ->output

#include <stdio.h>
#include "include/analysis.h"
#include "include/interface.h"
#include "include/rework.h"

int main(int argc, char *argv[]) //Параметры функции main [] - для доступа к отдельным символам
{                                //argc равно двум
    int error_check;
    int string_length = interface(argv);
    error_check = analys(argv, string_length);

    if (error_check == 1)
    {
        printf("\nThe program is terminated due to an error\n\n");
        return 1;
    }

    double result = string_rework(argv, string_length); //Из реворка в калкулэйшн
    printf("\nРезультат - %.4f\n\n", result);

    return 0;
}