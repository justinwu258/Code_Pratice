#include<iostream>
using namespace std;

class Person{
    public:
        Person():name("Justin"),address("Taipei"){};        
        string getName(const string &);
        string getName();
        string getAddr(const string &);
    private:
        string name;
        string address;
};

string Person::getName(){
    return name;
}
string Person::getName(const string &s){
    return s;
};

int main(){
    //cout << "Hello" << endl;
    Person p;
    cout << "Who is the person(input string)? " << p.getName("Kerker") << endl;
    cout << "Who is the person(origin)? " << p.getName() << endl;
    return 0;
}
