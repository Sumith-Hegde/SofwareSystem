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

// Function to write user data to a file using system calls
void writeUserToFile(const struct User* user, const char* filename) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    if (write(fd, user, sizeof(struct User)) != sizeof(struct User)) {
        perror("Error writing to file");
    }

    close(fd);
}

int main() {
    struct User user;

    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter password: ");
    scanf("%s", user.password);

    writeUserToFile(&user, "user_data.dat");

    printf("User data has been stored in 'user_data.dat'.\n");

    return 0;
}

