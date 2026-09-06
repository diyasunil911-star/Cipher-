#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        else if (islower(text[i]))
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
}

void decrypt(char text[], int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';
        else if (islower(text[i]))
            text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
    }
}

int main() {
    char text[100];
    int choice, key;

    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter key: ");
    scanf("%d", &key);
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
