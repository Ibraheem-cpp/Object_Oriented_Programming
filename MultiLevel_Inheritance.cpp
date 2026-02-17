#include<iostream>
using namespace std;

/*                  Base Class     Derived Class     Further Derived Class from previous derived class
                          A ------------> B -------------> C                                           
*/


//-----------------------------------------EMPLOYEE CLASS---------------------------------------------------------------

class person{
    protected:
        string name;
        int age;
    public: 
        void set_data(string n , int a){
            name = n;
            age = a;
        }
        int get_age(){
            return age;
        }
        void get_name(){
            cout << "The Name of The Employee is : " << name << endl;
        }
};

class Employee : public person{
    protected: 
        int Employee_ID;
        int salary;
    public: 
        void set_Employee_Data(int id , int sal){
            Employee_ID = id;
            salary = sal;
        }
};

class Manager : public Employee{
    protected:
        string designation = "Manager";
        string Department_Name;
        string Department_ID;
    public:
        void Set_Manager_Data(string n , string id){
            Department_Name = n;
            Department_ID = id;
            
        }
        void print_person_Details(){
            cout << endl << "              PERSON DETAILS              " << endl;
            cout << "Employee Name         : " << name << endl;
            cout << "Employee Age          : " << age << endl;
            cout << "Employee Designation  : " << designation << endl;
            cout << "Employee ID           : " << Employee_ID << endl;
            cout << "Department Name       : " << Department_Name << endl;
            cout << "Department ID         : " << Department_ID << endl;
            cout << "Salary                : " << salary << endl << endl; 
        }
};

  /*
      Manager m1;
      m1.set_data("Ibraheem" , 20);
      m1.set_Employee_Data(2303 , 250000);
      m1.Set_Manager_Data("Game Development" , "GD-202");
      m1.print_person_Details();
    */

//-------------------------------------------VEHICLE CLASS-------------------------------------------------------------

class vehicle{
    private:
        int year;
        string brand;
        string model;
        int number_of_wheels;
    protected:
        void set_vehicle_data(int y , string b , string m){
            year = y;
            brand = b;
            number_of_wheels = 4;
            model = m;
        }
        int get_year() const {
            return year;
        }
        int get_wheel_count() const {
            return number_of_wheels;
        }
        string get_brand() const {
            return brand;
        }
        string get_model() const {
            return model;
        }
};

class car : protected vehicle{
    private:
        int number_of_doors;
        string fuel_type;
    protected:
        void set_car_data(int d){
            number_of_doors = d;
            fuel_type = "Electric";
        }
        int get_doors() const {
            return number_of_doors;
        }
        string get_fuel_type() const {
            return fuel_type;
        }
};

class Electric_Car : protected car{
    private:
        int battery_capacity;
        int charge_time;
    public:
        void set_electric_car_data(int battery,int charge,int doors,int year,string brand,string model){
            battery_capacity = battery;
            charge_time = charge;
            set_car_data(doors);
            set_vehicle_data(year,brand,model);
        }
        void see_car_details(){
            cout << endl << "                                   CAR DETAILS        " << endl << endl;
            cout << "Manufacturing Year      : " << get_year() << endl;
            cout << "Car Brand               : " << get_brand() << endl;
            cout << "Car Model               : " << get_model() << endl;
            cout << "Car Fuel Type           : " << get_fuel_type() << endl;
            cout << "Car Battery Capacity    : " << battery_capacity << " mAH" << endl;
            cout << "Charge Time (0 to Full) : " << charge_time << " Minutes" << endl;
            cout << "Number of Doors         : " << get_doors() << endl << endl;

        }
        void set_electric_car_details(int& battery,int& charge,int& doors,int& year,string& brand,string& model){
            cout << endl << "         Enter The Electric Car Details    " << endl << endl;
            cout << "Enter Manufacturing Year of Car : ";
            cin >> year;
            cin.ignore();
            cout << "Enter Brand of Car : ";
            getline(cin,brand);
            cout << "Enter Model of car : ";
            getline(cin,model);
            cout << "Enter Number of Doors of Car : ";
            cin >> doors;
            cout << "Enter Battery Capacity of Car (mAH) : ";
            cin >> battery;
            cout << "Enter Charging Time from 0 to full charge (Minutes) : ";
            cin >> charge;
        }

};

int main(){

    int year , doors , battery , charge;
    string brand , model;

    Electric_Car Car1;
    Car1.set_electric_car_details(battery,charge,doors,year,brand,model);
    Car1.set_electric_car_data(battery,charge,doors,year,brand,model);
    Car1.see_car_details();

    return 0;
}
