#include<iostream>
#include<string>
using namespace std;

 const int max_cars_in_garage = 10;

class car;
class customer;

//--------------------------GARAGE CLASS-------------------------------------------------------------------------------------------------------------------------------

class garage_owner{
    private:
        string owner_name;
        int owner_security_pin;
        friend class customer;
    public:
        garage_owner(){
            owner_name = "Black Knight";
            owner_security_pin = 9090;
        }
        void welcome(int& choice){
            cout << endl << "    Welcome, Black Knight." << endl << endl;
            cout << " What do you Wish To Do ?" << endl;
            cout << "1. See All Cars in The Garage." << endl;
            cout << "2. Add a New Car." << endl;
            cout << "3. Remove a Car." << endl;
            cout << "4. Change Color of a Car." << endl;
            do{
                cout << "Enter Choice : ";
                cin >> choice;
                if(choice < 0 || choice > 4){cout << "  Invalid Choice." << endl;}
            }while(choice < 0 || choice > 4);
            cout << endl;
        }
        void add_new_car(car c[]);
        void remove_car(car c[]);
        void see_all_cars(car c[]);
        void change_color(car c[]);
            
        bool authenticate_pin(){
            int pin , wrong_count = 0;
            do{
            cout << "Enter Owner Security Pin : ";
            cin >> pin;
            if(pin!=owner_security_pin){
                wrong_count++;
            }
           }while(pin != owner_security_pin && wrong_count != 3);
           if(wrong_count == 3){return false;}
           return true;
        }
        bool is_valid_reg(string s){
            int dash_count = 0 , number_count = 0 , alphabet_count = 0;
            if(s.length() < 4 || s.length() > 8){return false;}
            for(int i = 0;i<s.length();i++){
                if(s[i] == '-'){dash_count++;}
                else if(s[i] >= '0' && s[i] <= '9'){number_count++;}
                else if(s[i] >= 'A' && s[i] <= 'Z'){alphabet_count++;}
            }
            if(dash_count == 1 && (alphabet_count >=2 && alphabet_count <=3) && (number_count >= 1 && number_count <=4)){return true;}
            return false;
        }

        ~garage_owner(){
            // DESTRUCTOR
        }
        
};


//--------------------------------CAR CLASS------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class car{
    private:
        string brand;
        string model;
        int year;
        bool is_available;
        string registration_number;
        string color;
        static int total_cars;
        friend class garage_owner;
        friend class customer;
    public:
        car(){
           model = "empty";
           brand = "empty";
           year = 0;
           is_available = false;
          // cout << "Default Constructor." << endl;
        }
        car(string b , string m , int y , bool f , string r , string c){
            brand = b;
            model = m;
            year = y;
            is_available = f;
            registration_number = r;
            color = c;
           // cout << "Parameterized Constructor." << endl;
        }
        static void fill_details(car c[]){

            c[0] = car("Honda","Civic",2020,true,"LEH-991","Red");
            total_cars++;
            c[1] = car("Audi","A6",2022,true,"AUU-1567","White");
            total_cars++;
            c[2] = car("Kia","Sportage",2021,true,"ABC-123","Black");
            total_cars++;
            c[3] = car("Honda","Reborn",2021,true,"AU-1298","Grey");
            total_cars++;
            c[4] = car("Honda","City",2017,true,"ACB-098","Taffeta");
            total_cars++;
            c[5] = car("Toyota","Camry",2018,true,"MKL-1354","Light Blue");
            total_cars++;
            c[6] = car("Toyota","Grande",2022,true,"UHJ-3321","Silver");
            total_cars++;
            c[7] = car("Toyota","Corolla",2015,true,"LEE-3827","Red");
            total_cars++;
        }
        void print_car(){
            cout << endl << brand << " " << model << " " << year << " " << registration_number << " " << color << endl;
        }
        static void main_menu(int& a){
            cout << endl << "            GREETINGS !!!     " << endl << endl;
            cout << " Press 1 if you are the Owner of The Garage." << endl;
            cout << " Press 2 if you are some sort of a Customer." << endl;
            do{
                cout << "Enter Choice : ";
                cin >> a;
            }while(a != 1 && a != 2);
        }
        static int get_total_cars(){
            return total_cars;
        }

        ~car(){
            // DESTRUCTOR
        }
};






//---------------------FUNCTIONS OF CLASS DEFINED OUTSIDE CLASS----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void garage_owner :: see_all_cars(car c[]){
            cout << "Cars in The Garage : " << endl << endl;
            cout << "    Brand " << " Model " << " Year " << " Reg# " << " Color " << endl;
            cout << "-----------------------------------------" << endl;
            for(int i=0;i<car::total_cars;i++){
               
                if(c[i].is_available == true){
                    cout << "    " << c[i].brand << "  " << c[i].model << "  " << c[i].year << "  " << c[i].registration_number << 
                    "  " << c[i].color << endl << endl;
                }
            }
    }
void garage_owner :: add_new_car(car c[]){

    if(car::get_total_cars() >= max_cars_in_garage){
            cout << "Garage is Full." << endl;
            return;
    }

    string b,m,r,color;
    int year;
    cin.ignore();
    cout << "Enter Brand of Car (honda,toyota etc) : ";
    getline(cin,b);

    cout << "Enter Model of Car (civic,grande etc) : ";
    getline(cin,m);

    do{
        cout << "Enter Year of Manufacturing : ";
        cin >> year;
    }while(year < 1960 || year > 2025);

    cin.ignore();
    do{
    cout << "Enter Registration Number : ";
    getline(cin,r);
    if(!is_valid_reg(r)){cout << "   Invalid Registration Number." << endl;}
    }while(!is_valid_reg(r));

    cout << "Enter The Color of the Car : ";
    getline(cin,color);
    
    c[car::total_cars] = car(b,m,year,true,r,color);
    car::total_cars++;
    cout << endl << "   Car Added to Garage Successfully." << endl;
    
}
void garage_owner :: remove_car(car c[]){
    cin.ignore();
    string r;
    bool found = false;
    cout << "Enter Registration Number of Car You Want to remove : ";
    getline(cin,r);
    for(int i=0;i<car :: total_cars;i++){
        if(r == c[i].registration_number){
            found = true;
            c[i].is_available = false;
            break;
        }
    }
    if(!found){cout << "Car Not Found." << endl;}
    else{cout << "Car Removed Successfully." << endl;}
}
void garage_owner :: change_color(car c[]){
    cin.ignore();
    bool found = false;
    string r;
    int j;
    cout << "Enter The Registration Number of the Car you want to change color of : ";
    getline(cin,r);
     for(int i=0;i<car :: total_cars;i++){
        if(r == c[i].registration_number){
            found = true;
            j = i;
            break;
        }
    }
    if(!found){cout << "Car Not Found." << endl; return;}
    else{
        string color;
        cout << "Enter New Color : ";
        getline(cin,color);
        c[j].color = color;
        cout << "Color Changed Successfully." << endl;
    }
}

//----------------------------------MAIN----------------------------------------------------------------------------------------------------------------------------------------------------------


int car :: total_cars;
const int customer :: max_garage_capacity;
void main_menu(int& a);

int main(){

    cout << endl << "                   ====================| BLACK KNIGHT GARAGE |====================           " << endl << endl;
   
    garage_owner owner;
    car cars[max_cars_in_garage];
    car::fill_details(cars);
    customer c1;
    int choice , owner_choice , customer_choice;
    char main_repeater = 'y' , owner_repeater = 'y';
    do{
          car::main_menu(choice);

            if(choice == 1){
                if(owner.authenticate_pin()){
                  do{
                        owner.welcome(owner_choice);
                        switch (owner_choice)
                        {
                        case 1:
                            owner.see_all_cars(cars);
                            break;
                        case 2:
                            owner.add_new_car(cars); 
                            break;
                        case 3:
                            owner.remove_car(cars);
                            break;
                        case 4:
                            owner.change_color(cars);
                            break;
                        default:
                            cout << " Invalid Choice." << endl;
                            break;
                        }

                    cout << endl << "  Do You Wish To do Something Else (y/n) : ";
                    cin >> owner_repeater;
                    cout << endl;
                  }while(owner_repeater == 'y' || owner_repeater == 'Y');
                }
                else{cout << endl << "You Are Not the Owner of The Garage." << endl;}

            }
            else if(choice == 2){
                char customer_repeater = 'n';
                do{
                   c1.customer_menu(customer_choice);
                   switch (customer_choice)
                   {
                    case 1:
                        c1.buy_new_car(cars);
                        break;
                    case 2:
                        c1.sell_a_car(cars);
                        break;
                    case 3:
                        c1.repair_car();
                        break;
                    case 4:
                        c1.see_owned_cars();
                        break;
                    case 5:
                        owner.see_all_cars(cars);
                        break;
                   default:
                    cout << "Invalid Choice." << endl;
                    break;
                   }


                   cout << endl << "     Do you wish to Exit the Garage (y/n) : ";
                   cin >> customer_repeater;
                   cout << endl;

                }while(customer_repeater == 'n' || customer_repeater == 'N');
            }



            
            cout << "Do You Want to Run The Program Again ? (y/n) : ";
            cin >> main_repeater;
            cout << endl;

        }while(main_repeater == 'y' || main_repeater == 'Y');
    
        
    return 0;
}

