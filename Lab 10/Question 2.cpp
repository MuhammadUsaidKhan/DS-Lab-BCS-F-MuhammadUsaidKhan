#include <iostream>
using namespace std;
//Function to check if array is a Max Heap?
bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n/2 - 1); i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[i] < arr[left])
            return false;
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
    }
}
int main() {
    int arr[] = {8, 7, 6, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isMaxHeap(arr, n))
        cout << "This array represents a Max Heap\n";
    else
        cout << "Not a Max Heap\n";
    heapSort(arr, n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
