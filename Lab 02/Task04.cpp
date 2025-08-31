#include <iostream>
#include <string>
using namespace std;
double* resizeArray(double* oldarr, int oldsize, int newsize){
    if(newsize==oldsize){
        return oldarr;
    }
    double *newarr;
    newarr = new double[newsize];
    int limit;
    if(oldsize<newsize){
        limit = oldsize;
    }
    else{
        limit = newsize;
    }
    for(int i=0; i<limit; i++){
        newarr[i] = oldarr[i];
    }
    delete [] oldarr;
    return newarr;
}
int main()
{
    int numMonths;
    cout<<"Enter Number of Months you want to store expenses: ";
    cin>>numMonths;
    double *month = new double[numMonths];
    for(int i=0; i<numMonths; i++){
        cout<<"Enter Expense for Month "<<i+1<<": ";
        cin>>month[i];
    }
    string change;
    double total=0;
    double average;
    cout<<"Do you want to add more months: ";
    cin>>change;
    if(change == "yes" || change == "Yes"){
        int newSize;
        cout<<"Enter new Number of Months: ";
        cin>>newSize;
        month = resizeArray(month, numMonths, newSize);
        for(int i=numMonths; i<newSize; i++){
            cout<<"Enter Expense for Month "<<i+1<<": ";
            cin>>month[i];
        }
        for(int i=0; i<newSize; i++){
            total = total + month[i];
        }
        average = total/newSize;
        cout<<"Totl Expenses for "<<newSize<<" months are: "<<total<<endl;
        cout<<"Average Expending is for "<<newSize<<" is: "<<average<<endl;
        
    }
    else{
        for(int i=0; i<numMonths; i++){
            total = total + month[i];
        }
        average = total/numMonths;
        cout<<"Totl Expenses for "<<numMonths<<" months are: "<<total<<endl;
        cout<<"Average Expending is for "<<numMonths<<" is: "<<average<<endl;
    }
    delete [] month;
    return 0;
}
