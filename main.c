#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	printf("%s\n", argv[1]);    // check string 
	char *array;               // init array
	array = argv[1];          // copy string --> array 
	printf("%s\n", array);   // check array
	
	int count;
	int i;
	for (i=0;i<6;i++){
		if (array [i] != '+') && (array [i] != '-') && (array [i] != '*') && (array [i] != '/') && (array [i] != '(') && (array [i] != ')'){  		
			switch(array [i]){
				case '1':
					printf("One");
				break;
				case '+':
					printf("Plus");
				break;
			}
		}
	}	
	return 0;
	
}
