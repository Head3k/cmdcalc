#include <stdio.h>
#include <stdlib.h>
#include "computing.h" 
                                                                                   
int main(int argc, char *argv[])                    
{
    
    char *array_char;               // init array
    array_char = argv[1];          // copy string --> array_char    


    delete_space(array_char);  // array without space
    check_brackets(array_char);
    printf("%g\n", calculation(array_char)); // check value
    return 0;
}

