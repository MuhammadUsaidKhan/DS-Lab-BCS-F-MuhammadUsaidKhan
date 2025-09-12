#include <iostream>
#include <string>
using namespace std;
//Assuming Employee Id's and Roll Number consist of two integer digits.
// Employee Array is in Ascending Order.
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
    cout<<"Enter the Number of Employee ID's in the array: ";
    cin>>size;
    int *Employees = new int[size];
    for(int i=0; i<size; i++){
        cout<<"Enter Employee ID at Index "<<i<<": ";
        cin>>Employees[i];
    }
    int targetValue;
    cout<<"Enter Target Value: ";
    cin>>targetValue;
    int *temp;
    temp = new int[size+1];
    int j=0;
    if(binarySearch(Employees, size, targetValue) == -1){
        for(int i=0; i<size; i++){
            temp[i] = Employees[i];
            temp[size] = 0;
        }
        for(int i=0; i<size; i++){
            if(targetValue> temp[i]){
                j=i;
            }
        }
        for(int i=size; i>j; i--){
            temp[i] = temp[i-1];
        }
        temp[j+1] = targetValue;
    }
    for(int i=0; i<size+1; i++){
        cout<<temp[i]<<endl;
    }
    delete [] Employees;
    delete [] temp;
    return 0;
}
