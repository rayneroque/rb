#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    char choice;
    int value;

    do {
        cout << "[A] Add Data to Queue" << endl;
        cout << "[B] Remove Data from Queue" << endl;
        cout << "[C] Show Front of Queue" << endl;
        cout << "[D] Show Queue Size" << endl;
        cout << "[E] Quit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a':
                cout << "Enter value to add: ";
                cin >> value;
                q.push(value);
                cout << value << " added to queue." << endl;
                break;
            case 'B':
            case 'b':
                if (!q.empty()) {
                    cout << q.front() << " removed from queue." << endl;
                    q.pop();
                } else {
                    cout << "Queue is empty. Cannot remove." << endl;
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
                cout << "Queue size: " << q.size() << endl;
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
