#include<iostream>
using namespace std;

class BankAccount {
public:
    float bal;
    
    BankAccount() {
        bal = 0.0;
    }
    
    BankAccount(float b) {
        bal = b;
    }
    
    void Display() {
        cout << "Balance: K$" << bal << endl;
    }
};

int main() {
    BankAccount account1;
    account1.Display();
    
    BankAccount account2(100.0f);
    account2.Display();
    
    BankAccount account3(account2);
    account3.Display();
    
    return 0;
}
