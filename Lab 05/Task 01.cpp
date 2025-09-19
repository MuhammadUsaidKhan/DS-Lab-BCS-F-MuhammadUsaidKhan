#include <iostream>
#include <string>
using namespace std;
int factorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int main(){
    int num;
    cout<<"Enter the number you want the factorial of: ";
    cin>>num;
    int result = factorial(num);
    cout<<"Factorial of "<<num<<" is: "<<result<<endl;
    return 0;
}
