#include <iostream>
using namespace std;


string name;
bool name_value = false;

string getName() {
    while (!name_value) {
        cout << "What is your name: ";
        getline(cin, name);
        name_value = true;

        for (char c : name) {
            if (!isalnum(c) && !isspace(c)) {
                name_value = false;
                cout << "Invalid name!" << endl;
            }
        }
    }

    cout << "Welcome " << name << "!" << endl;
}


int main()
{
    enum choices {match = 1, display, giveup, exit};
    int size = 4;


    cout << "By: Tobi Akere" << endl;
    cout << "EUID: oaa0167" << endl;
    cout << "Email: tobiakere@my.unt.edu" << endl;
    cout << "--------------------------------------" << endl;



    return 0;
}
