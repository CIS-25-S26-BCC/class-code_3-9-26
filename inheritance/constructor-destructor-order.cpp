#include <iostream>

using namespace std;

class Base {
    public:
        Base() {
            cout << "We're in the base constructor!!!!" << endl;
        }
        ~Base() {
            cout << "We're in the base destructor!!!!" << endl;
        }
};

class Derived : public Base {

    public:
        Derived() {
           cout << "We're in the derived constructor!!!!" << endl; 
        }

        ~Derived() {
           cout << "We're in the derived destructor!!!!" << endl; 
        }

};

int main() {
    Derived derived;
}