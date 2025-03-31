#include<iostream>
using namespace std;
class student{
    private:
    string name;
    int age;
    int rollno;
    public:
    void setname(string n){
        if(n.size()==0){
            cout << "invalid Name"<<endl;
        }
        name = n;
    }
     void setage(int a){
        int age = a;
     }
    void setrollno(int r){
        int rollno = r;
    }
    void getname(){
        cout << name <<endl;
    }
    void getage(){
        cout << age <<endl;
    }
    void getrollno(){
        cout << rollno <<endl;
    }
};
int main(){
    student s1;
    s1.setname("Jauant");
    s1.setage(21);
    s1.setrollno(22);
    s1.getname();
    return 0;
}
