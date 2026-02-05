#include <stdio.h>

int main() {
    int n, pos, arr[100];
    
    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &pos);
    
    // Shift left from position pos
    for (int i = pos - 1; i < n - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }
    
    // Print new array
    for (int i = 0; i < n - 1; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

