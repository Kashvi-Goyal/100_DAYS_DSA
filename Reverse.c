#include <stdio.h>

int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Checkpoint 1: Validate n
    if(n <= 0) 
    {
        printf("Error: Number of elements must be positive\n");
        return 1;
    }
    
    int arr[1000];  // Assuming max size
    
    // Checkpoint 2: Check array capacity
    if(n > 1000) 
    {
        printf("Error: Maximum 1000 elements allowed\n");
        return 1;
    }
    
    // Input array elements
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    // Two-pointer approach to reverse the array
    int left = 0;           // Start pointer
    int right = n - 1;      // End pointer
    
    while(left < right) 
    {
        // Swap elements at left and right pointers
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        // Move pointers toward center
        left++;
        right--;
    }
    
    // Print reversed array
    printf("Reversed array: ");
    for(int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
