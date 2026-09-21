#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int age;
} User;

int main() {
    FILE *fp;
    User user;

    /* Take input */
    printf("Enter ID: ");
    scanf("%d", &user.id);

    printf("Enter name: ");
    scanf("%s", user.name);

    printf("Enter age: ");
    scanf("%d", &user.age);

    /* Open .dat file for writing */
    fp = fopen("users.dat", "ab");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    /* Write data */
    fwrite(&user, sizeof(User), 1, fp);

    fclose(fp);

    printf("\nData saved successfully.\n");

    /* Open .dat file for reading */
    fp = fopen("users.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    /* Read and display data */
    printf("\nStored data:\n");

    while (fread(&user, sizeof(User), 1, fp) == 1) {
        printf("ID: %d\n", user.id);
        printf("Name: %s\n", user.name);
        printf("Age: %d\n", user.age);
    }

    fclose(fp);

    return 0;
}