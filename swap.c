
#include <stdio.h> 
#include <stdlib.h>
 
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
int main(int argc, char** argv) 
{ 
    int x=atoi(argv[1]), y=atoi(argv[2]);
    printf("\nBefore Swapping: x = %d, y = %d", x, y); 
    swap(&x, &y); 
    printf("\nAfter Swapping: x = %d, y = %d\n", x, y); 
    return 0; 
} 
