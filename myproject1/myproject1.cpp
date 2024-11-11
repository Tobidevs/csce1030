#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int points = 50;
    enum choices {add, subtract, display, giveup, exit};
    string name;

    cout << "By: Tobi Akere" << endl;
    cout << "EUID: oaa0167" << endl;
    cout << "Email: tobiakere@my.unt.edu" << endl;
    cout << "--------------------------------------" << endl;

    // Get Name from user
    bool name_value = false;

    while (!name_value) {
        cout << "What is your name: " << endl;
        getline(cin, name);
        name_value = true;

        for (char c : name) {
            if (isalnum(c) || isspace(c)) {
                name_value = false;
                cout << "Invalid name!" << endl;
            }
        }
    }

    
}