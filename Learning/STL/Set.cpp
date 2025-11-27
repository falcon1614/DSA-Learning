
// It Store Only unique element
// It Store value in sorted order

// Implement using avl tree for insertaion  for print inorder traversal

// Red black tree

// Real World Implement use Instagram unique id stored

#include<bits/stdc++.h>
using namespace std;

// Only Unique Value will be store
// Store Value in Sorted Order ascending
// Insertion Deletion and search Operation have logarithmic time (o(log n), making them fast for most use case).
// Generally Implement using Red-Black Tree or AVL Tree
// We Can Sort it in Descending Order also using greater<type>

class Person{
  public:
    string name;
    int age;

    bool operator <(const Person &other) const{
      return age<other.age;
    }
};

int main(){

  set<int,greater<int>> s;
  s.insert(10);
  s.insert(20);
  s.insert(30);
  s.insert(40);
  s.insert(20);

  // Search Element

  // Using find
  if(s.find(280)!=s.end())
    cout<<"Element Found \n";
  else
    cout<<"Element Not Found \n";

  // using Count
  if(s.count(281))
  cout<<"Present \n";
  else
  cout<<"Absent \n";

  // Delete
  s.erase(280);

  // Print Value
  cout<<"Element in Set ";
  for(auto it=s.begin(); it!=s.end(); it++){
    cout<<*it<<" ";
  }
  
  cout<<endl;
  cout<<"-----------------------------------"<<endl;
  cout<<"-----------------------------------"<<endl;
  cout<<endl;

  set<Person> p;
  Person person1;
  person1.name = "Alice";
  person1.age = 30;

  Person person2;
  person2.name = "Bob";
  person2.age = 25;

  p.insert(person1);
  p.insert(person2);

  // Print Persons
  for(auto it=p.begin(); it!=p.end(); it++){
    cout<<(*it).name<<" "<<(*it).age<<" ";
    cout<<endl;
  }
  cout<<endl;
}
