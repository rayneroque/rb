#include <iostream>
#include <vector>
using namespace std;

// Function for Bubble Sort
void bubbleSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    comparisons = swaps = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            ++comparisons;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++swaps;
            }
        }
    }
}

// Function for Insertion Sort
void insertionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    comparisons = swaps = 0;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        ++comparisons;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            ++comparisons;
            ++swaps;
        }
        arr[j + 1] = key;
        ++swaps;
    }
}

// Function for Selection Sort
void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    comparisons = swaps = 0;
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            ++comparisons;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
        ++swaps;
    }
}

// Helper function for Merge Sort to merge two halves
void merge(vector<int>& arr, int left, int mid, int right, int& comparisons, int& swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        ++comparisons;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
        ++swaps;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        ++swaps;
    }
}

// Function for Merge Sort
void mergeSort(vector<int>& arr, int left, int right, int& comparisons, int& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

// Main function to demonstrate sorting algorithms
int main() {
    int N, choice;
    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the elements: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cout << "Choose sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    int comparisons = 0, swaps = 0;
    vector<int> sortedArr = arr;

    switch (choice) {
        case 1:
            bubbleSort(sortedArr, comparisons, swaps);
            break;
        case 2:
            insertionSort(sortedArr, comparisons, swaps);
            break;
        case 3:
            selectionSort(sortedArr, comparisons, swaps);
            break;
        case 4:
            mergeSort(sortedArr, 0, N - 1, comparisons, swaps);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;

    return 0;
}
