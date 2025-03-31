#include<iostream>
#include<vector>
using namespace std;
class Animal{
    public:
    virtual void speak(){  // when use virtual keyword then it decide at runtime
        cout<<"Hu-Hu-Hu"<<endl;
    }
};
class Dog:public Animal{
    public:
    void speak(){
        cout <<"Bark"<<endl;
    }
};
class Cat:public Animal{
    public:
    void speak(){
        cout <<"Meow"<<endl;
    }
};
int main(){
    // Animal *p; // 1 pointer of Animal class
    // p = new Dog; //
    // p->speak(); // 2 it run

    Animal *p;
    vector<Animal*>animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    for(int i=0; i<animals.size(); i++){
        p = animals[i];
        p->speak();
    }
    return 0;
}
