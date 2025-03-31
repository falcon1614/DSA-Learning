#include<iostream>
using namespace std;
class Complex{
    int real;
    int img;
    public:
    Complex(){
        
    }
    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }
    void disply(){
        cout<<real<<"+i"<<img<<endl;
    }
    Complex operator+(Complex c){
        Complex ans;
        ans.real = real+c.real;
        ans.img = img+c.img;
    }
};
int main(){
    Complex c1(2,3);
    Complex c2(4,5);

    Complex c3 = c1+c2;
    return 0;
}
