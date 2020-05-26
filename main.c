#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	printf("%s\n", argv[1]);    // check string 
	char *array;               // init array
	array = argv[1];          // copy string --> array 
	printf("%s\n", array);   // check array
	
	/*size array --> count && print array*/	
 
	int i = 0;                               //
	int count = 0;                          //
	printf("\n-- print_char_array --\n");  //
	while((array[i]!=0) && (i<6)){	      // print array
		printf("%c\n", array[i]);    // 
		count ++;		    //
		i++;                       //
	}
	
	/*save digit in int array*/
	
	int digit_array[count];        // 
	printf("\n-- switch --\n");   // 
	for (i=0;i<count;i++){       // char --> int   
		switch(array [i]){  //
			case '0':
				digit_array[i]=0;
				//printf("\nZero");
			break;

			case '1':
				digit_array[i]=1;
				//printf("\nOne");
			break;

			case '2':
				digit_array[i]=2;
				//printf("\nTwo");
			break;

			case '3':
				digit_array[i]=3;
				//printf("\nTree");
			break;

			case '4':
				digit_array[i]=4;
				//printf("\nFour");
			break;

			case '5':
				digit_array[i]=5;
				//printf("\nFive");
			break;

			case '6':
				digit_array[i]=6;
				//printf("\nSix");
			break;

			case '7':
				digit_array[i]=7;
				//printf("\nSeven");
			break;

			case '8':
				digit_array[i]=8;
				//printf("\nEight");
			break;

			case '9':
				digit_array[i]=9;
				//printf("\nNine");
			break;
		}
	}
	printf("\n-- print_int_array --\n");
	
	for (i=0;i<count;i++)
		printf("%d\n",digit_array[i]);
	return 0;
}
