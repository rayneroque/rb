#include <iostream>
#include <stack>
using namespace std;

void showMenu() {
    cout << "[A] Push Data" << endl;
    cout << "[B] Pop Data" << endl;
    cout << "[C] Show Top" << endl;
    cout << "[D] Show Size" << endl;
    cout << "[E] Quit" << endl;
    cout << "Enter Choice: ";
}

int main() {
    stack<int> s;
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
                s.push(value);
                cout << value << " pushed to stack." << endl;
                break;
            case 'B':
            case 'b':
                if (!s.empty()) {
                    cout << s.top() << " popped from stack." << endl;
                    s.pop();
                } else {
                    cout << "Stack is empty. Cannot pop." << endl;
                }
                break;
            case 'C':
            case 'c':
                if (!s.empty()) {
                    cout << "Top of stack: " << s.top() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 'D':
            case 'd':
                cout << "Size of stack: " << s.size() << endl;
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
