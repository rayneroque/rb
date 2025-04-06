#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function for Linear Search
int linearSearch(const vector<int>& arr, int value, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < arr.size(); ++i) {
        ++comparisons;
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function for Binary Search
int binarySearch(const vector<int>& arr, int value, int& comparisons) {
    comparisons = 0;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        ++comparisons;
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Function for Interpolation Search
int interpolationSearch(const vector<int>& arr, int value, int& comparisons) {
    comparisons = 0;
    int low = 0, high = arr.size() - 1;
    while (low <= high && value >= arr[low] && value <= arr[high]) {
        if (low == high) {
            ++comparisons;
            if (arr[low] == value) return low;
            return -1;
        }
        ++comparisons;
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (value - arr[low]);
        if (arr[pos] == value) {
            return pos;
        }
        if (arr[pos] < value) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

// Function for Jump Search
int jumpSearch(const vector<int>& arr, int value, int& comparisons) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;
    comparisons = 0;
    while (arr[min(step, n) - 1] < value) {
        ++comparisons;
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    while (arr[prev] < value) {
        ++comparisons;
        ++prev;
        if (prev == min(step, n)) return -1;
    }
    ++comparisons;
    if (arr[prev] == value) return prev;
    return -1;
}

int main() {
    int N, value, choice;
    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the elements: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cout << "Enter value to search: ";
    cin >> value;

    cout << "Choose searching algorithm:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "3. Interpolation Search" << endl;
    cout << "4. Jump Search" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    int comparisons = 0;
    int index = -1;

    switch (choice) {
        case 1:
            index = linearSearch(arr, value, comparisons);
            break;
        case 2:
            sort(arr.begin(), arr.end()); // Ensure the array is sorted for binary search
            index = binarySearch(arr, value, comparisons);
            break;
        case 3:
            sort(arr.begin(), arr.end()); // Ensure the array is sorted for interpolation search
            index = interpolationSearch(arr, value, comparisons);
            break;
        case 4:
            sort(arr.begin(), arr.end()); // Ensure the array is sorted for jump search
            index = jumpSearch(arr, value, comparisons);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    if (index != -1) {
        cout << "Value found at index: " << index << endl;
    } else {
        cout << "Value not found in the array." << endl;
    }

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
