#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    // Seed for random number generation
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int playerGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Loop until the player guesses the correct number
    do {
        cout << "Enter your guess: ";
        
        // Check if the input is a valid number
        if (!(cin >> playerGuess)) {
            // If input is not a valid number, show error message and clear the error state
            cout << "Invalid input! Please enter a valid number." << endl;

            // Clear error state and ignore any remaining characters in the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Skip the rest of the loop and ask for input again
        }

        attempts++;

        // Check the player's guess and provide feedback
        if (playerGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (playerGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
            cout << "It took you " << attempts << " attempts." << endl;
        }

    } while (playerGuess != randomNumber); // Continue the loop until the guess is correct

    return 0;
}
