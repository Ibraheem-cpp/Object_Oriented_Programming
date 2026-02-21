#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class bank;

class bank_admin{

    private:
        int admin_security_pin;
    public:
    bank_admin(){
        admin_security_pin = 6969;
    }
    void see_all_details(bank b[]);
    void change_pin(bank b[]);
    bool validate_admin(){
        int pin;
        cout << "Enter The Admin Security Pin : ";
        cin >> pin;
        if(pin == admin_security_pin){return true;}
        return false;
    }
    bool authentic_pin(int pin , int n_pin){
        if(pin < 1000 || pin > 9999 || n_pin < 1000 || n_pin > 9999 || pin != n_pin){return false;}
        return true;
    }
    
};

class bank{

private:
    string name;
    double account_no;
    int pin;
    double balance;
    static int total_accounts;
    friend class bank_admin;
public:
    bank(){
        name = " ";
        account_no = 0;
        pin = 0;
        balance = 0;
    }
    bank(string n , double a_c , int p , double bal){
        name = n;
        account_no = a_c;
        pin = p;
        balance = bal;
        total_accounts++;
    }
    static void fill_details(bank b[]){
       int a_c = (rand() % 20000) + 150000;
       int a_c2 = (rand() % 20000) + 150000;
       int a_c3 = (rand() % 20000) + 150000;
    
         b[0] = bank("Ibraheem Tahir" , a_c , 2005 , 50000);
         b[1] = bank("Black Knight" , a_c2 , 1005 , 40000);
         b[2] = bank("Geralt of Rivia" , a_c3 , 4005 , 400000);
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    void details(){
            cout << "         Account Details        " << endl << endl;
            cout << " Account Holder Name : " << name << endl;
            cout << " Account Number      : " << account_no << endl;
            cout << " Current Balance     : " << balance << endl;
            cout << endl;
    }
    void deposit(){

           double amount;
           cout << "Enter The Amount of Money You wish to Deposit : ";
           cin >> amount;

           if(amount < 0){cout << "Invalid Amount." << endl; return;}

           balance = balance + amount;
           cout << " Amount Deposited Successfully." << endl;
           cout << endl;
        
    }
    void withdraw(){
           double amount;
           cout << "Enter The Amount of Money You wish to Withdraw : ";
           cin >> amount;

           if(amount < 0){cout << "Invalid Amount." << endl; return;}

           if(balance-amount >= 0){
              balance = balance - amount;
              cout << " Amount Withdrawn Successfully." << endl;
           }
           else{
              cout << " Not Enough Money." << endl;
           }
           cout << endl;
        
    }
    int your_acount(bank b[]){
        int a = -1;
        your_account1(b,a);
        if(a != -1){return a-1 ;}
        return a;
    }
    void your_account1(bank b[] , int& a){
        int acc;
        cout << "     Current Accounts : " << endl;
        for(int i=0;i<total_accounts;i++){
           cout << i+1 << ". ";
           b[i].show_name();
        }
        do{
           cout << "Enter Your Account : ";
           cin >> acc;
        }while(acc < 1 || acc > total_accounts);

        if(!b[acc-1].authenticate_pin()){cout << "Incorrect Pin." << endl; return;}
        else{
            cout << endl << "           Welcome " << b[acc-1].name << " ! " << endl;
            a = acc;
        }
    }
    void bank_transfer_details(int your_account , bank b[]){
        int acc2;
        cout << " In whose account do you wish to transfer Money : " << endl;
        for(int i=0;i<total_accounts;i++){
            cout << i+1 << ". ";
            b[i].show_name();
        }
        cout << "Enter Account : ";
        cin >> acc2;
        if(acc2 < 1 || acc2 > total_accounts){cout << "Account Not Found." << endl; return;}
        else if(your_account+1 == acc2){cout << "You Cannot Transfer To the same account." << endl; return;}
        else{
            bank_transfer(b[your_account],b[acc2-1]);
        }
    }
    bool authenticate_pin(){
        int p;
        cout << "Enter Pin : ";
        cin >> p;
        if(p == pin){return true;}
        return false;
    }
    void show_name(){
        cout << name << endl; 
    }


    friend void bank_transfer(bank& b1 , bank& b2);
    friend void audit_account(const bank& b);
    
};

void bank_transfer(bank& b1 , bank& b2){
    double amount;
    cout << "Enter The Amount You Want To Transfer : ";
    cin >> amount;
    if(amount < 0 ){cout << "Invalid Amount." << endl; return;}
    else if(b1.balance-amount < 0){cout << "Not Enough Balance." << endl; return;}
    else{
        b1.balance = b1.balance - amount;
        b2.balance = b2.balance + amount;
        cout << " Transaction Successful." << endl;
    }
}
void audit_account(const bank& b){
    cout << endl;
    cout << "         Auditing Account " << endl;
    cout << " Account Title   : " << b.name << endl;
    cout << " Account Number  : " << b.account_no << endl;
    cout << " Account Balance : " << b.balance << endl;
    cout << endl;
}

void bank_admin::see_all_details(bank b[]){
    for(int i=0;i<b[0].total_accounts;i++){
        cout << "              Account Number " << i+1 << endl;
        cout << " Account Holder Name : " << b[i].name << endl;
        cout << " Account Number      : " << b[i].account_no << endl;
        cout << " Current Balance     : " << b[i].balance << endl;
        cout << " Account Pin         : " << b[i].pin << endl;
        cout << endl;
    }
}
void bank_admin::change_pin(bank b[]){
    int choice;
    cout << " Whose Pin You Want To Change ?" << endl;
    for(int i=0;i<b[0].total_accounts;i++){
        cout << i+1 << ". ";
        b[i].show_name();
    }
    do{
        cout << "Enter Choice : ";
        cin >> choice;
    }while(choice < 1 || choice > b[0].total_accounts);
    int new_pin , new_pin2;
    do{
        cout << "Enter New Pin (4 digits)       : ";
        cin >> new_pin;
        cout << "Re-Enter New Pin (Same as Pin) : ";
        cin >> new_pin2;
        if(!authentic_pin(new_pin,new_pin2)){
            cout << "You Entered Invalid Pin." << endl;
        }
        cout << endl;
    }while(!authentic_pin(new_pin,new_pin2));
    b[choice-1].pin = new_pin;
    cout << "Pin Changed Successfully." << endl;
}

void user(int& a);
void menu();
void admin_menu(int& a);

int bank :: total_accounts;

int main()
{
    cout << endl << "                   ====================| BLACK KNIGHT BANK |====================           " << endl;
    srand(time(0));
    bank accounts[3];
    bank::fill_details(accounts);
    
    char rep2 = 'y';
    while (rep2 == 'y' || rep2 == 'Y')
    {
        char rep1 = 'y';
        int user_choice = 0;
        user(user_choice);
        if (user_choice == 2)
        {
            bank_admin admin;
            if (admin.validate_admin())
            {
                int admin_choice = 0;
                cout << endl << "            Welcome Bank Admin ! " << endl;
                admin_menu(admin_choice);
                if(admin_choice==1){
                    admin.see_all_details(accounts);
                    cout << endl;
                }
                else if(admin_choice == 2){
                    admin.change_pin(accounts);
                    cout << endl;
                }
            }
            else
                cout << "Invalid Pin. You Are Not an Admin." << endl;
        }

        else if (user_choice == 1)
        {
            while (rep1 == 'y' || rep1 == 'Y')
            {
                char rep = 'y';
                int your_account = 0;
                do
                {
                    your_account = accounts->your_acount(accounts);
                } while (your_account == -1);

                int choice;
                while (rep == 'y' || rep == 'Y')
                {
                    menu();
                    cout << "Enter Choice : ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        accounts[your_account].details();
                        break;
                    case 2:
                        accounts[your_account].deposit();
                        break;
                    case 3:
                        accounts[your_account].withdraw();
                        break;
                    case 4:
                        accounts[your_account].bank_transfer_details(your_account, accounts);
                        break;
                    case 5:
                        audit_account(accounts[your_account]);
                        break;
                    case 0:
                        break;
                    default:
                        cout << " Invalid Choice." << endl;
                        break;
                    }

                    cout << "       Do You Wish To do Something Else ? (y/n) : ";
                    cin >> rep;
                }

                cout << "    Do You Wish To Switch To Another Account (y/n) : ";
                cin >> rep1;
            }
        }
        cout << " Do You Wish To Run The Program Again ? (y/n) : ";
        cin >> rep2;
    }

    return 0;
}

void menu(){
    cout << endl;
    cout << " Press 1 to see Account Details." << endl;
    cout << " Press 2 to Deposit Money into Account." << endl;
    cout << " Press 3 to Withdraw Money From Account." << endl;
    cout << " Press 4 to Transfer Money To another Account." << endl;
    cout << " Press 5 to Audit Account." << endl;
    cout << " Press 0 to Exit." << endl;
    cout << endl;
}
void user(int& a){
    cout << endl << "              Greetings !!!       " << endl << endl;
    cout << " Press 1 if You are a Bank Account Holder." << endl;
    cout << " Press 2 if You are a Bank Admin." << endl;
    do{
    cout << "Enter Choice : ";
    cin >> a;
    }while(a != 1 && a != 2);
}
void admin_menu(int& a){
    cout << endl;
    cout << " Press 1 to see the Details of Every Account Holder." << endl;
    cout << " Press 2 to Change The Pin of The Account Holder." << endl;
    do{
        cout << "Enter Choice : ";
        cin >> a;
    }while(a != 1 && a != 2);
}

