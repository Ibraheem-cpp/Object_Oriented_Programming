#include<iostream>
#include<string>
using namespace std;

class player{
    private:
        string GamerTag;
        const int MAX_HP = 100;
        int HP;
        bool valid_gamertag(string name1);
    public:
        void show_Data(){
            cout << "Your In Game Name : " << GamerTag << endl;
            cout << "Your Current Health : " << HP << endl;
        }
        void set_Data(string name1);


};
void player :: set_Data(string name1){
    
    if(valid_gamertag(name1) == true){
        GamerTag = name1;
    }

    else {
     cout << "Invalid Gamer Tag.";
     exit(0);
    }

    HP = MAX_HP;
}

bool player :: valid_gamertag(string name1){
    for(int i=0;i<name1.length();i++){
        if((name1.at(i) < 'a' || name1.at(i) > 'z') && (name1.at(i) < 'A' || name1.at(i) > 'Z') && name1.at(i) != '_' && name1.at(i) != '-' && name1.at(i) != ' '){
           return false;
        }
    }
    return true;
}


int main(){

    player p1;
    string name;
    cout << "Enter Your Gamer Tag : ";
    getline(cin,name);
    p1.set_Data(name);
    p1.show_Data();

    return 0;
}

