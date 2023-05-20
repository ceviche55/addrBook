#include <iostream>
using namespace std;

int main() {
    int usrChoice;
    
    system("clear");
    cout << "Main Menu:" << endl;
    cout << "1. Display Contacts" << endl;
    cout << "2. Search Contacts" << endl;
    cout << "3. Create New Contact" << endl;
    cout << "4. Exit" << endl;
    cout << "Input Number Choice:\t";

    cin >> usrChoice;
    cout << endl;

//    while (true) {
        switch (usrChoice) {
            case 1:
                cout << "Display" << endl;
                break;
            case 2:
                cout << "Search" << endl;
                break;
            case 3:
                cout << "Create" << endl;
                break;
            case 4:
            default:
                cout << "Exit" << endl;
                break;
        }
//    }
}
