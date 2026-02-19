#include <stdio.h>

int main() {
    char str[100];  // Buffer for input string (sufficient for typical constraints)
    
    // Read the input string
    scanf("%s", str);
    
    // Calculate length manually (no library strlen)
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    // Swap characters from start and end
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    
    // Print reversed string
    printf("%s\n", str);
    
    return 0;
}
