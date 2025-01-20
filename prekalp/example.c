#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[100];
    int age;
} UserData;

void createNewUser()
{
    UserData user;
    int id, exists = 0;

    FILE *file = fopen("user_data.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open the file for reading\n");
        return;
    }

    printf("Enter the user ID: ");
    scanf("%d", &id);

    // Check if the user ID already exists
    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            exists = 1;
            printf("User ID already taken. Please try another one\n");
            break;
        }
    }

    if (exists)
    {
        fclose(file);
        return;
    }
    fclose(file);

    // Open the file in append mode to add a new user
    file = fopen("user_data.txt", "a");

    if (file == NULL)
    {
        printf("Unable to open the file for writing\n");
        return;
    }

    user.id = id;

    while (getchar() != '\n')
        ; // Clear input buffer before reading the name
    printf("Enter name: ");
    fgets(user.name, 100, stdin);               // Use fgets to allow names with spaces
    user.name[strcspn(user.name, "\n")] = '\0'; // Remove trailing newline character

    int validAge = 0;
    while (!validAge) {
        printf("Enter Age: ");
        if (scanf("%d", &user.age) != 1) {
           // clearBuffer();  // Clear invalid input
            printf("Invalid input for age! Please enter a valid integer.\n");
            exit(1);
        } else {
            validAge = 1;  // Age is valid, exit the loop
        }
    }

    // Write to file
    fprintf(file, "%d\t%s\t%d\n", user.id, user.name, user.age);
    printf("The user is successfully added\n");

    fclose(file);
    return;
}

void displayAllUsers()
{
    FILE *file = fopen("user_data.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
   
    UserData user;
    int foundUser = 0; 
    printf("\n--- User List ---\n");
    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) == 3)
    {
        // printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
        foundUser = 1;  // at least one user found
        printf("{\n");
        printf("    User ID: %d\n", user.id);
        printf("    Name: %s \n", user.name);
        printf("    Age: %d\n", user.age);
        printf("}\n");
    }

    if(!foundUser){
        printf("No users found\n");
    }

    fclose(file);
    return;
}

void updateUser()
{
    int id, exists = 0;
    UserData user;
    FILE *file = fopen("user_data.txt", "r");
    FILE *temp_file = fopen("temp_file.txt", "w");

    if (file == NULL || temp_file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter User ID to modify: ");
    scanf("%d", &id);
    getchar(); // clear the newline character left by scanf

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            exists = 1;
            printf("User found. Enter new details.\n");

            // // Input new name
            // while (getchar() != '\n');  // Clear any leftover newline character
            printf("Enter new name: ");
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0'; // Remove trailing newline

            // Input new age with validation
            int validAge = 0;
            while (!validAge)
            {
                printf("Enter new age: ");
                if (scanf("%d", &user.age) != 1)
                {
                    printf("Invalid input for age! Please enter a valid integer.\n");
                    while (getchar() != '\n')
                        ; // Clear invalid input
                }
                else
                {
                    validAge = 1; // Age is valid, exit the loop
                }
            }
        }
        // Write each user back to the temp file
        fprintf(temp_file, "%d\t%s\t%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp_file);

    if (exists)
    {
        remove("user_data.txt");                  // Delete the original file
        rename("temp_file.txt", "user_data.txt"); // Rename the temp file to original file
        printf("User updated successfully.\n");
    }
    else
    {
        remove("temp_file.txt");
        printf("No user found with ID %d.\n", id);
    }
}

void removeUser()
{
    int id, exists = 0;
    UserData user;
    FILE *file = fopen("user_data.txt", "r");
    FILE *temp_file = fopen("temp_file.txt", "w");

    if (file == NULL || temp_file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            exists = 1;
            continue; // Skip this user (effectively deleting them)
        }
        // Copy the user to the temp file if not the one to be deleted
        fprintf(temp_file, "%d\t%s\t%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp_file);

    if (exists)
    {
        remove("user_data.txt");                  // Delete the original file
        rename("temp_file.txt", "user_data.txt"); // Rename temp file to original file
        printf("User successfully deleted.\n");
    }
    else
    {
        remove("temp_file.txt");
        printf("No user exists with ID %d.\n", id);
    }
}

int main()
{
    FILE *file = fopen("user_data.txt", "r");
    if (file == NULL)
    {
        file = fopen("user_data.txt", "a");
        printf("File created successfully.\n");
    }
    fclose(file);

    int choice = 0;

    while (choice != 5)
    {

        printf("\n--- User Management Menu ---\n");
        printf("1. Add a New User\n");
        printf("2. View All Users\n");
        printf("3. Edit User Details\n");
        printf("4. Remove a User\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createNewUser();
            break;
        case 2:
            displayAllUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            removeUser();
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("\n Invalid choice! Please try again.\n");
        }
    }

    return 0;
}