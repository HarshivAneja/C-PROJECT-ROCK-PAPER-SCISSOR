#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement the game
int game(char you, char computer) {
    if (you == computer)
        return 0;  // Draw

    if ((you == 's' && computer == 'p') ||
        (you == 'p' && computer == 'z') ||
        (you == 'z' && computer == 's'))
        return 1;  // You win

    return -1;  // Computer wins
}

// Function to get user input
char getUserChoice() {
    char choice;
    printf("Enter 's' for STONE, 'p' for PAPER, or 'z' for SCISSOR: ");
    scanf(" %c", &choice); // Add space before %c to consume whitespace (newline) left in the input buffer
    return choice;
}

int main() {
    int n;
    char you, computer;
    int result;

    srand(time(NULL));
    n = rand() % 3;  // Generate a random number between 0 and 2

    if (n == 0)
        computer = 's';
    else if (n == 1)
        computer = 'p';
    else
        computer = 'z';

    you = getUserChoice();  // Get user input

    result = game(you, computer);

    if (result == 0) {
        printf("Game Draw!\n");
    } else if (result == 1) {
        printf("You have won the game!\n");
    } else {
        printf("You have lost the game!\n");
    }

    printf("You chose: %c and Computer chose: %c\n", you, computer);

    return 0;
}

