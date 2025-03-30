#include<iostream>
using namespace std;
class Engineer{
    public:
    string specilazation;
    void work(){
        cout<<"Engineer is working"<<specilazation<<endl;
    }
};
class youtube{
    public:
    int subscriber;
    void creater(){
        cout<<"YouTuber is creating"<<subscriber<<"subscriber"<<endl;
    }
};
class codeTeacher:public Engineer, public youtube{
    public:
    string name;
    void codeTeacher(string name, string specilazation, int subscriber){
        this->name = name;
        this->spe
    }
};
int main(){

    return 0;
}
