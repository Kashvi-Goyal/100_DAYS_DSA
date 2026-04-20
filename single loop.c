#include <stdio.h>
#include <time.h>

int main() 
{
    clock_t start = clock();       
    
    int sum = 0;
    for(int i = 0; i < 3; i++) 
    {    
        sum += i;
    }
    
    clock_t end = clock();        
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
    
    printf("n = 3, sum = %d, time = %.7f seconds", sum, time_taken);
    
    return 0;
}
