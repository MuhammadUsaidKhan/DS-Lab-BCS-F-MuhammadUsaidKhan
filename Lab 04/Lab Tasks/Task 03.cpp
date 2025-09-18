#include <iostream>
#include <string>
using namespace std;
void SelectionSort(int a[], int n){
    int i,j,k,temp;
    for(i=0; i<n; i++){
        for(j=k=i; j<n; j++){
            if(a[j]<a[k]){
                k=j;
            }
        }
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
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
    SelectionSort(intArray, size);
    cout<<"Sorted Array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<intArray[i]<<" ";
    }
    return 0;
}
