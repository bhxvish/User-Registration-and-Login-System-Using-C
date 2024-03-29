#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Admin "Bhavish"
#define Pass "1234"

#define MAX_USERS 100


struct User {
    char userID[10];
    char name[50];
    char email[50];
    char mobile[15];
    char address[100];
};


struct User users[MAX_USERS]; 
int userCount = 0; 
void registerUser();
void generateUserID(char *userID);
void displayUsers();
int loginUser();

int main() {
    int choice;
    
    do {
        printf("\nUser Registration and Login System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Display Users\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser())
                    printf("Login successful!\n");
                else
                    printf("Login failed. Invalid credentials.\n");
                break;
            case 3:
                displayUsers();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}


void registerUser() {
    struct User newUser;
    
    printf("\nEnter Name: ");
    scanf(" %s", newUser.name);
    
    printf("Enter Email: ");
    scanf("%s", newUser.email);
    
    printf("Enter Mobile: ");
    scanf("%s", newUser.mobile);
    
    printf("Enter Address: ");
    scanf(" %s", newUser.address);
    
    
    generateUserID(newUser.userID);
    
    
    users[userCount++] = newUser;
    
    printf("User registered successfully.\n");
}


void generateUserID(char *userID) {
    static int id = 1;
    sprintf(userID, "U%04d", id++);
}


void displayUsers() {
    if (userCount == 0) {
        printf("No users registered yet.\n");
        return;
    }
    
    printf("\nList of Registered Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("User ID: %s\n", users[i].userID);
        printf("Name: %s\n", users[i].name);
        printf("Email: %s\n", users[i].email);
        printf("Mobile: %s\n", users[i].mobile);
        printf("Address: %s\n", users[i].address);
        printf("-------------------------\n");
    }
}


int loginUser() {
    char email[50];
    char mobile[15];
    int found = 0;
    
    printf("\nEnter Email: ");
    scanf("%s", email);
    
    printf("Enter Mobile: ");
    scanf("%s", mobile);
    if ((email == Admin)&&(mobile == Pass)){
        printf("Welcome admin\n");
    }
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(email, users[i].email) == 0 && strcmp(mobile, users[i].mobile) == 0) {
            found = 1;
            break;
        }
    }
    
    return found;
}


