#include <iostream>
#include <string>
using namespace std;

int main()
{
    int departments;
    cout<<"Enter Number of Departmnets: ";
    cin>>departments;
    int** department;
    department = new int*[departments];
    int employees[departments];
    for(int i=0; i<departments; i++){
        cout<<"Enter number of employees in department "<<i+1<<": ";
        cin>>employees[i];
    }
    for(int i=0; i<departments; i++){
        department[i] = new int[employees[i]];
    }
    for(int i=0; i<departments; i++){
        cout<<"For Department "<<i+1<<": "<<endl;
        for(int j=0; j<employees[i]; j++){
            cin>>department[i][j];
        }
    }
    int highestSalary=0;
    float averageSalary;
    int total = 0;
    float maxAverageSalary =0;
    int maxAverageSalaryOfDepartment;
    for(int i=0; i<departments; i++){
        for(int j=0; j<employees[i]; j++){
            if(department[i][j]>highestSalary){
                highestSalary = department[i][j];
            }
        }
        cout<<"Highest Salary for Department "<<i+1<<": "<<highestSalary;
        cout<<endl;
        highestSalary = 0;
    }
    for(int i=0; i<departments; i++){
        for(int j=0; j<employees[i]; j++){
            total = total+department[i][j];
        }
        averageSalary = total/employees[i];
        if(averageSalary>maxAverageSalary){
            maxAverageSalary = averageSalary;
            maxAverageSalaryOfDepartment = i+1;
        }
        
    }
    cout<<"Max Average Salary is of Department "<<maxAverageSalaryOfDepartment<<endl;
    for(int i=0; i<departments; i++){
        delete[] department[i];
    }
        delete [] department;

    return 0;
}
