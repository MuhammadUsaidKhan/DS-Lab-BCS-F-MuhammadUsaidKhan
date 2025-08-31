#include <iostream>
#include <string>
using namespace std;
void searchBookID(int **arr,int bookid){
    
}
int main()
{
    int numCategory;
    int *numBooks;
    cout<<"Enter number of Categories: ";
    cin>>numCategory;
    int **library;
    library = new int*[numCategory];
    numBooks = new int[numCategory];
    for(int i=0; i<numCategory; i++){
        cout<<"Enter Number of Books in Category "<<i+1<<": ";
        cin>>numBooks[i];
    }
    for(int i=0; i<numCategory; i++){
        library[i] = new int[numBooks[i]];
    }
    for(int i=0; i<numCategory; i++){
        cout<<"Enter Book ids for Category "<<i+1<<endl;
        for(int j=0; j<numBooks[i]; j++){
            cin>>library[i][j];
        }
    }
    string search;
    int bookid;
    bool found = false;
    do{
    cout<<"Do you want to search a Book? ";
    cin>>search;
    if(search=="yes" || search=="Yes"){
        cout<<"Enter Book Id of book you want to search: ";
        cin>>bookid;
        for(int i=0; i<numCategory; i++){
            for(int j=0; j<numBooks[i]; j++){
                if(library[i][j]==bookid){
                    cout<<"Book is found and available in Category "<<i+1<<endl;
                    found = true;
                }
            }
        }
        if(found==false){
            cout<<"Book Not Found."<<endl;
        }
    }
    }while(search=="yes" || search=="Yes");
    for(int i=0; i<numCategory; i++){
        delete [] library[i]; 
    }
    delete [] numBooks;
    delete [] library;
    return 0;
}
