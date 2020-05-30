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
		printf("%c\n", array[i]);    // 
		count++;                    //
		i++;                       //
	}

	int k=0;	
	int tmp=0;
	int digit[count];
	char t_cont[128];

	while (i<count){
		
		// registr digit 
		
		if (array[i]=='0'){
			//if (t_cont !=0){
				t_cont[i] = array[i];
		}
		if (array[i]=='1'){
			t_cont[i] = array[i];
		}
		if (array[i]=='2'){
			t_cont[i] = array[i];	
		}
		if (array[i]=='3'){
			t_cont[i] = array[i];	
		}
		if (array[i]=='4'){
			t_cont[i] = array[i];	
		}
		if (array[i]=='5'){
			t_cont[i] = array[i];
		}
		if (array[i]=='6'){
			t_cont[i] = array[i];
		}
		if (array[i]=='7'){
			t_cont[i] = array[i];
		}
		if (array[i]=='8'){
			t_cont[i] = array[i];
		}
		if (array[i]=='9'){
			t_cont[i] = array[i];
		}
		
		else{
			tmp = atoi(t_cont);  // drop digital -->  int tmp 
			k++;
		digit[k] = tmp;
		}
	}
	for (k=0;k<count;k++)
		printf("\n%d", digit[k]);
}
	
	
