#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream fin;
    // File ko open Karna
    fin.open("zoom.txt");
    // fir ko read karo
    char c;
    fin>>c;
    while(!fin.eof()){
        cout <<c;
        c = fin.get();
    }
    fin.close();
}