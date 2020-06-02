#include "include/rework.h"
#include "include/calculation.h"
#include "stdlib.h"

//Находим числа, преобразуем, нумеруем. Находим операторы, нумеруем. Вычисляем с соответствием номеров

double string_rework(char *array_char, int array_count)
{
    int z = 0, i, open_bracket = 0;
    char *string;
    string = malloc(sizeof(char) * 9000);

    for (i = 0; array_char[i] != '\0'; i++)
    {
        while (array_char[i] == ' ')
        {
            i++;
        }

        string[z] = array_char[i];
        z++;

        if (array_char[i] == '(')
        {
            open_bracket++;
        }
    }

    double result = calculation(string, 0, z - 1); //Поступает на вход строка, ее начало, и индекс последнего символа
    return result;
}