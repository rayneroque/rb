#include <iostream>

using namespace std;

int main() {
    int height = 6;  
    int width = 11; 
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j >= (width / 2 - i) && j <= (width / 2 + i)) {
                cout << "#";  
            } else {
                cout << " ";  
            }
        }
        cout << endl;
    }

    for (int i = 0; i < height - 2; i++) {  
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout << "|";  
            } else if (i == height - 3 && j == width / 2) {
                cout << "*";  
            } else {
                cout << " ";  
            }
        }
        cout << endl;
    }

  
    for (int i = 0; i < width; i++) {
        cout << "_";
    }
    cout << endl;

    return 0;
}
