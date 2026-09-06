#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], char key[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            text[i] = key[text[i] - 'A'];
        else if (islower(text[i]))
            text[i] = tolower(key[text[i] - 'a']);
    }
}

void decrypt(char text[], char key[]) {
    int i, j;
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            for (j = 0; j < 26; j++) {
                if (key[j] == text[i]) {
                    text[i] = 'A' + j;
                    break;
                }
            }
        } else if (islower(text[i])) {
            for (j = 0; j < 26; j++) {
                if (tolower(key[j]) == text[i]) {
                    text[i] = 'a' + j;
                    break;
                }
            }
        }
    }
}

int main() {
    char text[100];
    char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int choice;

    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    if (choice == 1) {
        encrypt(text, key);
        printf("Encrypted text: %s", text);
    } else if (choice == 2) {
        decrypt(text, key);
        printf("Decrypted text: %s", text);
    } else {
        printf("Invalid choice");
    }

    return 0;
}
