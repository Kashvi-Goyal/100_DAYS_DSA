#include <stdio.h>

int main()
{
    int a;
    int *p;
    a = 10; // &a = address of a
    printf("Address of a is %d\n", &a);
    p = &a; // will the address in p change to point b
    printf("Address of p is %d\n", p);
    printf("Value at p is %d\n", *p);
    return 0;
}
