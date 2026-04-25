#include <stdio.h>

int main() {
    int r1, c1, r2, c2, i, j, k;  
    
    printf("Enter m*n for first matrix: ");    
    scanf("%d %d", &r1, &c1);
    printf("Enter n*p for second matrix: ");    
    scanf("%d %d", &r2, &c2);

   
    printf("First matrix: %d*%d (m=%d, n=%d)\n", r1, c1, r1, c1);
    printf("Second matrix: %d*%d (n=%d, p=%d)\n", r2, c2, r2, c2);
    if(c1 != r2) {
        printf("ERROR: n must match! (%d != %d)\n", c1, r2);
        return 1;
    }
    printf("Result will be: %d*%d\n\n", r1, c2);
    
    int a[10][10], b[10][10], c[10][10];
    
    printf("Enter first matrix (m*n = %d*%d):\n", r1, c1);
    for(i=0; i<r1; i++)
        for(j=0; j<c1; j++)
            scanf("%d", &a[i][j]);
    
    
    printf("Enter second matrix (n*p = %d*%d):\n", r2, c2);
    for(i=0; i<r2; i++)
        for(j=0; j<c2; j++)
            scanf("%d", &b[i][j]);
    
    for(i=0; i<r1; i++) {
        printf("Row %d of result (using A row %d * B columns):\n", i, i);
        for(j=0; j<c2; j++) {
            printf("  C[%d][%d]: ", i, j);
            int sum = 0;
            
            for(k=0; k<c1; k++) {
                int product = a[i][k] * b[k][j];
                printf("(%d*%d=%d) ", a[i][k], b[k][j], product);
                sum += product;
            }
            
            printf("= %d\n", sum);
            c[i][j] = sum;
        }
        printf("\n");
    }
    
    printf("Result matrix (m*p = %d*%d):\n", r1, c2);
    for(i=0; i<r1; i++) {
        for(j=0; j<c2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    
    return 0;
}