#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>

using namespace std;

int main() {
    // 1. Display user info
    cout << "Name: John Doe" << endl;
    cout << "EUID: jdoe123" << endl;
    cout << "Email: jdoe123@unt.      edu" << endl;
    cout << "Department: Computer Science" << endl;
    cout << "Course: CSCE 1030" << endl;

    // 2. Declare and initialize points
    int points = 50;

    // 3. Define menu choices using enum
    enum MenuOptions { ADD = 1, SUBTRACT, DISPLAY, GIVEUP, EXIT };

    // 4. Ask for username
    string username;
    bool validName = false;
    while (!validName) {
        cout << "Enter your username (only letters, digits, and spaces): ";
        getline(cin, username);

        validName = true;
        for (char c : username) {
            if (!isalnum(c) && !isspace(c)) {
                validName = false;
                cout << "Invalid characters found in username. Please try again." << endl;
                break;
            }
        }
    }

    // Welcome message
    cout << "Welcome to the game, " << username << "!" << endl;

    // 5. Initialize random number generator
    srand(time(0));

    bool play = true; // Controls the main loop of the game
    bool displayFirstNumber = false; // Flag to check if the first number was displayed
    while (play && points > 0) {
        // 6. Generate two random numbers
        int num1, num2;
        do {
            num1 = rand() % 51 + 50; // Random number between 50 and 100
            num2 = rand() % 51 + 50;
        } while (num1 >= num2); // Ensure num1 < num2

        // 7. Present menu options
        cout << "\nMenu: " << endl;
        cout << "1. Guess the sum of two numbers" << endl;
        cout << "2. Guess the difference between two numbers" << endl;
        cout << "3. Display the first number" << endl;
        cout << "4. Give up" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case ADD: {
                // Guess the sum
                int guess;
                cout << "Guess the sum of the two numbers: ";
                cin >> guess;
                int actualSum = num1 + num2;
                if (abs(actualSum - guess) < 5) {
                    points += 5;
                    cout << "Correct! Your points: " << points << endl;
                } else {
                    points--;
                    cout << "Incorrect! The sum was: " << actualSum << ". Your points: " << points << endl;
                }
                break;
            }
            case SUBTRACT: {
                // Guess the difference
                int guess;
                cout << "Guess the difference between the two numbers: ";
                cin >> guess;
                int actualDiff = abs(num2 - num1);
                if (abs(actualDiff - guess) < 5) {
                    points += 5;
                    cout << "Correct! Your points: " << points << endl;
                } else {
                    points--;
                    cout << "Incorrect! The difference was: " << actualDiff << ". Your points: " << points << endl;
                }
                break;
            }
            case DISPLAY: {
                if (!displayFirstNumber) {
                    points -= 3;
                    displayFirstNumber = true;
                    cout << "The first number is: " << num1 << ". Your points: " << points << endl;
                } else {
                    cout << "You have already displayed the first number!" << endl;
                }
                break;
            }
            case GIVEUP: {
                cout << "The numbers were " << num1 << " and " << num2 << "." << endl;
                break;
            }
            case EXIT: {
                play = false;
                cout << "Goodbye, " << username << "! Your final points: " << points << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        if (points <= 0) {
            cout << "Game over! You have no points left." << endl;
            play = false;
        }
    }

    return 0;
}
