#include<iostream>
using namespace std;
class Customer{
    string name;
    int age;
    int account_number;
    int balance;
    static int total_customer;
    public:
    Customer(string name, int age, int account_number, int balance){
        this->name = name;
        this->age = age;
        this->account_number = account_number;
        this->balance = balance;
        total_customer++;
    }
    static void accesStatic(){
        cout << "Total customer: " << total_customer << endl;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
        cout << "Total_customer" <<total_customer << endl;
        cout <<endl;
    }
};
int Customer::total_customer = 0;
int main(){
    Customer c1("John", 25, 1234, 1000);
    Customer c2("Jane", 30, 5678, 2000);
    c1.display();
    c2.display();
    Customer::accesStatic();
    return 0;
}
