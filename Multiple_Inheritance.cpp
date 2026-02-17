#include<iostream>
#include<cmath>
using namespace std;

/*                       (Base Class) A -----|
                                             |
                                             |--------> B (Derived Class)
                                             |
                         (Base Class) B -----|
*/


//--------------------------------------CALCULATOR-----------------------------------------------------------------------

class simpleCalculator{
    protected:
        void add(float a , float b){
            cout << a << " + " << b << " = " << a+b << endl;
        }
        void subtract(float a , float b){
            cout << a << " - " << b << " = " << a-b << endl;
        }
        void multiply(float a , float b){
            cout << a << " x " << b << " = " << a*b << endl;
        }
        void divide(float a , float b){
            cout << a << " / " << b << " = " << a/b << endl;
        }
};

class scientificCalculator{
    protected:
        void exponential(float a , float b){
            cout << a << "^" << b << " = " << pow(a,b) << endl;
        }
        void percentage(float a , float b){
            cout << "The Percentage is : " << (a/b)*100 << " %" << endl;
        }
        void cosine(float a){
            cout << "cos(" << a << ")" << " = " << cos(a) << endl;
        }
        void sine(float a){
            cout << "sin(" << a << ")" << " = " << sin(a) << endl;
        }
        void tangent(float a){
            cout << "tan(" << a << ")" << " = " << tan(a) << endl;
        }
};

class Calculator : protected simpleCalculator , protected scientificCalculator{
    private:
        int a;
        int b;
        
    public:

        void calculator_menu(){
            char ch;
            int x,y;
            cout << endl << endl << "    Select Operation : \n";
            cout << "'+' for Addition.\n";
            cout << "'-' for Subtraction.\n";
            cout << "'x' for Multiplication.\n";
            cout << "'/' for Division.\n"; 
            cout << "'e' for Exponential Function.\n";
            cout << "'%' to  calculate percentage.\n";
            cout << "'c' for Cos.\n";
            cout << "'s' for Sin.\n";
            cout << "'t' for Tan.\n" << endl;
            do{
                cout << "Enter Choice : ";
                cin >> ch;
            }while(!is_valid_choice(ch));
            cout << '\n';
            if(ch == '+'){
                cout << "Enter Number : ";
                cin >> a;
                cout << "Enter number : ";
                cin >> b;
                add(a,b);
            }
            else if(ch == '-'){
                cout << "Enter Number : ";
                cin >> a;
                cout << "Enter number : ";
                cin >> b;
                subtract(a,b);
            }
            else if(ch == 'x'){
                cout << "Enter Number : ";
                cin >> a;
                cout << "Enter number : ";
                cin >> b;
                multiply(a,b);
            }
            else if(ch == '/'){
                cout << "Enter Number : ";
                cin >> a;
                cout << "Enter number : ";
                cin >> b;
                divide(a,b);
            }
            else if(ch == 'e'){
                cout << "Enter base : ";
                cin >> a;
                cout << "Enter Exponent : ";
                cin >> b;
                exponential(a,b);
            }
            else if(ch == '%'){
                cout << "Enter The Part : ";
                cin >> a;
                cout << "Enter The Whole : ";
                cin >> b;
                percentage(a,b);
            }
            else if(ch == 'c'){
                cout << "Enter Angle (degree) : ";
                cin >> a;
                b=0;
                cosine(a);
            }
            else if(ch == 's'){
                cout << "Enter Angle (degree) : ";
                cin >> a;
                b=0;
                sine(a);
            }
            else if(ch == 't'){
                cout << "Enter Angle (degree) : ";
                cin >> a;
                b=0;
                tangent(a);
            }
        }
        bool is_valid_choice(char ch){
            if(ch == '+' || ch == '-' || ch == '/' || ch == 'x' || ch == 's' || ch == 'c' || ch == 't' || ch == 'e' || ch == '%'){return true;}
            return false;
        }

        /*
    Calculator c1;
    char ch;
    do{
    c1.calculator_menu();
    cout << "Do You Wish to Exit ? (y/n) : ";
    cin >> ch;
    }while(ch == 'n' || ch == 'N');
    */
};


//----------------------------------BASIC GAME CHARACTER---------------------------------------------------------------

class person{
    protected:
        int Health;
        int Level;
};

class healer : virtual protected person{
    protected:
        int Healing_power;
    public:
        healer(){
            Health = 100;
            Level = 1;
            Healing_power = 20;
        }
        void speak(){
            cout << " I am a Healer." << endl;
        }
        void heal(){
            cout << " Healing Spell used.     +10 HP" << endl;
        }
        void show_details(){
            cout << endl << " Player Type    : Healer" << endl;
            cout << " Player Health  : " << Health << " HP" << endl;
            cout << " Player Level   : " << Level << endl;
            cout << " Actions        : Can only Heal." << endl; 
        }
};

class attacker : virtual protected person{
    protected:
        int attack_power;
    public:
        attacker(){
            Health = 100;
            Level = 1;
            attack_power = 20;
        }
        void speak(){
            cout << " I am an Attacker." << endl;
        }
        void attack(){
            cout << " Sword Attack used.     Enemy -20 HP" << endl;
        }
        void show_details(){
            cout << endl << " Player Type    : Attacker" << endl;
            cout << " Player Health  : " << Health << " HP" << endl;
            cout << " Player Level   : " << Level << endl;
            cout << " Actions        : Can only Attack." << endl; 
        }
};

class paladin : protected healer , protected attacker{
   
    public:
        paladin(){
            Health = 120;
            Level = 1;
            Healing_power = 15;
            attack_power = 15;
        }
        void speak(){
            healer :: speak();
            attacker :: speak();
            cout << " I am THE PALADIN.\n\n";
        }
        void show_details(){
            cout << endl << " Player Type    : Paladin" << endl;
            cout << " Player Health  : " << Health << " HP" << endl;
            cout << " Player Level   : " << Level << endl;
            cout << " Actions        : Can Attack and Heal." << endl; 
        }
        void action(){
            attack();
            heal();
        }
};

int main(){

    healer h1;
    attacker a1;
    paladin p1;

    cout << endl;

    h1.speak();
    h1.heal();
    h1.show_details();
    cout << endl;
    a1.speak();
    a1.attack();
    a1.show_details();
    cout << endl << endl;
    p1.speak();
    p1.action();
    p1.show_details();
   

    cout << endl;

    return 0;
}