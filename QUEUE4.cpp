#include <iostream>
#include <queue>
using namespace std;

void showMenu() {
    cout << "[A] Push Data" << endl;
    cout << "[B] Pop Data" << endl;
    cout << "[C] Show Front" << endl;
    cout << "[D] Show Back" << endl;
    cout << "[E] Show Size" << endl;
    cout << "[F] Quit" << endl;
    cout << "Enter Choice: ";
}

int main() {
    queue<int> q;
    char choice;
    int value;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a':
                cout << "Enter value to push: ";
                cin >> value;
                q.push(value);
                cout << value << " pushed to queue." << endl;
                break;
            case 'B':
            case 'b':
                if (!q.empty()) {
                    cout << q.front() << " popped from queue." << endl;
                    q.pop();
                } else {
                    cout << "Queue is empty. Cannot pop." << endl;
                }
                break;
            case 'C':
            case 'c':
                if (!q.empty()) {
                    cout << "Front of queue: " << q.front() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 'D':
            case 'd':
                if (!q.empty()) {
                    cout << "Back of queue: " << q.back() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 'E':
            case 'e':
                cout << "Size of queue: " << q.size() << endl;
                break;
            case 'F':
            case 'f':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter A, B, C, D, E, or F." << endl;
        }

        cout << endl;
    } while (choice != 'F' && choice != 'f');

    return 0;
}
