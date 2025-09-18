#include <iostream>
#include <string>
using namespace std;
void bubbleSort(int a[], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
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
    bubbleSort(intArray, size);
    cout<<"Sorted Array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<intArray[i]<<" ";
    }
    return 0;
}
