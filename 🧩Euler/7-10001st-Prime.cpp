#include<bits/stdc++.h>
using namespace std;

void prime(int &num, int &count){
    if(count == 1000){
        return;
    }

    int temp = 2;
    bool flag = false;

    //********* Check Prime Or Not
    while(temp*temp <= num){
        if(num % temp == 0){
            flag = true;
            break;
        }
        temp++;
    }

    if(flag == false){
        count++;
        if(count == 10001) return;
    }

    num++;
    prime(num, count);
}

int main(){
    int num = 2;
    int count = 0;
    prime(num, count);
    cout << num;
    return 0;
}
