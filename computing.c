#include <stdio.h>
#include <math.h>
#include <stdlib.h>                                 
#include "computing.h"
 
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
    int index = 0;                            // index --> selected element
                                             
    return second_priority(array, &index);  // call '+' && '-'
}
 
float second_priority(char *array, int *index)     // index --> selected element
{                                                 
    float result = first_priority(array, index); // call '*' && '/'

    while (*(array + *index) == '+' || *(array + *index) == '-') {                            
        switch (*(array + *index)) {
        case '+':
            ++*index;
            result += first_priority(array, index);
            break;

        case '-':
            ++*index;
            result -= first_priority(array, index);
            break;
        }
    }
    
    return result;
}
 
float first_priority(char *array, int *index)      
{
    float divider;
    float result = brackets_priority(array, index);

    while (*(array + *index) == '*' || *(array + *index) == '/') {                       
        switch (*(array + *index)) {
        case '*':
            ++*index;
            result *= brackets_priority(array, index);
            break;

        case '/':
            ++*index;
            divider = brackets_priority(array, index);
            
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

float brackets_priority(char *array, int *index)    
{
    float result;

    if (*(array + *index) == '(') {                   
        ++*index;
        result = second_priority(array, index);
        ++*index;
    } else {
        result = digit(array, index);  
    }
    
    return result;
}
 
float digit(char *array, int *index)                     
{
    float result = 0;
    float factor = 1;
    short extra = 1;

    while (*(array + *index) == '-') {                    
        extra *= -1;
        ++*index;
    }
    
    while (*(array + *index) >= '0' && *(array + *index) <= '9') {
        result = 10 * result + (*(array + *index) - '0');
        ++*index;
    }
    
    if ( *(array + *index) == '.') {
        ++*index;
                         
        while (*(array + *index) >= '0' && *(array + *index) <= '9') { 
            factor *= 0.1;
            result = result + (*(array + *index) - '0') * factor;
            ++*index;
        }
    }
    
    return result * extra;
}


