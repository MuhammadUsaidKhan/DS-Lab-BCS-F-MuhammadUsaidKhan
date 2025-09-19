#include <iostream>
#include <string>
using namespace std;
void functionB(int n);
void functionA(int n){
    if(n==1){
        cout<<n;
    }
    else{
        cout<<n<<" ";
        functionB(n-1);
    }
}
void functionB(int n){
    if(n==1){
        cout<<n;
    }
    else{
        cout<<n<<" ";
        functionA(n-1);
    }
}
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    functionA(num);
    return 0;
}
