#include <stdio.h>
#include <string.h>
#include <crypt.h>

void crack_password(const char* hashed_password, const char* password_list) {
    FILE *file = fopen(password_list, "r");
    if (!file) {
        printf("Could not open password list file.\n");
        return;
    }

    char password[100];
    while (fgets(password, sizeof(password), file)) {
        // Remove the newline character from the password
        password[strcspn(password, "\n")] = 0;

        // Check if the hashed version of the password matches the given hash
        char *hashed_attempt = crypt(password, hashed_password);
        if (strcmp(hashed_attempt, hashed_password) == 0) {
            printf("Password cracked! The password is: %s\n", password);
            fclose(file);
            return;
        }
    }

    printf("Password not found in the list.\n");
    fclose(file);
}

int main() {
    const char* hashed_password = "$6$ASDFGHJKL$8bVfF/AwpAeE9jCa0URjTsdgTVqT1XOT4dBiEVqZB8c6/34kQYYbF4xV2yxrYvGe6g6f08SD7jgfCm5XOsMXM8.";
    const char* password_list = "passwords.txt"; // Replace with your password list filename

    crack_password(hashed_password, password_list);
    return 0;
}
