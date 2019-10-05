/*
 *	Garth Slaney B01 		
 *  lab3exe_C.c
 *  ENSF 337, lab3 Exercise C
 *
 *  In this program the implementatiom of function pascal_trangle is missing.
 *  Studtent must complete this function.
 */

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
 PROMISES: displays a pascal_triangle. the first 5 line of the function's output
 should have the following format:
 row 0:  1
 row 1:  1   1
 row 2:  1   2   1
 row 3:  1   3   3   1
 row 4:  1   4   6   4   1
 */

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);
    if(nrow <= 0 || nrow > 20) {
        printf("Error: the maximum number of rows can be 20.\n");
        exit(1);
    }
    
    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) {
	int current_array[n];
	int past_array[n];
	for(int i = 0; n >= i; i++) { 
		for(int j = 0; i >= j; j++) 
			if( j == i || j == 0) 
				current_array[j] = 1;
			else 
				current_array[j] = past_array[(j-1)] + past_array[j];
		printf("Row %i:", i);
		for(int c = 0; i >= c; c++){
			printf("   %i", current_array[c]);
			past_array[c] = current_array[c];
		}
		printf("\n");
	}		
}
