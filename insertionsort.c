#include <stdio.h>

int main() 
{
    int n, i, j, key;
    int arr[100]; 

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for(j=1; j<n; j++)
    {
        key = arr[j];
        i = j-1;
        while (i>=0 && arr[i]>key) 
        {
            arr[i+1] = arr[i];       
            i = i-1;
        }
        arr[i+1] = key;
    }
    
    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
