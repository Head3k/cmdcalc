#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("%s\n", argv[1]);
    char* array;
    array = argv[1];
    printf("%s\n", array);
    printf("%c\n", array[1]);
    printf("%c\n", array[2]);
    return 0;
}
