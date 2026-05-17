# include<iostream>
# include<fstream>

using namespace std;

class BankAccount{
    public:
         int accountno;
         string name;
         float balance;

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

            // case 2:
            // acc.depositMoney();
            // break;

            // case 3:
            // acc.WithdrawMoney();
            // break;

            // case 4:
            // acc.checkBalance();
            // break;

            case 5:
            cout<<"\nThank You!!\n\n";
            break;
        }
        
    }while(choice!=5);
   
}