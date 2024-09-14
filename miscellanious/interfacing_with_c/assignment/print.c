#include <stdio.h>

void print_array(int values[], int length){
    
    for (int i = 0; i < length; i++)
    {
        printf("%d,", values[i]);
    }
	printf("\n");
    
}
