#include <iostream>
#include <string>
using namespace std;
int InterpolationSearch(int a[], int n, int key){
    int low=0;
    int high = n-1;
    while(low<=high && key>= a[low] && key<=a[high]){
        if(low == high){
            if(a[low]==key){
                return low;
            }
            return -1;
        }
        int pos = low + ((key - a[low]) * (high-low))/(a[high] - a[low]);
        if(a[pos] == key){
            return pos;
        }
        if(a[pos]<key){
            low = pos+1;
        }
        else{
            high = pos-1;
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
    cout<<"Sorted Array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<intArray[i]<<" ";
    }
    cout<<endl;
    int targetValue;
    cout<<"Enter Value you want to find: ";
    cin>>targetValue;
    int result = InterpolationSearch(intArray, size, targetValue);
    if(result == -1){
        cout<<"Element not found."<<endl;
    }
    else{
        cout<<"Value Found at index: "<<result<<endl;
    }
    cout<<endl;
    
    return 0;
}
