#include <iostream>
#include <string>
using namespace std;

class Course {
    string courseName;
    float marks;

public:
    Course() {
        courseName = "";
        marks = 0;
    }

    void inputCourse() {
        cout << "Enter course name: ";
        cin >> courseName;
        cout << "Enter marks: ";
        cin >> marks;
    }

    float getMarks() {
        return marks;
    }

    string getCourseName() {
        return courseName;
    }
};

class Student {
    string name;
    string rollno;
    string university;
    int numCourses;
    Course* courses;

public:
    Student() {
        name = "";
        rollno = "";
        university = "";
        numCourses = 0;
        courses = nullptr;
    }

    void inputStudent() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter university: ";
        cin >> university;
        cout << "Enter number of courses: ";
        cin >> numCourses;

        courses = new Course[numCourses];

        for (int i = 0; i < numCourses; i++) {
            cout << "Course " << i + 1 << ":\n";
            courses[i].inputCourse();
        }
    }

    float calculateAverage() {
        float sum = 0;
        for (int i = 0; i < numCourses; i++) {
            sum += courses[i].getMarks();
        }
        return (numCourses > 0) ? (sum / numCourses) : 0;
    }

    void displayStudent() {
        cout << "\nStudent Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        cout << "University: " << university << endl;
        cout << "Courses and Marks:\n";
        for (int i = 0; i < numCourses; i++) {
            cout << "- " << courses[i].getCourseName() << ": " << courses[i].getMarks() << endl;
        }
        cout << "Average Marks: " << calculateAverage() << endl;
    }

    ~Student() {
        delete[] courses;
    }
};

int main() {
    int students;
    cout << "Enter number of students: ";
    cin >> students;

    Student* stu = new Student[students];

    for (int i = 0; i < students; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        stu[i].inputStudent();
    }

    cout << "\n----- Student Report -----\n";
    for (int i = 0; i < students; i++) {
        stu[i].displayStudent();
    }

    delete[] stu;
    return 0;
}

