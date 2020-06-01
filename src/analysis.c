#include "include/analysis.h"
#include "include/interface.h"

//Сделать проверку операторов
//Сделать проверку наличия цифр

int analys(char **argv, int string_length)
{
    int error = 0;
    int error_ch = '0';

    if (string_length < 3)
    {
        printf("\nERROR: too short\n");
        return 1;
    }

    error = space_detector(argv, string_length);
    if (error == 1)
    {
        printf("\nError: all characters in the string are spaces\n");
        return 1;
    }

    error = bracket_detector(argv, string_length);
    if (error == 1)
    {

        return 1;
    }

    error = correct_input_detector(argv, string_length, "()/*+-.0123456789 ");
    if (error == 1)
    {
        printf("ERROR: unrecognized characters\n\nEnter numbers and operators: ()0123456789*+-/\n");
        return 1;
    }

    error = operator_detector(argv, string_length);
    if (error == 1)
    {
        return 1;
    }

    error_ch = type_of_mistake_1(argv, string_length);
    if (error_ch != '0')
    {
        printf("ERROR: (%c in row\n", error_ch);
        return 1;
    }

    error = type_of_mistake_2(argv, string_length);
    if (error == 1)
    {
        printf("ERROR: point after space\n");
        return 1;
    }

    error = type_of_mistake_3(argv, string_length);
    if (error == 1)
    {
        printf("ERROR: character.) in a row\n");
        return 1;
    }

    return error;
}
//Проверка на все пробелы в тексте
int space_detector(char **argv, int string_length)
{
    int i;
    int space_counter = 0;

    for (i = 0; i < string_length; i++)
    {
        if (argv[1][i] == ' ')
        {
            space_counter++;
        }
    }

    if (space_counter == string_length)
    {
        return 1;
    }
    return 0;
}
//Проверка равенства числа скобок и поиск ()
int bracket_detector(char **argv, int string_length)
{
    int i;
    int left_bracket_counter = 0;
    int right_bracket_counter = 0;

    for (i = 0; i < string_length; i++)
    {
        if (argv[1][i] == '(')
        {
            left_bracket_counter++;
        }
        if (argv[1][i] == ')')
        {
            right_bracket_counter++;
            if (right_bracket_counter > left_bracket_counter)
            {
                printf("ERROR: closed bracket without open bracket\n");
                return 1;
            }
        }
    }
    if (right_bracket_counter != left_bracket_counter)
    {
        printf("\nERROR: unequal number of brackets\n");
        return 1;
    }
    for (i = 0; i < string_length - 1; i++)
    {
        if ((argv[1][i] == '(') && (argv[1][i + 1]) == ')')
        {
            printf("ERROR: () -??? ٩(｡•́‿•̀｡)۶\n");
            return 1;
        }
    }

    return 0;
}
//Проверка на допустимые символы:()*-+/1234567890
int correct_input_detector(char **argv, int string_length, char *list)
{
    int i, j, correct_counter = 0;

    for (j = 0; j < string_length; j++)
    {
        for (i = 0; list[i] != '\0'; i++)
        {
            if (argv[1][j] == list[i])
            {
                correct_counter++;
            }
        }
    }
    if (correct_counter == string_length)
    {
        return 0;
    }
    return 1;
}
//Проверка на два оператора подряд и их отсутствие
int operator_detector(char **argv, int string_length)
{
    int i, j;

    for (i = 0; i < string_length - 1; i++)
    {
        j = i + 1;
        if ((argv[1][i] == '+') || (argv[1][i] == '-') || (argv[1][i] == '*') || (argv[1][i] == '/') || (argv[1][i] == '.'))
        {
            if ((argv[1][j] == '+') || (argv[1][j] == '-') || (argv[1][j] == '*') || (argv[1][j] == '/') || (argv[1][j] == '.'))
            {
                printf("ERROR: two operators or points, or point and operator in row\n");
                return 1;
            }
        }
    }
    for (i = 0; i < string_length - 1; i++)
    {
        if ((argv[1][i]) == ' ')
        {
            if (argv[1][i + 1] == ' ')
            {
                printf("ERROR: two spaces in row\n");
                return 1;
            }
        }
    }

    for (i = 0; i < string_length - 1; i++)
    {
        if ((argv[1][i] == '+') || (argv[1][i] == '-') || (argv[1][i] == '*') || (argv[1][i] == '/'))
            return 0;
    }
    printf("ERROR: no operators found\n");
    return 1;
}
//Проверка на шоибку вида ('operator'
char type_of_mistake_1(char **argv, int string_length)
{
    int i, j;

    for (i = 0; i < string_length - 1; i++)
    {
        j = i + 1;
        if (argv[1][i] == '(')
        {
            if ((argv[1][j] == '+') || (argv[1][j] == '*') || (argv[1][j] == '/') || (argv[1][j] == '.'))
            {
                return argv[1][j];
            }
        }
    }
    return '0';
}

//Проверка на ' .character' в строке
int type_of_mistake_2(char **argv, int string_length)
{
    int i;

    for (i = 0; i < string_length - 1; i++)
    {
        if (argv[1][i] == ' ')
        {
            if (argv[1][i + 1] == '.')
            {
                return 1;
            }
        }
    }
    return 0;
}
//Проверка на 'character.)' в строке
int type_of_mistake_3(char **argv, int string_length)
{
    int i;

    for (i = 0; i < string_length - 1; i++)
    {
        if (argv[1][i] == '.')
        {
            if (argv[1][i + 1] == ')')
            {
                return 1;
            }
        }
    }
    return 0;
}