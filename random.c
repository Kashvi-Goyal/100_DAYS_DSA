#include <stdio.h>
#include <stdlib.h>  
#include <time.h>    
int main() {
    int n, i, j, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[10000];  

    
    srand(time(0));  
    printf("Randomly generated array:\n");
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 100;  
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    
    clock_t start_asc = clock();  

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    clock_t end_asc = clock();  
    double time_taken_asc = ((double)(end_asc - start_asc)) / CLOCKS_PER_SEC;

    printf("Sorted array in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken for ascending sort: %f seconds\n\n", time_taken_asc);

    
    clock_t start_desc = clock();  
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    clock_t end_desc = clock();  
    double time_taken_desc = ((double)(end_desc - start_desc)) / CLOCKS_PER_SEC;

    printf("Sorted array in descending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken for descending sort: %f seconds\n", time_taken_desc);

    return 0;
}