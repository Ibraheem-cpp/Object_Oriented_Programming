#include<iostream>
#include<fstream>
using namespace std;

class person{
    protected:
        int age;
        string name;
    public:
        person() {cout << "Person Constructor.\n";}

        person(int a , string n) : age(a) , name(n) {}

        virtual void display_info() = 0;

        virtual ~person() {cout << "Person Destructor.\n";} 
};

class student : public person{
    protected:
        int roll_no;
    public:
        student() {cout << "Student Constructor.\n";}

        student(string name , int age , int rollNo) : person(age , name) , roll_no(rollNo) {}

        ~student() {cout << "Student Destructor.\n";}

};

class underGraduate : public student{
    private:
        string degreeName;
    public:
        underGraduate() {cout << "Under Graduate Constructor.\n";}

        underGraduate(string name , int age , int roll_no , string degree) :
                        student(name , age , roll_no) , degreeName(degree) {}

        void display_info() override {
            cout << "Undergraduate Student.\n";
            cout << "Name : " << name << endl;
            cout << "Roll No# : " << roll_no << endl;
            cout << "Age : " << age << endl;
            cout << "Degree : " << degreeName << endl << endl;
        }

        ~underGraduate() {cout << "Under Graduate Destructor.\n";}
};

class Graduate : public student{
    private:
        string degreeName;
    public:
        Graduate() {cout << "Graduate Constructor.\n";}

        Graduate(string name , int age , int roll_no , string degree) :
                        student(name , age , roll_no) , degreeName(degree) {}

        void display_info() override {
            cout << "Graduate Student.\n";
            cout << "Name : " << name << endl;
            cout << "Roll No# : " << roll_no << endl;
            cout << "Age : " << age << endl;
            cout << "Degree : " << degreeName << endl << endl;
        }

        ~Graduate() {cout << "Graduate Destructor.\n";}

};


class professor : public person{
    protected:
        string teaching_subject;
    public:
        professor() {cout << "Professor Constructor.\n";}

        professor(string name , int age , string subject) :
            person(age,name) , teaching_subject(subject) {}

        ~professor() {cout << "Professor Destructor.\n";}
};

class lecturer : public professor{
    private:
        int lectures_in_week;
    public:
        lecturer() {cout << "Lecturer Constructor.\n";}

        lecturer(string name , int age , string subject , int lectures) :
            professor(name,age,subject) , lectures_in_week(lectures) {}

        void display_info() override {
            cout << "Lecturer.\n";
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
            cout << "Subject : " << teaching_subject << endl;
            cout << "Lectures in a Week : " << lectures_in_week << endl << endl;
        }

        ~lecturer() {cout << "Lecturer Destructor.\n";}
};  

class lab_instructor : public professor{
    private:    
        int labs_in_week;
    public: 
        lab_instructor() {cout << "Lab Constructor.\n";}

        lab_instructor(string name , int age , string subject , int labs) : 
            professor(name,age,subject) , labs_in_week(labs) {}

        void display_info() override {
            cout << "Lab Instructor.\n";
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
            cout << "Lab Subject : " << teaching_subject << endl;
            cout << "Labs in a Week : " << labs_in_week << endl << endl;
        }

        ~lab_instructor() {cout << "Lab Destructor.\n";}
};

int main(){

    person* UG1 = new underGraduate("Ibraheem Tahir",20,241,"BS Computer Science");
    person* G1 = new Graduate("Umer Zulfiqar",19,236,"MS Computer Science");
    person* L1 = new lecturer("Asif Haroon",45,"Discrete Structures",5);
    person* LI1 = new lab_instructor("Fraz Aslam",25,"Computing Lab",2);

    UG1->display_info();
    G1->display_info();
    L1->display_info();
    LI1->display_info();

    delete UG1;
    delete G1;
    delete L1;
    delete LI1;

    return 0;
}