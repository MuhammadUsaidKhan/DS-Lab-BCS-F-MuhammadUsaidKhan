#include <iostream>
#include <string>
using namespace std;
int main() {
    int rows,columns;
    cout<<"Enter number of Rows: ";
    cin>>rows;
    cout<<"Enter number of Columns: ";
    cin>>columns;
    int **sparseMatrix;
    sparseMatrix = new int*[rows];
    for(int i=0; i<rows; i++){
        sparseMatrix[i] = new int[columns];
    }
    for(int i=0; i<rows; i++){
        cout<<"Enter Elements in Row "<<i+1<<": "<<endl;
        for(int j=0; j<columns; j++){
            cin>>sparseMatrix[i][j];
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<sparseMatrix[i][j];
        }
        cout<<endl;
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(sparseMatrix[i][j]!=0){
                cout<<"Value "<<sparseMatrix[i][j]<<" found in Row "<<i+1<<" and column "<<j+1<<endl;
            }
        }
    }
    for(int i=0; i<rows; i++){
        delete [] sparseMatrix[i];
    }
    delete [] sparseMatrix;
    return 0;
}
}
