// Special Pythagorean Triplet https://projecteuler.net/problem=9
#include<bits/stdc++.h>
using namespace std;
bool Pythagoram(int a, int b, int c){
    if(a<b<c){
        if((a*a+b*b) == (c*c)){
            return true;
        }
    }
    return false;
}
int main(){
    int a,b,c;
    Pythagoram(a,b,c);
    return 0;
}
