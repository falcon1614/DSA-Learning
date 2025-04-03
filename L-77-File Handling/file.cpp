#include<iostream>
#include<fstream>
using namespace std;
int main(){
    // File ko open karne
    ofstream fout;
    fout.open("zoom.txt"); // create kar dega aur fr open
    // Write kar sakta hu
    fout<<"Hello India";
    fout.close();
    return 0;
}