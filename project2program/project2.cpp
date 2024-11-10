#include <iostream>
#include <unistd.h>  // For sleep function
#include <cstdlib>   // For system function and random operations
#include <ctime>     // For random seeding
#include <string>

using namespace std;

const int SIZE = 4;
enum MenuOption { Match = 1, Display, Giveup, Exit };

int points = 50;
int cards[SIZE][SIZE];
int cardStatus[SIZE][SIZE]; // 0 = face down, 1 = face up

// Function to get the player's name
string getName() {
    string name;
    bool valid = false;
    while (!valid) {
        cout << "Enter your name: ";
        getline(cin, name);
        valid = true;
        for (char c : name) {
            if (!isalnum(c) && !isspace(c)) {
                valid = false;
                cout << "Error: Name can only contain letters, digits, and spaces.\n";
                break;
            }
        }
    }
    return name;
}

// Function to generate a random index for the 2D array
int genRandomIndex() {
    return rand() % SIZE;
}

// Function to shuffle the cards
void shuffle(int arr[SIZE][SIZE]) {
    for (int i = 0; i < 15; ++i) {
        int x1 = genRandomIndex(), y1 = genRandomIndex();
        int x2 = genRandomIndex(), y2 = genRandomIndex();
        swap(arr[x1][y1], arr[x2][y2]);
    }
}

// Function to initialize the card arrangement and status
void initialize() {
    int num = 1;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j += 2) {
            cards[i][j] = cards[i][j + 1] = num++;
        }
    }
    shuffle(cards);
    for (int i = 0; i < SIZE; ++i)
        fill(cardStatus[i], cardStatus[i] + SIZE, 0);
}

// Function to show the cards with an option to reveal all
void showCards(bool showReal = false) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (showReal || cardStatus[i][j] == 1) {
                cout << cards[i][j] << " ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

// Function to check if all cards are face up
bool allFaceUp() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (cardStatus[i][j] == 0) return false;
        }
    }
    return true;
}

// Function to check if input coordinates are valid
bool checkInputs(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && cardStatus[x][y] == 0;
}

// Function to handle matching two selected cards
void match(int& points) {
    int x1, y1, x2, y2;
    showCards();
    cout << "Enter coordinates of the first card (x y): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of the second card (x y): ";
    cin >> x2 >> y2;
    if (!checkInputs(x1, y1) || !checkInputs(x2, y2)) {
        cout << "Invalid coordinates or already face up.\n";
        return;
    }
    if (cards[x1][y1] == cards[x2][y2]) {
        cardStatus[x1][y1] = cardStatus[x2][y2] = 1;
        points += 5;
        cout << "Matched!\n";
    } else {
        points -= 1;
        cout << "No match. Try again.\n";
        sleep(5);
        system("clear");
    }
}

// Function to reveal an identical pair for a points penalty
void display(int& points) {
    if (points < 10) {
        cout << "Not enough points to display.\n";
        return;
    }
    points -= 10;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (cardStatus[i][j] == 0) {
                for (int m = 0; m < SIZE; ++m) {
                    for (int n = 0; n < SIZE; ++n) {
                        if ((i != m || j != n) && cards[i][j] == cards[m][n] && cardStatus[m][n] == 0) {
                            cardStatus[i][j] = cardStatus[m][n] = 1;
                            return;
                        }
                    }
                }
            }
        }
    }
}

// Main function to handle the game flow
int main() {
    srand(time(0));
    initialize();
    string playerName = getName();
    int choice;
    bool playing = true;

    cout << "Welcome, " << playerName << "! Let's play the Memory Matching Game.\n";

    while (playing && points > 0) {
        cout << "\n1. Match\n2. Display\n3. Give up\n4. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case Match: 
                match(points); 
                break;
            case Display: 
                display(points); 
                break;
            case Giveup: 
                showCards(true); 
                playing = false; 
                break;
            case Exit: 
                playing = false; 
                break;
            default: 
                cout << "Invalid choice. Try again.\n";
        }

        if (allFaceUp()) {
            cout << "Congratulations! You've matched all pairs!\n";
            playing = false;
        }
    }
    cout << "Goodbye " << playerName << ", your final score: " << points << endl;
    return 0;
}
