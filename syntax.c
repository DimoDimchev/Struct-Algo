#include <stdio.h>
#include <stdlib.h>

/*
    PRINTING CHEAT-SHEET:
    %c character
    %d integer number(base 10)
    %e exponential floating-point number
    %f floating-point number
    %i integer (base 10)
    %o octal number(base 8)
    %s a string of characters
    %u unsigned decimal (integer) number
    %x number in hexadecimal (base 16)
    %% print a percent sign
*/

int main(){
    int arrayOfInt[] = {1, 2, 3, 4, 5}; /* declaration of an array of integers */

    int someVariable = 10; /* actual variable declaration */

    int *somePointer; /* pointer variable declaration */
    somePointer = &someVariable; /* store address of someVariable in pointer somePointer */

    for (int i = 0; i < 5; i++) {
        printf("Element on index %i is %d \n", i, arrayOfInt[i]); /* print every element of the array */
    }
    
}