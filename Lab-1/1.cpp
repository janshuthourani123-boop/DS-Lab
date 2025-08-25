#include <iostream>

using namespace std;
class BankAccount{
    public:
    float balance;
    BankAccount(){
        balance = 0.0;
    }
    BankAccount(float b){
       balance = b;
    }
    void Display(){
        cout<<"Balance: "<<balance<<endl;
    }
};
int main() {
  BankAccount account1;
  account1.Display();
  BankAccount account2(1000);
  account2.Display();
  BankAccount account3 = account2;
  account3.Display();
  account3 = account3.balance - 200.0;
  account3.Display();  
    return 0;
}
