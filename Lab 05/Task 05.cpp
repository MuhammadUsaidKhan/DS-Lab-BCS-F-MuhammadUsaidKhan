#include <iostream>
using namespace std;
bool isValid(int r, int c, int val, int s[9][9]){
    for(int i=0; i<9; i++){
        if(s[r][i]==val||s[i][c]==val){
            return false;
        }
    }
    int blockRow = r-r%3;
    int blockCol = c-c%3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(s[blockRow+i][blockCol+j]==val){
                return false;
            }
        }
    }
    return true;
}
void Sudoku(int r, int c, int s[9][9]){
    if(r==9){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<s[i][j]<<" ";
            }
            cout<<endl;
        } 
        return;
    }
    else{
        if(s[r][c]!=0){
            Sudoku(c==8?r+1:r, c==8?0:c+1, s);
        }
        else{
            for(int i=1; i<=9; i++){
                if(isValid(r, c, i, s)){
                    s[r][c] = i;
                    Sudoku(c==8?r+1:r, c==8?0:c+1, s);
                    s[r][c] = 0;
                }
            }
        }
    }
}

int main() {
    int board[9][9] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},
        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},
        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };
    Sudoku(0,0, board);
    return 0;
}
