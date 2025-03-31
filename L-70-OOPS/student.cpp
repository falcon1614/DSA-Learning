#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int age;
    int roll_number;
    string grade;
};
int main(){
    Student s1;
    s1.name = "Jayant";
    s1.age = 21;
    s1.roll_number = 22;
    s1.grade = "A+";
    cout << s1.name << " ";
}
