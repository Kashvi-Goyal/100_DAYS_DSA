#include <stdio.h>

int main() 
{
    int n;    //no. of elements in array before insertion
    printf("Enter an element=");
    scanf("%d", &n);
    
    int arr[100];   //max limit of the array
    for(int i = 0; i < n; i++) 
    { 
        printf("Input five elements of the array");
        scanf("%d", &arr[i]);   //input elements of the array
    }
    
    int pos, element; // input the position and element to be inserted
    printf("Input the position=");
    scanf("%d", &pos);
    printf("input the element=");
    scanf("%d", &element);
    
    for(int i = n; i >= pos; i--) //shifting of the array elements to the right
    {
        arr[i] = arr[i-1];
    }
    
    arr[pos-1] = element;  // insertion of that element in the array
    

    for(int i = 0; i <= n; i++)  //print the updated array
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
