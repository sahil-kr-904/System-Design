#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NonWithdrawableAccount{
    public:

      virtual void deposit(int amount) = 0;
};

class Withdrwableaccount : public NonWithdrawableAccount{
    public:
      
      virtual void withdraw(int amount) = 0;
};

class currentAccount : public Withdrwableaccount{
    private:
      int balance;

    public:

      currentAccount(){
         balance = 0;
      }

    //   Getter
       int balanceCheck(){
         return this->balance;
       }

    // Setter
       void deposit(int amount){
          this->balance += amount;
          cout << "Credited: " << amount << " in current account. New Balance: " << this->balance << endl; 
       }

       void withdraw(int amount){
          if(amount<=this->balance){
            this->balance -= amount;
            cout << "Debited: " << amount << " from current account. New Balance: " << this->balance << endl;
          }
          else{
            cout << "Insufficient balance\n";
          }
       }
};

class SavingAccount : public Withdrwableaccount{
    private:
      int balance;

    public:

      SavingAccount(){
         balance = 0;
      }


    //   Getter
       int balanceCheck(){
         return this->balance;
       }

    // Setter
       void deposit(int amount){
          this->balance += amount;
          cout << "Credited: " << amount << " in saving account. New Balance: " << this->balance << endl; 
       }

       void withdraw(int amount){
          if(amount<=this->balance){
            this->balance -= amount;
            cout << "Debited: " << amount << " from saving account. New Balance: " << this->balance << endl;
          }
          else{
            cout << "Insufficient balance\n";
          }
       }
};

class FixedDepositAccount : public NonWithdrawableAccount{
    private:
      int balance;

    public:

      FixedDepositAccount(){
         balance = 0;
      }


    //   Getter
       int balanceCheck(){
         return this->balance;
       }

    // Setter
       void deposit(int amount){
          this->balance += amount;
          cout << "Credited: " << amount << " in fd account. New Balance: " << this->balance << endl; 
       }
};

class BankClient{
   private:
     vector<Withdrwableaccount*> withdrawable_accounts;
     vector<NonWithdrawableAccount*> nonwithdrawable_accounts;

   public:
     BankClient(vector<Withdrwableaccount*> withdrawable_accounts,vector<NonWithdrawableAccount*> nonwithdrawable_accounts){
      this->withdrawable_accounts = withdrawable_accounts;
      this->nonwithdrawable_accounts = nonwithdrawable_accounts;
     }
     
   //   Supporting the lsv of SOLID principle
     void process_transaction(int amount){
       for(int i=0; i<withdrawable_accounts.size(); i++){
         withdrawable_accounts[i]->deposit(amount);
         withdrawable_accounts[i]->withdraw(500);
       }
       for(int i=0; i<nonwithdrawable_accounts.size(); i++){
         nonwithdrawable_accounts[i]->deposit(amount);
       }
     }
};

int main(){
    
   vector<Withdrwableaccount*> withdrawable_accounts;
   withdrawable_accounts.push_back(new SavingAccount());
   withdrawable_accounts.push_back(new currentAccount());

   vector<NonWithdrawableAccount*> nonwithdrawable_accounts;
   nonwithdrawable_accounts.push_back(new FixedDepositAccount());

   BankClient* client = new BankClient(withdrawable_accounts,nonwithdrawable_accounts);
   client->process_transaction(10000);

   return 0;
}