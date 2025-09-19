#include <iostream>
#include <string>
using namespace std;
int calculateFactorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return n*calculateFactorial(n-1);
    }
}
int main(){
    int num;
    cout<<"Enter the number you want the factorial of: ";
    cin>>num;
    int result = calculateFactorial(num);
    cout<<"Factorial of "<<num<<" is: "<<result<<endl;
    return 0;
}
