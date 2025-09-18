#include <iostream>
#include <string>
using namespace std;
void InsertionSort(int a[], int n){
    int i,j,x;
    for(i=1; i<n; i++){
        j=i-1;
        x=a[i];
        while(j>-1 && a[j]>x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size-1;
    bool found = false;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target){
            found = true;
            return mid;
        }
        if (arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int size;
    cout<<"Enter size of AN array: ";
    cin>>size;
    int *intArray = new int[size];
    for(int i=0; i<size; i++){
        cin>>intArray[i];
    }
    cout<<"Unsorted Array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<intArray[i]<<" ";
    }
    cout<<endl;
    InsertionSort(intArray, size);
    cout<<"Sorted Array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<intArray[i]<<" ";
    }
    cout<<endl;
    int targetValue;
    cout<<"Enter Value you want to find: ";
    cin>>targetValue;
    int result = binarySearch(intArray, size, targetValue);
    if(result == -1){
        cout<<"Element Not Found."<<endl;
    }
    else{
        cout<<"Element Found at Index: "<<result<<endl;
    }
    return 0;
}
