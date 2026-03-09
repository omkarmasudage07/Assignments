#include<iostream>
using namespace std;

class BankAccount{
    int accountNo;
    string accountHolderName;
    double balance =90000;
    public:
        void setAccountNO(int accountNO)
        {
            this->accountNo = accountNO;
        }
        int getAccountNo()
        {
            return accountNo;
        }
        void setName(string accountHolderName)
        {
            this->accountHolderName = accountHolderName;
        }
        string getName()
        {
            return accountHolderName;
        }

        void deposit(double ammount)
        {
            balance = balance+ammount;
            cout << "Amount Deposited Successfully!\n";
        }
        void withdraw(double amount)
        {
            if(amount > balance)
            {
                cout << "Insufficient Balance!\n";
            }
            else
            {
                balance -= amount;
                cout << "Amount Withdrawn Successfully!\n";
            }
        }
        double getBalance()
        {
            return balance;
        }
        void displayAccountDetails()
        {
            cout<<"Account NO: "<<getAccountNo()<<endl;
            cout<<"Account holder name: "<<getName()<<endl;
            cout<<" balance: "<<getBalance()<<endl;
        }
};

int main()
{
    BankAccount b;
    int acn;
    cout<<"Enter the ac no:"<<endl;
    cin>>acn;
    string name;
    cout<<"Enter the name: "<<endl;
    cin>>name;
    b.setAccountNO(acn);
    b.setName(name);
    
    cout<<"press 1 for deposit \n press 2 for withdraw"<<endl;
    int choice;
    cin>>choice;
    if(choice == 1){
        int am;
        cout<<"Enter the amount:"<<endl;
        cin>>am;
        b.deposit(am);

    }
    else{
        int am;
        cout<<"Enter the amount:"<<endl;
        cin>>am;
        b.withdraw(am);
    }
        

    b.displayAccountDetails();
}