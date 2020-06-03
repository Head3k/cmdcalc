#include <stdio.h>
#include <math.h>
#include <stdlib.h>                                 
#include "include/computing.h"
 
void delete_space(char *array)
{
    int i = 0, j = 0;
    
    while ((*(array+i) = *(array + j++)) != '\0') {
        if (*(array+i) != ' ') {
            i++;
        }
    }
}

void check_brackets(char *array)
{
    int open = 0, close = 0;
    
    while (*array) {
        if (*array == '(') {
            open++;
        } else if (*array == ')') {
            close++;
        }
   
        ++array;
    }
  
    if (open != close) {
        printf("Brackets unbalanced!\n");
        exit(-1);
    }
        
}

float calculation(char *array)                  // calculation
{                                              
    int i = 0;                            // i --> selected element
                                             
    return second_priority(array, &i);  // call '+' && '-'
}
 
float second_priority(char *array, int *i)     // i --> selected element
{                                                 
    float result = first_priority(array, i); // call '*' && '/'

    while (*(array + *i) == '+' || *(array + *i) == '-') {                            
        switch (*(array + *i)) {
        case '+':
            ++*i;
            result += first_priority(array, i);
            break;

        case '-':
            ++*i;
            result -= first_priority(array, i);
            break;
        }
    }
    
    return result;
}
 
float first_priority(char *array, int *i)      
{
    float divider;
    float result = brackets_priority(array, i);

    while (*(array + *i) == '*' || *(array + *i) == '/') {                       
        switch (*(array + *i)) {
        case '*':
            ++*i;
            result *= brackets_priority(array, i);
            break;

        case '/':
            ++*i;
            divider = brackets_priority(array, i);
            
            if (divider != 0) {                      
                result /= divider;
            } else {                        
                printf("Division by zero is not defined\n");         
                exit(-1);
            }
            
            break;
       }
    }
    
    return result;
}

float brackets_priority(char *array, int *i)    
{
    float result;

    if (*(array + *i) == '(') {                   
        ++*i;
        result = second_priority(array, i);
        ++*i;
    } else {
        result = digit(array, i);  
    }
    
    return result;
}
 
float digit(char *array, int *i)                     
{
    float result = 0;
    float factor = 1;
    short extra = 1;

    while (*(array + *i) == '-') {                    
        extra *= -1;
        ++*i;
    }
    
    while (*(array + *i) >= '0' && *(array + *i) <= '9') {
        result = 10 * result + (*(array + *i) - '0');
        ++*i;
    }
    
    if ( *(array + *i) == '.') {
        ++*i;
                         
        while (*(array + *i) >= '0' && *(array + *i) <= '9') { 
            factor *= 0.1;
            result = result + (*(array + *i) - '0') * factor;
            ++*i;
        }
    }
    
    return result * extra;
}


