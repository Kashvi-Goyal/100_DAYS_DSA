#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// --- COLOR DEFINITIONS ---
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m" 

// --- 1. THE STRUCTURE ---
struct Contact {
    char name[100];
    char phone[15];
    char email[100];
};

// --- 2. GLOBAL STORAGE ---
struct Contact address_book[200];
int contact_count = 0;

// --- 3. PROTOTYPES ---

void add_contact();
void display_all_contacts();
void search_contact();
void edit_contact(); 
void delete_contact();
void print_one_contact(struct Contact c); 
void welcome_screen(); 
void clear_screen();   
void wait_for_enter(); 

// --- 4. MAIN PROGRAM ---
int main() {
    int choice;

    welcome_screen();

    do {
        clear_screen();

        printf("\n%s  ************************************%s\n", CYAN, RESET);
        printf("%s     * Contact Management System *    %s\n", CYAN, RESET);
        printf("%s  ************************************%s\n\n\n", CYAN, RESET);
        printf("          1. Add Contact\n");
        printf("          2. Display All Contacts\n");
        printf("          3. Search Contact\n");
        printf("          4. Edit Contact\n");   
        printf("          5. Delete Contact\n");
        printf("          6. Exit\n\n");
        printf("          Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\n%s[Error] Invalid input. Please enter a number.%s\n", RED, RESET);
            
            // %*s means "read a string but don't save it anywhere"
            scanf("%*s"); 
            
        }

        // Clear screen to show results on a clean page
        clear_screen();

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_all_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                edit_contact(); 
                break;
            case 5:
                delete_contact();
                break;
            case 6:
                printf("\nExiting program... Goodbye!\n");
                break;
            default:
                printf("\n%s[Error] Invalid choice. Please pick 1-6.%s\n", RED, RESET);
        }

        // Pause unless the user is exiting
        if (choice != 6) {
            wait_for_enter();
        }

    } while (choice != 6);

    return 0;
}

// FUNCTIONS

void clear_screen() {
    // ANSI code to clear terminal
    printf("\033[H\033[J");
}

void wait_for_enter() {
    printf("\nPress [Enter] to return to the menu...");
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    getchar(); 
}

void welcome_screen() {
    clear_screen(); 
    
    printf("\n\n\n"); 

    printf("%s     CONTACT MANAGEMENT SYSTEM%s\n", GREEN, RESET);
    
    int rows = 6;
    for (int i = 0; i < rows; i++) {

        printf("            ");

        for (int j = 0; j < i; j++) {
            printf(" ");
        }

        printf("%s", YELLOW); 

        for (int k = 0; k < 2 * (rows - i) - 1; k++) {
            printf("*");
        }

        printf("%s\n", RESET); 
    }
    printf("\n\n");

    printf("      Project by: %s[Kashvi Goyal]%s\n", BLUE, RESET);
    printf("      SAP I'D:    %s[590024634]%s\n", BLUE, RESET);
    printf("\n\n");
    printf("%s>>> Press [Enter] to enter the system <<<%s\n", RED, RESET);
    
    getchar(); 
}


void add_contact() {
    if (contact_count >= 200) {
        printf("\nAddress book is full!\n");
        return;
    }

    printf("\n--- Add New Contact ---\n");
    printf("(Type '0' at any time to CANCEL)\n\n");
    
    printf("Enter Name: ");
    // " %[^\n]" to read names with spaces (e.g., "John Doe")
    scanf(" %[^\n]", address_book[contact_count].name);
    if (strcmp(address_book[contact_count].name, "0") == 0) {
        printf("\nOperation Cancelled.\n");
        return; 
    }
    
    // Loop for Phone Validation (Exactly 10 digits)
    while (1) {
        printf("\nEnter Phone (10 digits): ");
        scanf("%s", address_book[contact_count].phone);

        if (strcmp(address_book[contact_count].phone, "0") == 0) {
            printf("\nOperation Cancelled.\n");
            return; 
        }

        // Check if length is exactly 10
        if (strlen(address_book[contact_count].phone) != 10) {
            printf("%s[Error] Phone number must be exactly 10 digits. Try again.%s\n", RED, RESET);
            continue;
        }

        // Check if all characters are digits
        int valid_digits = 1;
        for (int i = 0; i < 10; i++) {
            if (address_book[contact_count].phone[i] < '0' || address_book[contact_count].phone[i] > '9') {
                valid_digits = 0;
                break;
            }
        }

        if (valid_digits) {
            break; // Input is valid
        } else {
            printf("%s[Error] Phone number must contain only digits. Try again.%s\n", RED, RESET);
        }
    }
    
    printf("\nEnter Email: ");
    scanf("%s", address_book[contact_count].email);

    // Save the contact by incrementing count
    contact_count++;
    printf("\n%sContact added successfully!%s\n", GREEN, RESET);
}

void display_all_contacts() {
    if (contact_count == 0) {
        printf("\nAddress book is empty.\n");
        return;
    }

    printf("\n--- All Contacts (%d) ---\n", contact_count);
    
    for (int i = 0; i < contact_count; i++) {
        printf("\nContact #%d\n", i + 1);
        print_one_contact(address_book[i]);
    }
}

void search_contact() {
    char search_name[100];
    printf("\n--- Search Contact ---\n");
    printf("Enter name (or part of name) to search (or '0' to cancel): ");
    scanf("%s", search_name);

    if (strcmp(search_name, "0") == 0) {
        printf("\nOperation Cancelled.\n");
        return;
    }

    int found = 0;

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < contact_count; i++) {
        if (strstr(address_book[i].name, search_name) != NULL) {
            printf("\nMatch Found at index #%d:\n", i + 1);
            print_one_contact(address_book[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nNo contacts found matching '%s'.\n", search_name);
    }
}

void edit_contact() {
    char search_name[100];
    printf("\n--- Edit Contact ---\n");
    printf("Enter EXACT name of contact to edit (or '0' to cancel): ");
    // Updated to read names with spaces
    scanf(" %[^\n]", search_name);

    if (strcmp(search_name, "0") == 0) {
        printf("\nOperation Cancelled.\n");
        return;
    }

    int found_index = -1;

    // Find the contact first
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(address_book[i].name, search_name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("\nContact not found.\n");
        return;
    }

    printf("\nContact Found! Enter New Details.\n");
    
    printf("Enter New Name: ");
    // allow spaces in the new name
    scanf(" %[^\n]", address_book[found_index].name);
    
    printf("Enter New Phone: ");
    scanf("%s", address_book[found_index].phone);
    
    printf("Enter New Email: ");
    scanf("%s", address_book[found_index].email);
    
    printf("\n%sContact updated successfully!%s\n", GREEN, RESET);
}

void delete_contact() {
    char search_name[100];
    printf("\n--- Delete Contact ---\n");
    printf("Enter name to delete (or '0' to cancel): ");
    scanf("%s", search_name);

    if (strcmp(search_name, "0") == 0) {
        printf("\nOperation Cancelled.\n");
        return;
    }

    int found_index = -1;

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(address_book[i].name, search_name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("\nContact not found.\n");
        return;
    }

    // Shift Logic: Overwrite the deleted contact
    for (int i = found_index; i < contact_count - 1; i++) {
        address_book[i] = address_book[i + 1];
    }

    contact_count--;
    printf("\n%sContact deleted successfully.%s\n", GREEN, RESET);
}

void print_one_contact(struct Contact c) {
    printf("  Name:  %s\n", c.name);
    printf("  Phone: %s\n", c.phone);
    printf("  Email: %s\n", c.email);
}