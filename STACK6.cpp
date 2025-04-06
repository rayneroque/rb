#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> s;
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    // Push each character of the string onto the stack
    for (char c : str) {
        s.push(c);
    }

    cout << "Reversed string: ";

    // Pop each character from the stack to reverse the string
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    cout << endl;
    return 0;
}
