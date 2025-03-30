#include<iostream>
using namespace std;
class Human{
    protected:
    string name;
    int age;
    int weight;
};
class Student:private Human{
    int roll_number;
    int fee;
    int sem;
    public:
    void get(string name, int age, int weight, int roll_number, int fee, int sem){
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_number = roll_number;
        this->fee = fee;
        this->sem = sem;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout <<"Age: "<<age<<endl;
        cout <<"Weight: "<<weight<<endl;
        cout <<"Roll Number "<<roll_number<<endl;
        cout <<"Fee: "<<roll_number<<endl;
        cout <<"Semester: "<<sem<<endl;
    }
};
class Teacher:private Human{
    int Sallary;
    int years_of_experience;
    string subject;
    public:
    void get(string name, int age, int weight, int Sallary, int years_of_experience, string subject){
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->Sallary = Sallary;
        this->years_of_experience = years_of_experience;
        this->subject = subject;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Sallary: "<<Sallary<<endl;
        cout<<"Year_Of Experience: "<<years_of_experience<<endl;
    }
};
int main(){
    Student s1;
    s1.get("Jayant",21,65,22,35000,6);
    s1.display();
    return 0;
}
