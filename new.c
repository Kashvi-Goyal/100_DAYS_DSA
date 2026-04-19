#include <stdio.h>
#include <time.h>

int main() {
    int n_values[] = {1000, 2000, 4000};
    int sizes = 3;
    
    for(int k = 0; k < sizes; k++) 
    {
        int n = n_values[k];
        clock_t start = clock();
        
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) 
            {
                sum += i + j; 
            }
        }
        
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("For n=%d, time: %f seconds\n", n, time_taken);
    }
    return 0;
}
