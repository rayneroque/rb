#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> printQueue;
    string document;
    char choice;

    do {
        cout << "[A] Add Document to Print Queue" << endl;
        cout << "[B] Print Document" << endl;
        cout << "[C] Show Next Document to Print" << endl;
        cout << "[D] Show Queue Size" << endl;
        cout << "[E] Quit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a':
                cout << "Enter document name to add: ";
                cin >> document;
                printQueue.push(document);
                cout << document << " added to print queue." << endl;
                break;
            case 'B':
            case 'b':
                if (!printQueue.empty()) {
                    cout << "Printing " << printQueue.front() << endl;
                    printQueue.pop();
                } else {
                    cout << "Print queue is empty. Cannot print." << endl;
                }
                break;
            case 'C':
            case 'c':
                if (!printQueue.empty()) {
                    cout << "Next document to print: " << printQueue.front() << endl;
                } else {
                    cout << "Print queue is empty." << endl;
                }
                break;
            case 'D':
            case 'd':
                cout << "Print queue size: " << printQueue.size() << endl;
                break;
            case 'E':
            case 'e':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter A, B, C, D, or E." << endl;
        }

        cout << endl;
    } while (choice != 'E' && choice != 'e');

    return 0;
}
