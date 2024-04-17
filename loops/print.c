#include <stdio.h>

int main(void)
{
    char user_letter;

    printf("Enter the capital letter to produce a pyramid: ");
    scanf("%c", &user_letter);

    int number_of_rows = user_letter - 'A' + 1;

    for (int rows = 0; rows < number_of_rows; rows++)
    {
        // Print spaces
        for (int space = 0; space < number_of_rows - rows - 1; space++)
            printf(" ");

        // Print letters in ascending order
        for (char current_letter = 'A'; current_letter <= 'A' + rows; current_letter++)
            printf("%c", current_letter);

        // Print letters in descending order
        for (char current_letter = 'A' + rows - 1; current_letter >= 'A'; current_letter--)
            printf("%c", current_letter);

        printf("\n");
    }

    return 0;
}