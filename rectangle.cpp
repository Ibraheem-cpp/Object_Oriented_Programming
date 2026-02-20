#include<iostream>
#include<fstream>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------

class animal{
    protected:
        int legs;
    public:
        animal(int l) : legs(l) {}

        virtual void makeSound(){
            cout << "Hello.\n";
        }
};

class dog : public animal{
    public:
        dog() : animal(4) {}

        void makeSound() override {
            cout << "Bow !!\n" << legs << endl;
        }
};

class cat : public animal{
    public:
        cat() : animal(4) {}

        void makeSound() override {
            cout << "Meow !!\n" << legs << endl;
        }
};

//----------------------------------------------------------------------------------------------------------------

class shape{
    protected:
        string name;
    public:
        shape(string n) : name(n) {}
        
        virtual void calculate_area() = 0;

        virtual void calculate_perimeter() = 0;
};

class rectangle : public shape{
    private:
        int length , width;
    public:
        rectangle(int l , int w) : shape("Rectangle") , length(l) , width(w) {}

        void calculate_area() override {
            cout << name << endl;
            cout << "Area : " << length * width << endl;
        }

        void calculate_perimeter() override {
            cout << "Perimeter : " << 2  * (length + width) << endl;
        }
};

class circle : public shape{
    private:
        int radius;
    public:
        circle(int r) : shape("Circle") , radius(r) {}

        void calculate_area() override {
            cout << name << endl;
            cout << "Area : " << 3.14 * radius * radius << endl;
        }

        void calculate_perimeter() override {
            cout << "Perimeter : " << 2 * 3.14 * radius << endl;
        }

};

//----------------------------------------------------------------------------------------------------------------------------

class employee{
    protected: 
        int salary;
    public:
    
        employee(int s) : salary(s) {}

        virtual void getSalary() = 0;

        virtual ~employee(){
            //cout << "Employee Destructor.\n\n";
        }

};

class fullTimeEmployee : public employee{
    private:
        int months_worked;
    public:
        fullTimeEmployee(int months) : employee(months * 30000) , months_worked(months) {}

        void getSalary() override {
        
            cout << "Full Time Employee.\n";
            cout << "Months Worked : " << months_worked << endl;
            cout << "Total Salary : " << salary << endl;
        }

        ~fullTimeEmployee() {
            //cout << "Full Time Employee Destructor.\n\n";
        }
};

class partTimeEmployee : public employee{
    private:
        int no_of_hours;
    public:
        partTimeEmployee(int hours) : employee(hours * 100) , no_of_hours(hours) {}

        void getSalary() override {
            
            cout << "Part Time Employee.\n";
            cout << "Hours Worked : " << no_of_hours << endl;
            cout << "Total Salary : " << salary << endl;
        }

        ~partTimeEmployee() {
            //cout << "Part Time Employee Destructor.\n\n";
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------------------

class person{
    protected:
        string name;
        int age;
    public:
        person(){}

        person(string n , int a) : name(n) , age(a) {}

        virtual void display_info(){
            cout << "Person : \n";
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl << endl;
        }

};

class student : public person{
    protected:  
        int roll_no;
    public:
        student(){}

        student(string n , int a , int r) : person(n,a) , roll_no(r) {}

        void display_info() override {
            cout << "Student : \n";
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
            cout << "Roll No : " << roll_no << endl << endl;
        }
};

class graduateStudent : public student{
    protected:
        string thesis_topic;
        int marks_obtained;
    public:
        graduateStudent(){}

        graduateStudent(string n , int a , int r , string thesis , int m) :
            student(n,a,r) , thesis_topic(thesis) , marks_obtained(m) {}

        void display_info() override {
            cout << "Graduate Student : \n";
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
            cout << "Roll No : " << roll_no << endl;
            cout << "Thesis Topic : " << thesis_topic << endl;
            cout << "Marks Obtained : " << marks_obtained << endl << endl; 
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------------




int main(){

    person* p1 = new graduateStudent("Ibraheem",20,345,"Comp Science",99);
    
    p1->display_info();
    

    return 0;
}