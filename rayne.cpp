#include <iostream>

using namespace std;

int main() {
    int height = 6;  // Height of the house
    int width = 11;  // Width of the house (it should be an odd number for symmetry)
    
    // Roof of the house (triangular shape)
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j >= (width / 2 - i) && j <= (width / 2 + i)) {
                cout << "#";  // Part of the roof made of '#'
            } else {
                cout << " ";  // Space to create the triangle shape
            }
        }
        cout << endl;
    }

    // Walls of the house
    for (int i = 0; i < height - 2; i++) {  // Height of the walls (height - roof)
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout << "|";  // Left and right walls of the house
            } else if (i == height - 3 && j == width / 2) {
                cout << "*";  // Door in the middle of the house
            } else {
                cout << " ";  // Inside the house (empty space)
            }
        }
        cout << endl;
    }

    // Base of the house (foundation)
    for (int i = 0; i < width; i++) {
        cout << "_";  // Foundation of the house
    }
    cout << endl;

    return 0;
}
