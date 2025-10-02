#include <iostream>
#include <string>
using namespace std;
int ackermann(int m, int n){
    if(m==0){
        return n+1;
    }
    if(m>0 && n==0){
        return ackermann(m-1, 1);
    }
    if(m>0 && n>0){
        return ackermann(m-1, ackermann(m, n-1));
    }
}
int main()
{
    int A;
    A = ackermann(1, 3);
    cout << A << endl;
    return 0;
}
