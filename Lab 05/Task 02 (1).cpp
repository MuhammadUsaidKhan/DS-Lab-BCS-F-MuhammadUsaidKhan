#include <iostream>
#include <string>
using namespace std;
void printNumbers(int n){
    if(n==1){
        cout<<n;
    }
    else{
        cout<<n<<" ";
        printNumbers(n-1);
    }
}
int main(){
    int num;
    cout<<"Enter the number you want the factorial of: ";
    cin>>num;
    printNumbers(num);
    return 0;
}
