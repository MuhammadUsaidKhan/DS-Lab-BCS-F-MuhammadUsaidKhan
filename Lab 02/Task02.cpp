#include <iostream>
#include <string>
using namespace std;
int main() {
    int benches;
    int seats;
    cout<<"Enter Number of Benches: ";
    cin>>benches;
    cout<<"Enter Number of Seats in a Bench: ";
    cin>>seats;
    int **arr = new int*[benches];
    for(int i=0; i<benches; i++){
        arr[i] = new int[seats];
    }
    for(int i=0; i<benches; i++){
        for(int j=0; j<seats; j++){
            arr[i][j]=0;
        }
    }
    string change;
    
    do{
        cout<<"Do you want to update the seat(ocuupied or not?) in a bench?"<<endl;
        cin>>change;
        if(change=="Yes" || change=="yes"){
            int benchno;
            int s;
            int occupied;
            cout<<"Enter Bench Number: "<<endl;
            cin>>benchno;
            cout<<"Enter Seat Number: "<<endl;
            cin>>s;
            cout<<"Enter Occupied or not(1 for Occupied and 0 for Free)"<<endl;
            cin>>occupied;
            if(occupied==1||occupied==0){
                arr[benchno-1][s-1] = occupied;
            }
        }
    }while(change=="Yes" || change=="yes");
    for(int i=0; i<benches; i++){
        for(int j=0; j<seats; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
