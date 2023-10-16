#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Define a structure for user data
struct User {
    char username[50];
    char password[50];
};

// Function to read an array of structures from a file using system calls
int readUsersFromFile(struct User users[], int maxUsers, const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 0;  // File not found or unable to open
    }

    int numUsers = 0;
    while (read(fd, &users[numUsers], sizeof(struct User)) == sizeof(struct User)) {
        numUsers++;
        if (numUsers >= maxUsers) {
            break;
        }
    }

    close(fd);
    return numUsers;
}

// Function to authenticate a user
int authenticateUser(struct User users[], int numUsers, const char* username, const char* password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                return 1;  // Username and password match
            } else {
                return 0;  // Incorrect password
            }
        }
    }
    return 2;  // Username not found
}

int main() {
    // Define an array of structures to store user data
    struct User users[100];  // Assuming a maximum of 100 users
    int numUsers = readUsersFromFile(users, 100, "user_data.dat");

    if (numUsers == 0) {
        printf("Error: Unable to read user data from file.\n");
        return 1;
    }

    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int result = authenticateUser(users, numUsers, username, password);

    if (result == 1) {
        printf("Authentication successful.\n");
    } else if (result == 0) {
        printf("Incorrect password.\n");
    } else if (result == 2) {
        printf("Username not found.\n");
    }

    return 0;
}

