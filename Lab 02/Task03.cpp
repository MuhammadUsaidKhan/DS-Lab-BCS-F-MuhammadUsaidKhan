#include <iostream>
#include <string>
using namespace std;
class Course{
    string courseName;
    float marks;
    public:
    Course(){
        courseName = "";
        marks =0;
    }
    Course(string cn, float m){
        courseName = cn;
        marks= m;
    }
};
class Student{
    string name;
    string rollno;
    string university;
    int numCourses;
    Course* courses;
    public:
    Student(){
        name="";
        rollno="";
        university="";
        courses = 0;
    }
    Student(string n, string rn, string u, int c){
        name = n;
        rollno = rn;
        university = u;
        courses = new Course[numCourses];
    }
};
int main() {
    int students;
    cout<<"Enter Number Of Students: "<<endl;
    cin>>students;
    Student *stu;
    stu = new Student[students];
    int size[students];
    for(int i=0; i<students; i++){
        cout<<"Enter Number of Courses of Student: "<<endl;
        cin>>size[i];
        stu = new Student[size[i]];
    }
    
    
    return 0;
}
