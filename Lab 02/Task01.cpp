#include <iostream>
#include <string>
using namespace std;
int main() {
    int size;
    cout<<"Enter Size of an array: "<<endl;
    cin>>size;
    int *arr;
    arr = new int[size];
    int i;
    string change;
    for(int i=0; i<size; i++){
        arr[i]=0;
    }
    do{
        cout<<"Do want to update the array: "<<endl;
        cin>>change;
        if(change=="Yes" || change=="yes"){
        int index;
        cout<<"Enter Index at which you want to change value: "<<endl;
        cin>>index;
        if(index>=0 && index<size){
            cout<<"Enter Value: "<<endl;
            cin>>arr[index];
        }
        }
    }while(change=="Yes" || change=="yes");
    for(i=0; i<size; i++){
        cout<<"Value of array at Index "<<i<<" is: "<<arr[i]<<endl;
    }
    delete [] arr;
    return 0;
}
