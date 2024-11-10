#include <iostream>
using namespace std;
int main() {
    string name;
    double salary;
    int rate;
    double bonus;

    // gets name
    cout << "what is your name: ";
    getline(cin, name);
    // gets salary
    cout << "what is your salary: ";
    cin >> salary;

    // gets rate of bonus
    cout << "what is your rate of bonus: ";
    cin >> rate;

    // check if rate is between 5 and 15
    if (rate < 5 || rate > 15) {
        cout << "invalid rate of bonus" << endl;
        return 1;  // Exit the program if rate is invalid
    }


    //calculate bonus
    bonus = salary * (static_cast<double>(rate) / 100);

    //convert 

    // print bonus
    cout << name << " earned a bonus of " << bonus; 

}