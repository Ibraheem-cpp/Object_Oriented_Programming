#include<iostream>
using namespace std;

class enemy{
     public:
     string type;
     int damage;
     int health;
     string special_attack;
   
     enemy(){
        type = "Normal";
        damage = 50;
        health = 100;
        special_attack = " No special attack";
     }

     void show_data(){
        cout << "ENEMY TYPE : " << type << endl;
        cout << "Damage : " << damage << endl;
        cout << "Health : " << health << endl;
        cout << "Special Attack : " << special_attack << endl;
     }
};

class dragon : enemy{
    string name  = "ALDUIN";
    public:
    dragon(){
        type = "Dragon";
        special_attack = "Fire Breath";
        health = 200;
        damage = 20;
        //show_data();
    }
    void special_attack1(){
        cout << "\nThe Dragon Used " << special_attack;
        cout << "\n      -50 HP\n";
    }
    void show_data2(){
        show_data();
        cout << "DRAGON NAME : " << name;
    }
};

class werewolf : enemy{
    public:
        werewolf(){
            type = "Werewolf";
            special_attack = "TEARING CLAW";
            health = 250;
            damage = 30;
            show_data();
        }
        void special_attack1(){
            cout << "\nThe Werewolf Used " << special_attack;
            cout << "\n        -60 HP\n";
        }
        
};

int main(){

    enemy e1;
    e1.show_data();
    cout << endl;
    dragon d1;
    d1.show_data2();
    d1.special_attack1();
    cout << endl;
    werewolf w1;
    //w1.show_data();
    w1.special_attack1();

    return 0;
}