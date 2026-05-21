# include<iostream>
# include<fstream>

using namespace std;

class BankAccount{
    public:
         int accountno;
         string name;
         float balance; 

        // function to create the account.

        void createAccount(){

            cout<<"\nEnter Account number: ";
            cin>> accountno;

            cin.ignore();

            ifstream file("bank.txt");

            string data;
            bool found = false;

            while(getline(file,data)){
                int pos = data.find("|");
                string acc_no = data.substr(0,pos);

                if(stoi(acc_no) == accountno){
                    found = true;
                    break;
                }
            }
            file.close();

            if(found){
                cout<<"\nAccount already exists!\n";
            }
            else{
                ofstream file("bank.txt", ios::app);

                cout<<"Enter the name of the Account holder: ";
                getline(cin,name);

                cout<<"Enter the initial balance: ";
                cin>> balance;

                cin.ignore();

                file<<accountno<<"|"<<name<<"|"<<balance<<endl;

                file.close();

                cout<<"\nAccount created successfully!!\n";
            }
         }
         // function to deposit the money.
         
            void depositMoney(){

            ifstream file("Bank.txt");
            ofstream temp("temp.txt",ios::app);
            string data;
            int amount;

            cout<<"Enter the Account No to deposit Money: ";
            cin>>accountno;

            cout<<"Enter the amount to be deposited: ";
            cin>> amount;
                    
            bool found = false;


            while(getline(file,data)){

                int pos1= data.find("|");
                string acc_no = data.substr(0,pos1);

                data.erase(0, pos1 + 1);
                int pos2 = data.find("|");

                string name = data.substr(0, pos2);

                data.erase(0, pos2 + 1);

                string balance = data;

                float bal = stof(balance);

                if(stoi(acc_no) == accountno){

                    bal += amount;
                    found = true;

                    cout<<"\nMoney credited Successfully!!\n";
                }

                temp << acc_no << "|"
                 << name << "|"
                 << bal << endl;
                }

                file.close();
                temp.close();

                remove("bank.txt");
                rename("temp.txt","bank.txt");

                if(!found){
                    cout<<"\nAccount not found! Please enter correct account number or create a new account.\n";
                }
         }

         void WithdrawMoney(){

            ifstream file("Bank.txt");
            ofstream temp("temp.txt",ios::app);
            string data;
            int amount;

            cout<<"Enter the Account No to  withdrawn Money: ";
            cin>>accountno;

            cout<<"Enter the amount to be withdrawn: ";
            cin>> amount;
                    
            bool found = false;


            while(getline(file,data)){

                int pos1= data.find("|");
                string acc_no = data.substr(0,pos1);

                data.erase(0, pos1 + 1);
                int pos2 = data.find("|");

                string name = data.substr(0, pos2);

                data.erase(0, pos2 + 1);

                string balance = data;

                float bal = stof(balance);

                if(stoi(acc_no) == accountno){

                    if((bal - amount)>=0){
                         
                        cout<<"\nMoney debited Successfully!! "<<(amount)<<" Rupees.\n";
                        bal -= amount;
                    }
                    else{
                        cout<<"\nInsufficient balance!!\n";
                    }
                    found = true;
                }

                temp << acc_no << "|"
                 << name << "|"
                 << bal << endl;
                }

                file.close();
                temp.close();

                remove("bank.txt");
                rename("temp.txt","bank.txt");

                if(!found){
                    cout<<"\nAccount not found! Please enter correct account number or create a new account.\n";
                }


         }

         void checkBalance(){
            ifstream file("Bank.txt");
            ofstream temp("temp.txt",ios::app);
            string data;
            int amount;

            cout<<"Enter the Account No to Check Balance: ";
            cin>>accountno;

                    
            bool found = false;


            while(getline(file,data)){

                int pos1= data.find("|");
                string acc_no = data.substr(0,pos1);

                data.erase(0, pos1 + 1);
                int pos2 = data.find("|");

                string name = data.substr(0, pos2);

                data.erase(0, pos2 + 1);

                string balance = data;

                float bal = stof(balance);

                if(stoi(acc_no) == accountno){

                    cout<< "\n Available Balance is "<<bal<<" Rupees.\n";
                    found = true;
                }

                temp << acc_no << "|"
                 << name << "|"
                 << bal << endl;
                }

                file.close();
                temp.close();

                remove("bank.txt");
                rename("temp.txt","bank.txt");

                if(!found){
                    cout<<"\nAccount not found! Please enter correct account number or create a new account.\n";
                }

         }
};
int main(){

    BankAccount acc;
    int choice;
    
    do{
        cout<<"\n=====BANK MENU=====\n";
        cout<<"\n1. Create Account";
        cout<<"\n2. Deposit Money";
        cout<<"\n3. Withdraw Money";
        cout<<"\n4. Check Balance";
        cout<<"\n5. Exit";

        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            acc.createAccount();
            break;

            case 2:
            acc.depositMoney();
            break;

            case 3:
            acc.WithdrawMoney();
            break;

            case 4:
            acc.checkBalance();
            break;

            case 5:
            cout<<"\nThank You!!\n\n";
            break;
        }
        
    }while(choice!=5);
   
}