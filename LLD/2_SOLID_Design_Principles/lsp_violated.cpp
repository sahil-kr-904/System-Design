#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account{
    public:
      
      virtual void deposit(double amount) = 0;
      virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account{
    private:
       double balance;

    public:
       SavingAccount(){
         balance = 0;
       }

       void deposit(double amount){
          balance += amount;
          cout << "Credited: " << amount << " in saving account. New Balance: " << this->balance << endl; 
       }

       void withdraw(double amount){
          if(balance>=amount){
            balance -= amount;
          }
          cout << "Debited: " << amount << " from saving account. New Balance: " << this->balance << endl;
       }
};

class CurrentAccount : public Account{
    private:
       double balance;

    public:
       CurrentAccount(){
         balance = 0;
       }

       void deposit(double amount){
          balance += amount;
          cout << "Credited: " << amount << " in current account. New Balance: " << this->balance << endl; 
       }

       void withdraw(double amount){
          if(balance>=amount){
            balance -= amount;
          }
          cout << "Debited: " << amount << " from current account. New Balance: " << this->balance << endl;
       }
};

class FixedDepositAccount : public Account{
    private:
       double balance;

    public:
       FixedDepositAccount(){
         balance = 0;
       }

       void deposit(double amount){
          balance += amount;
          cout << "Credited: " << amount << " in current account. New Balance: " << this->balance << endl; 
       }

       void withdraw(double amount){
          throw logic_error("Can't withdraw from this account");
       }
};

class BankClient{
    private:
      vector<Account*> accounts;

    public:
      BankClient(vector<Account*> accounts){
        this->accounts = accounts;
      }

      void processTransactions(int amount){
        for(int i=0; i<accounts.size(); i++){
            accounts[i]->deposit(amount); //All accounts allow deposits

            // Assuming all accounts support withdrawl (LSP Violation)
            try{
              accounts[i]->withdraw(500);
            }
            catch (const logic_error&e){
                cout << "Exception: " << e.what() << endl;
            }
        }
      }
};

int main(){
    
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedDepositAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions(10000);


    return 0;
}