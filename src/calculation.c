#include "include/calculation.h"

int power(int x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 1 / (x * power(1 / x, n + 1));
    return x * power(x, n - 1);
}

double char_to_digit(char *string, int i1, int i2)
{
    double Result = 0, doubles = 0;
    int i, d, x;

    for (i = i1; i <= i2; i++)
    {
        if (string[i] != '.')
            Result = (Result + (string[i] - '0')) * 10;
        else
            break;
    }

    Result = Result / 10;
    d = i;

    for (i = i + 1; i <= i2; i++)
        if (string[i] != '.')
            Result = Result + (doubles + (string[i] - '0')) / (x = power(10, i - d));
        else
            break;
    return Result;
}

double calculation(char *string, int Start, int End)
{
    int i = Start, open_bracket, close_bracket, o_bracket, cl_bracket, Tmp = 0;

    if ((string[Start] == '(') && (string[End] == ')'))
    {
        open_bracket = 1;
        close_bracket = 0;
        i++;
        while (!(open_bracket == close_bracket))
        {
            if (string[i] == '(')
                open_bracket++;
            if (string[i] == ')')
                close_bracket++;
            i++;
        }
        i--;
        if (i == End)
            return calculation(string, Start + 1, End - 1);
    }

    for (i = Start; i <= End; i++)
    {
        if (string[i] == '+')
        {
            return calculation(string, Start, (i - 1)) + calculation(string, (i + 1), End);
        }
        if (string[i] == '-')
        {
            if (i > Tmp)
            {
                Tmp = i;
            }
            continue;
        }
        if (string[i] == '*')
        {
            if (Tmp == 0)
            {
                Tmp = i;
            }
            continue;
        }
        if (string[i] == '/')
        {
            if ((Tmp == 0) || (string[Tmp] == '/'))
            {
                Tmp = i;
            }
        }
        if (string[i] == '(')
        {
            o_bracket = 1;
            cl_bracket = 0;
            i++;
            while (!(o_bracket == cl_bracket))
            {
                if (string[i] == '(')
                    o_bracket++;
                if (string[i] == ')')
                    cl_bracket++;
                i++;
            }
            i--;
            continue;
        }
    }
    if (Tmp > 0)
    {
        switch (string[Tmp])
        {
        case '-':
            return calculation(string, Start, Tmp - 1) - calculation(string, Tmp + 1, End);
        case '*':
            return calculation(string, Start, Tmp - 1) * calculation(string, Tmp + 1, End);
        case '/':
            return calculation(string, Start, Tmp - 1) / calculation(string, Tmp + 1, End);
        }
    }
    return char_to_digit(string, Start, End);
}
