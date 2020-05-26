#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	printf("%s\n", argv[1]);    // check string               |     A
	char *array;               // init CHAR array             |     R
	array = argv[1];          // copy string --> CHAR array   |     R
	printf("%s\n", array);   // check CHAR array              |     A
	                        //                                |     Y
	/*size array --> count && print array*/	
 
	int i = 0;                               //
	int count = 0;                          //
	printf("\n-- print_char_array --\n");  //
	while(array[i] != 0){	              // print CHAR array 
		printf("%c\n", array[i]);        // 
		count ++;		    		    //
		i++;                           //
	}
	
	
	
