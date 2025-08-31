#include <iostream>
#include <string>
using namespace std;

int main()
{
    int days, timings;
    cout<<"Enter number of days you want to record Temperature: ";
    cin>>days;
    cout<<"Enter number of times you want to record Temperature in a day: ";
    cin>>timings;
    float **city;
    city = new float*[days];
    for(int i=0; i<days; i++){
        city[i] = new float[timings];
    }
    for(int i=0; i<days; i++){
        cout<<"Enter Temperature for Day "<<i+1<<" :"<<endl;
        for(int j=0; j<timings; j++){
            cin>>city[i][j];
        }
    }
    float averageTemperatureOfDay;
    float total=0;
    float hottestDay=0;
    float coldestDay = 100;
    int hottest, coldest;
    for(int i=0; i<days; i++){
        for(int j=0; j<timings; j++){
            total = total + city[i][j];
        }
        averageTemperatureOfDay = total/timings;
        cout<<"Averge for Day "<<i+1<<" is: "<<averageTemperatureOfDay<<endl;
        total=0;
        if(averageTemperatureOfDay<coldestDay){
            coldestDay=averageTemperatureOfDay;
            coldest=i+1;
        }
        if(averageTemperatureOfDay>hottestDay){
            hottestDay = averageTemperatureOfDay;
            hottest = i+1;
        }
    }
    cout<<"Hottest Day is Day "<<hottest<<endl;
    cout<<"Coldest Day is Day "<<coldest<<endl;
    return 0;
}
