#include <iostream>
#include <string>
using namespace std;
int sumTail(int n, int total){
    if(n==0){
        return total;
    }
    else{
        total = total + n;
        return sumTail(n-1, total);
    }
}
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<sumTail(num ,0);
    return 0;
}
