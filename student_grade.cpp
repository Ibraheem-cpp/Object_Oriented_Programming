#include<iostream>
#include<string>
using namespace std;

const int SUBJECTS = 5;

class student{
    private:
        string name;
        int RollNo;
        int marks[SUBJECTS];
        char grade;
        float average;
        float obtained_marks;
        
    public:
        student(){
            name=" ";
            RollNo = 0;
            marks[SUBJECTS] = {0};
            grade = 'Z';
            obtained_marks = 0;
            average = 0.0;
        }
        void enter_info(){
            cout << "Enter Student Name : ";
            getline(cin,name);
            cout << "Enter Roll Number : ";
            cin >> RollNo;
            cout << "Enter Marks for Subjects (out of 100) : " << endl;
            for(int i=0;i<SUBJECTS;i++){
                do{
                cout << " Enter Subject " << i+1 << " Marks : ";
                cin >> marks[i];
                }while(marks[i] < 0 || marks[i] > 100);
            }
            cin.ignore();
        }
        void student_average(){
            int Total_marks = 100*SUBJECTS;
            for(int i=0;i<SUBJECTS;i++){
                obtained_marks = obtained_marks + marks[i];
            }
            average = obtained_marks/SUBJECTS;
            
        }
        void student_grade(){
            if(average >= 90){grade = 'A';}
            else if(average >=80 && average <=89){grade = 'B';}
            else if(average >=70 && average <=79){grade = 'C';}
            else if(average >=60 && average <=69){grade = 'D';}
            else if(average < 60){grade = 'F';}
        }
        void show_details(){
            cout << endl << "       STUDENT DETAILS    " << endl;
            cout << " Student Name    : " << name << endl;
            cout << " Student Roll No : " << RollNo << endl;
            cout << " Total Marks     : " << SUBJECTS*100 << endl;
            cout << " Obtained Marks  : " << obtained_marks << endl;
            cout << " Average         : " << average << endl;
            cout << " Grade           : " << grade << endl;
        }
        int get_RollNo() const {
            return RollNo;
        }
        
};

int main(){

    const int T_S = 2;
    student students[T_S];
    for(int i=0;i<T_S;i++){
        cout << "  Enter Student " << i+1 << " Details : " << endl;
        students[i].enter_info();
        cout << endl;
    }
    for(int i=0;i<T_S;i++){
        students[i].student_average();
        students[i].student_grade();
    }
    cout << "Currently Enrolled Students : " << endl;
    for(int i=0;i<T_S;i++){
        cout << " Roll No : " << students[i].get_RollNo() << endl;
    }
    int roll;
    bool found = false;
    do{
        cout << endl << "Which Student Data Do You Wish To See ? Enter Roll No : ";
        cin >> roll;
        for(int i=0;i<T_S;i++){
            if(roll == students[i].get_RollNo()){
                found = true;
                students[i].show_details();
                break;
            }
        }
      if(!found){cout << "Student Does Not Exist." << endl;}

    }while(!found);

    return 0;
}