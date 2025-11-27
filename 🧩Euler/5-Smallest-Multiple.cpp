// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
#include<bits/stdc++.h>
using namespace std;
// int main(){
//     int numbers = 21;

//     while (true){
//         int temp = 20;
//         while(temp>1){
//             if(numbers%temp!=0){
//                 numbers++;
//             }
//             temp--;
//         }
//         if(temp==1){
//             cout<< numbers;
//             return 0;
//         }
//    }
//     cout<<numbers;
//     return 0;
// }

void fun(int &number, int temp){
    if(temp==1){
        return;
    }
    while(temp>1){
        if(number%temp!=0){
            number++;
            fun(number,temp);
        }
        temp--;
    }
}

int main(){
    int number = 21;
    int temp = 20;
    fun(number,temp);
    cout<<"smallest positive number that is evenly divisible by all of the numbers from 1 to 20"<<number;
    return 0;
}
