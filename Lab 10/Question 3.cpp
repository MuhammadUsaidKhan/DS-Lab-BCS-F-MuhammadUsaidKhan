#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int largest = i;          
    int left = 2 * i + 1;     
    int right = 2 * i + 2;    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
int kthLargest(int arr[], int n, int k) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= n - k + 1; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
    return arr[0];
}
int main() {
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int K1 = 3;
    cout << "Kth largest: " << kthLargest(arr1, n1, K1) << endl;
    int arr2[] = {12, 3, 5, 7, 19};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int K2 = 2;
    cout << "Kth largest: " << kthLargest(arr2, n2, K2) << endl;
    return 0;
}
