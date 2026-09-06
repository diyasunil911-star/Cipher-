#include <stdio.h>
#include <string.h>

void encrypt(char text[], int key, char result[]) {
    int len = strlen(text);
    int row = 0, dir = 1, k = 0;
    char rail[key][len];

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    for (int i = 0; i < len; i++) {
        rail[row][i] = text[i];

        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;

        row += dir;
    }

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                result[k++] = rail[i][j];

    result[k] = '\0';
}

void decrypt(char text[], int key, char result[]) {
    int len = strlen(text);
    int row = 0, dir = 1, k = 0;
    char rail[key][len];

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    for (int i = 0; i < len; i++) {
        rail[row][i] = '*';

        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;

        row += dir;
    }

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*')
                rail[i][j] = text[k++];

    row = 0;
    dir = 1;
    k = 0;

    for (int i = 0; i < len; i++) {
        result[k++] = rail[row][i];

        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;

        row += dir;
    }

    result[k] = '\0';
}

int main() {
    char text[100], result[100];
    int choice, key;

    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter number of rails: ");
    scanf("%d", &key);
    getchar();

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    if (choice == 1) {
        encrypt(text, key, result);
        printf("Encrypted text: %s", result);
    } else if (choice == 2) {
        decrypt(text, key, result);
        printf("Decrypted text: %s", result);
    } else {
        printf("Invalid choice");
    }

    return 0;
}
