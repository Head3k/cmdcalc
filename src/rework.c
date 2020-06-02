#include "include/rework.h"
#include "include/calculation.h"
#include "stdlib.h"

//Находим числа, преобразуем, нумеруем. Находим операторы, нумеруем. Вычисляем с соответствием номеров

double string_rework(char **argv, int string_length)
{
    int z = 0, i, open_bracket = 0;
    char *string;
    string = malloc(sizeof(char) * 9000);

    for (i = 0; argv[1][i] != '\0'; i++)
    {
        while (argv[1][i] == ' ')
        {
            i++;
        }

        string[z] = argv[1][i];
        z++;

        if (argv[1][i] == '(')
        {
            open_bracket++;
        }
    }

    double result = calculation(string, 0, z - 1); //Поступает на вход строка, ее начало, и индекс последнего символа
    return result;
}