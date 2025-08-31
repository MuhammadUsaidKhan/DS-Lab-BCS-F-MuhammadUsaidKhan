#include <iostream>
#include <string>
using namespace std;
int** Matrice(int rows, int columns){
    int **row;
    row = new int*[rows];
    for(int i=0; i<rows; i++){
        row[i] = new int[columns];
    }
    for(int i=0; i<rows; i++){
        cout<<"Enter Numbers in Row "<<i+1<<endl;
        for(int j=0; j<columns; j++){
            cin>>row[i][j];
        }
    }
    return row;
}
int** additionMatrice(int** matrice1, int** matrice2, int rows, int columns){
    int** newarr;
    newarr = new int*[rows];
    for(int i=0;i<rows; i++){
        newarr[i] = new int[columns];
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            newarr[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
    return newarr;
}
int** substractionMatrice(int** matrice1, int** matrice2, int rows, int columns){
    int** newarr;
    newarr = new int*[rows];
    for(int i=0;i<rows; i++){
        newarr[i] = new int[columns];
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            newarr[i][j] = matrice1[i][j] - matrice2[i][j];
        }
    }
    return newarr;
}
int main()
{
    //Assuming both matrices have same number of rows and columns
    int rows,columns;
    cout<<"Enter Number of Rows: ";
    cin>>rows;
    cout<<"Enter Number of Columns: ";
    cin>>columns;
    int** matrice1;
    cout<<"For Matrice 1: "<<endl;
    matrice1 = Matrice(rows,columns);
    int** matrice2;
    cout<<"For Matrice 2: "<<endl;
    matrice2 = Matrice(rows,columns);
    int** addMatrice = additionMatrice(matrice1, matrice2, rows, columns);
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<addMatrice[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int** subMatrice = substractionMatrice(matrice1, matrice2, rows, columns);
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<subMatrice[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<rows; i++){
        delete [] matrice1[i];
    }
    delete [] matrice1;
    for(int i=0; i<rows; i++){
        delete [] matrice2[i];
    }
    delete [] matrice2;
    for(int i=0; i<rows; i++){
        delete [] addMatrice[i];
    }
    delete [] addMatrice;
    for(int i=0; i<rows; i++){
        delete [] subMatrice[i];
    }
    delete [] subMatrice;
    return 0;
}
