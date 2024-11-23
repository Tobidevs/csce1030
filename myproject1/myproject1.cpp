#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int points = 50;
    enum choices {add = 1, subtract, display, giveup, exit};
    string name;

    cout << "By: Tobi Akere" << endl;
    cout << "EUID: oaa0167" << endl;
    cout << "Email: tobiakere@my.unt.edu" << endl;
    cout << "--------------------------------------" << endl;

    // Get Name from user
    bool name_value = false;
    while (!name_value) {
        cout << "What is your name: ";
        getline(cin, name);
        name_value = true;

        for (char c : name) {
            if (!isalnum(c) && !isspace(c)) {
                name_value = false;
                cout << "Invalid name!" << endl;
                break;
            }
        }
    }

    cout << "Welcome " << name << "!" << endl;

    srand(time(0)); // Seed random generator
    bool play_again = true;

    while (play_again && points > 0) {
        // Generate random numbers
        int num1 = 50 + rand() % 51;
        int num2 = 50 + rand() % 51;

        while (num1 >= num2) {
            num1 = 50 + rand() % 51;
            num2 = 50 + rand() % 51;
        }

        cout << "Your two random numbers have been generated." << endl;

        // Menu choice
        cout << "What would you like to do? Enter corresponding number." << endl;
        cout << "1. ADD\n2. SUBTRACT\n3. DISPLAY\n4. GIVEUP\n5. EXIT" << endl;

        int choice;
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case add: {
                int guessed_sum;
                int sum_of_random = num1 + num2;
                cout << "Guess the sum of the two numbers: ";
                cin >> guessed_sum;

                if (abs(sum_of_random - guessed_sum) < 5) {
                    points += 5;
                    cout << "Correct! You now have " << points << " points." << endl;
                } else {
                    points -= 5;
                    cout << "Incorrect! You now have " << points << " points." << endl;
                }
                break;
            }
            case subtract: {
                int guessed_diff;
                int diff_of_random = num2 - num1;
                cout << "Guess the difference of the two numbers: ";
                cin >> guessed_diff;

                if (abs(diff_of_random - guessed_diff) < 5) {
                    points += 5;
                    cout << "Correct! You now have " << points << " points." << endl;
                } else {
                    points -= 5;
                    cout << "Incorrect! You now have " << points << " points." << endl;
                }
                break;
            }
            case display: {
                points -= 3;
                cout << "The first random number is " << num1 << "." << endl;
                break;
            }
            case giveup: {
                cout << "The two random numbers were " << num1 << " and " << num2 << "." << endl;
                play_again = false;
                break;
            }
            case exit: {
                cout << name << ", your final points are " << points << "." << endl;
                play_again = false;
                break;
            }
            default:
                cout << "Invalid response!" << endl;
                break;
        }

        if (points <= 0) {
            cout << "Game over! You have run out of points." << endl;
            break;
        }

        char play_again_char;
        while (true) {
            cout << "Do you want to play again? (y/n): ";
            cin >> play_again_char;
            if (play_again_char == 'y') {
                play_again = true;
                break;
            } else if (play_again_char == 'n') {
                play_again = false;
                break;
            } else {
                cout << "Invalid response! Please enter 'y' or 'n'.\n";
            }
        }
    }

    return 0;

    
}