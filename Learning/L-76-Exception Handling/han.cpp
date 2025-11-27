#include<iostream>
using namespace std;
class Customer{
    public:
    string name;
    int balance;
    int account_number;
    Customer(string name, int balance, int account_number){
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }
    // Deposite
    void deposit(int amount){
        if(amount >= 0){
            balance += amount;
             cout <<amount<<"is creadite suceffuly"<<endl;
        }else{
            throw runtime_error ("Amount Should be greater than 0");
        }
    }
    void withdraw(int amount){
        if(amount>0 && amount<=balance){
            balance -= amount;
            cout <<amount<<"is withdraw suceffuly"<<endl;
        }else{
            cout <<"Pagal Ho Kaya"<<endl;
        }
    }
};
int main(){
    Customer c("Rahul", 1000, 123);
    try{
        c.deposit(300);
         c.withdraw(200);
    }
    catch(const char *c){

    }

    return 0;
}
