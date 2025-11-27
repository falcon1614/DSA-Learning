#include<iostream>
using namespace std;
class Area{
    public:
    int areaOfCircle(int r){
        return 3.14*r*r;
    }
    int areaofrectangle(int l, int r){
        return l*r;
    }
};
int main(){
    Area a;
    cout<<a.areaOfCircle(5);
    return 0;
}
