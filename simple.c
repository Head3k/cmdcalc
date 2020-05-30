//КАЛЬКУЛЯТОР
 
#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
int main()
{
    setlocale(LC_ALL, "russian");
    char *b;
    float x, y, result;
    int a,flag1,flag2;
    flag1 = flag2 = a = 0;           //индентифицируем всё, чтобы компилятор не ругался
    b = (char*)malloc(2*sizeof(char));  //выделяем память для строки(будем вводить знак при помощи строки)
    if (!b)                            //если память не выделилась, то прерываем программу
    {
        printf("Что-то пошло не так...");
        system("pause");
        return 0;
    }                                //до сих пор была канитель с прерыванием программы
    fflush(stdin);                   //чистим входной поток
    do                               //цикл
    {
        printf("Введите первое число х=");
        scanf_s("%100,100f", &x);        //вводим первое число
        do
        {
            scanf_s("%s", b);
            fflush(stdin);
            if (*b == '+')
                a = 1;
            else if (*b == '-')
                a = 2;
            else if (*b == '*')
                a = 3;
            if (*b == '/' || *b == ':')
                a = 4;
            else
            {
                printf("\nВы ввели недопустимый знак, либо ввели знак неправильно. Попробуйте снова\n");
                flag1 = 1;      //если у нас любой символ, кроме нужного знака, то метка принимает значение 1
            }
            fflush(stdin);
        } while (flag1);     //если у нас метка принимает 1, то вводим знак заново
//      printf("%d", a);     //наш условный знак(плюс - а=1; минус - а=2; умножить - а=3; делить - а=4)
        free(b);
        printf("Введите второе число y=");
        scanf_s("%100,100f", &y);  //вводим второе число
        if (y == 0 && a == 4)        //проверка: знак проверяется на деление, а второе число на 0
        {
            printf("Вы пытаетесь поделить на 0\n");
            printf("Error");
            flag2 = 1;               //если у нас деление на ноль, то метка2 принимает значение 1
        }
    } while (flag2);                 //если метка2 принимает значение 1, то вводим все данные заново
    if (a == 1) result = x + y;      //если знак +, то сложение
    if (a == 2) result = x - 1;      //если -, то вычитание
    if (a == 3) result = x * y;      //если *, то умножение
    if (a == 4) result = x / y;      //если : или /, то деление
    printf("\n Результат вычисления=%10,10f", result);      //выводим результат
    system("pause");
    return 0;
}
