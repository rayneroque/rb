#include <iostream>
using namespace std;

// Function to calculate retail price
double calculateRetailPrice(double wholesaleCost, double markupPercentage) {
    return wholesaleCost + (wholesaleCost * markupPercentage / 100);
}

int main() {
    double wholesaleCost, markupPercentage;

    // Ask for wholesale cost
    cout << "Enter the item's wholesale cost: ";
    cin >> wholesaleCost;

    // Ask for markup percentage
    cout << "Enter the item's markup percentage: ";
    cin >> markupPercentage;

    // Calculate retail price
    double retailPrice = calculateRetailPrice(wholesaleCost, markupPercentage);

    // Display retail price
    cout << "The item's retail price is: $" << retailPrice << endl;

    return 0;
}
