#include<iostream>
using namespace std;

//                             Base Class (A) --------> (Derived Class) B 

class parent{
    int data0;
    
    protected:
        int data1;
        int data2;
    public:
        
        void set_data(){
            data1 = 10;
            data2 = 20;
        }
        int getdata1(){
            return data1;
        }
        int getdata2(){
            return data2;
        }
};

class child : protected parent{
    int data3;
    public:
        child(){
            data3 = 1;
        }
        void show_data(){
            cout << "Data 1 : " << getdata1() << endl;
            cout << "Data 2 : " << data2 << endl;
            cout << "Data 3 : " << data3 << endl;
        }
        void process_data(){
            set_data();
            data3 = getdata1() * data2;
        }
        void show_data1(){
            cout << data1;
        }
        
};

int main(){

    parent p1;
    child c1;
    //c1.set_data();
    // cout << p1.data1;
    // cout << c1.data1;
    //c1.getdata1();
    c1.process_data();
    c1.show_data();
    //cout << c1.data1;
    
    return 0;
}