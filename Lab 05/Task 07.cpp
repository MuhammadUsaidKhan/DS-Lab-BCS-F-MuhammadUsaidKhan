#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
bool valid(int k, int l, int x[]){
    for(int i=1; i<k; i++){
        if(x[i]==l || abs(i-k)==abs(x[i]-l)){
            return false;
        }
    }
    return true;
}
void NQueens(int k, int n, int x[]){
    for(int i=1; i<=n; i++){
        if(valid(k,i, x)){
            x[k] = i;
            if(k==n){
                for(int j=1; j<=n; j++){
                    cout<<x[j]<<" ";
                }
                cout<<endl;
            }
            else{
                NQueens(k+1, n, x);
            }
        }
    }
}
int main()
{
    int numberOfQueens;
    cout<<"Enter Number of Queens: ";
    cin>>numberOfQueens;
    if (numberOfQueens < 1) {
        cout << "Number of Queens must be at least 1." << endl;
        return 1;
    }
    int* arr = new int[numberOfQueens + 1]; 
    NQueens(1, numberOfQueens, arr);
    delete[] arr;
}
