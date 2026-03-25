#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Required for system()

// --- COLOR DEFINITIONS ---
// These are special codes that change the text color in the console
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"  // Resets color back to normal

struct Contact {
    char name[100];
    char phone[15];
    char email[100];
};

// Global Storage (Filing Cabinet)
struct Contact address_book[200];
int contact_count = 0;

// --- Function Prototypes ---
void add_contact();
void display_all_contacts();
void search_contact();
void delete_contact();
void print_one_contact(struct Contact c);
void welcome_screen(); 
void clear_screen();   
void wait_for_enter(); 

int main() {
    int choice;

    // 1. Show the Welcome Screen first
    welcome_screen();

    do {
        // 2. Clear the screen every time the menu loops
        clear_screen();

        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        // 3. Clear the screen again so the RESULT is on a clean page
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
                delete_contact();
                break;
            case 5:
                printf("\nExiting program... Goodbye!\n");
                break;
            default:
                printf("\n[Error] Invalid choice. Please pick 1-5.\n");
        }

        // 4. If the user didn't choose exit, Pause so they can read the result
        if (choice != 5) {
            wait_for_enter();
        }

    } while (choice != 5);

    return 0;
}

// --- NEW HELPER FUNCTIONS ---

// Clears the console window
void clear_screen() {
    printf("\033[H\033[J");
}

// Pauses and waits for user to press Enter (Used AFTER scanf)
void wait_for_enter() {
    printf("\nPress [Enter] to return to the menu...");
    while (getchar() != '\n'); // Clear buffer
    getchar(); // Wait for actual key press
}

// The Starting Slide with COLOR & LOOP-GENERATED Star Patterns
void welcome_screen() {
    clear_screen(); 
    
    int rows = 6; // Height of the triangles
    int i, j, k;

    printf("\n\n");

    // Switch to YELLOW for the top stars
    printf("%s", YELLOW);

    // --- 1. TOP TRIANGLE (Straight Pyramid Loop) ---
    for (i = 1; i <= rows; i++) {
        // Print leading spaces
        for (j = 1; j <= 18 - i; j++) {
            printf(" ");
        }
        // Print the stars
        for (k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    // Reset color, then print the Cyan Box
    printf("%s", RESET);
    printf("\n");
    printf("%s   ===========================================\n", CYAN);
    printf("   ||                                       ||\n");
    printf("   ||      %sCONTACT MANAGEMENT SYSTEM%s        ||\n", GREEN, CYAN);
    printf("   ||                                       ||\n");
    printf("   ===========================================%s\n", RESET);
    printf("\n");

    // Switch to YELLOW for the bottom stars
    printf("%s", YELLOW);

    // --- 2. BOTTOM TRIANGLE (Inverted Pyramid Loop) ---
    for (i = rows; i >= 1; i--) {
        // Print leading spaces
        for (j = 1; j <= 18 - i; j++) {
            printf(" ");
        }
        // Print the stars
        for (k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    // Reset to normal for the footer text
    printf("%s", RESET);

    printf("\n\n");
    printf("            Project by: %s[Your Name]%s\n", BLUE, RESET);
    printf("            Roll No:    %s[Your Roll No]%s\n", BLUE, RESET);
    printf("\n\n");
    printf("      %s>>> Press [Enter] to enter the system <<<%s\n", RED, RESET);
    
    // Wait for Enter
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- WORKER FUNCTIONS ---

void add_contact() {
    if (contact_count >= 200) {
        printf("\nAddress book is full!\n");
        return;
    }

    printf("\n--- Add New Contact ---\n");
    printf("(Type '0' at any time to CANCEL operation)\n\n");
    
    printf("Enter Name: ");
    scanf("%s", address_book[contact_count].name);
    if (strcmp(address_book[contact_count].name, "0") == 0) {
        printf("\nOperation Cancelled.\n");
        return; 
    }
    
    printf("Enter Phone: ");
    scanf("%s", address_book[contact_count].phone);
    if (strcmp(address_book[contact_count].phone, "0") == 0) {
        printf("\nOperation Cancelled.\n");
        return; 
    }
    
    printf("Enter Email: ");
    scanf("%s", address_book[contact_count].email);

    contact_count++;
    printf("\nContact added successfully!\n");
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
    printf("Enter name to search (or '0' to cancel): ");
    scanf("%s", search_name);

    if (strcmp(search_name, "0") == 0) {
        printf("\nOperation Cancelled.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(address_book[i].name, search_name) == 0) {
            printf("\nContact Found!\n");
            print_one_contact(address_book[i]);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nContact not found.\n");
    }
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

    for (int i = found_index; i < contact_count - 1; i++) {
        address_book[i] = address_book[i + 1];
    }

    contact_count--;
    printf("\nContact deleted successfully.\n");
}

void print_one_contact(struct Contact c) {
    printf("  Name:  %s\n", c.name);
    printf("  Phone: %s\n", c.phone);
    printf("  Email: %s\n", c.email);
}