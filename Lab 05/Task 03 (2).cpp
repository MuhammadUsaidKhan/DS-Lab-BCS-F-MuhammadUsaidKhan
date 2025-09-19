#include <iostream>
#include <string>
using namespace std;
int sumNonTail(int n){
    if(n==1){
        return 1;
    }
    else{
        return n + sumNonTail(n-1);
    }
}
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<sumNonTail(num);
    return 0;
}
