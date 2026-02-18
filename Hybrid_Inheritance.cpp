#include<iostream>
using namespace std;

/*
                                |--------> Derived Class (B) -------|
                                |                                   |
         Base Class (A) --------|                                   |------> Further Derived Class (D)        
                                |                                   |
                                |--------> Derived Class (C) -------|

    Note : There is no fix hierarchy of Hybrid Inheritance, it's just a combination of different 
           types of inheritances. 
*/

class Character{
    protected:
        string Type;
        int Health;
        int Level;
        Character(string t , int h , int l) : Type(t) , Level(l) , Health(h){}

        void show_stats(){
            cout << " Player Class    : " << this->Type << endl;
            cout << " Player Health   : " << this->Health << endl;
            cout << " Player Level    : " << this->Level << endl;
        }
   
};

class MagicUser : virtual protected Character{
    protected:
        int Mana;
    public:
        
        MagicUser(int m) : Character("Magic User",80,1) , Mana(m){}
        
            
        void cast_regen_spell(){
            cout << "The Player has casted a Regeneration Spell.\n"
                 << "      Player : +5 Health \n"
                 << "      Player : -5 Mana \n" << endl;
            this->Mana-=5;
            this->Health+=5;
        }
        void cast_fire_spell(){
            cout << "The Player has casted a Fire Spell.\n"
                 << "      Enemy  : -10 Health \n"
                 << "      Player : -5  Mana \n" << endl;
            this->Mana-=5;
        }
        void speak(){
            cout << "I am a Magic User. I can cast Wonderful and Deadly Spells.\n";
        }
};

class Warrior : virtual protected Character{
    protected:
        int Stamina;
    public:
        Warrior(int s) : Character("Warrior",100,1) , Stamina(s){}
        
           
        void swing_light_sword(){
            cout << "The Player swung the Sword lightly.\n"
                 << "      Enemy  : -5 HP\n"
                 << "      Player : -5 Stamina\n";
            this->Stamina-=5;
        }
        void swing_heavy_sword(){
            cout << "The Player swung the Sword heavily.\n"
                 << "      Enemy  : -10 HP\n"
                 << "      Player : -10 Stamina\n";
            this->Stamina-=10;
        }
        void speak(){
            cout << "I am a Warrior. Be careful around me, this Sword won't have mercy on anyone.\n";
        }
        void show_details(){
            cout << this->Type << '\n' << this->Health << '\n' << this->Level << '\n' << this->Stamina << '\n';
        }
};

class BattleMage : public Warrior , public MagicUser{
    public:
        BattleMage() :  MagicUser(40) , Character("Battle Mage",110,1) , Warrior(50){}
           
            
        void speak(){
            MagicUser :: speak();
            Warrior :: speak();
            cout << "So, I am a Battle Mage, Beware !!!\n";
        }
        void show_stats(){
            Character :: show_stats();
            cout << " Player Mana     : " << this->Mana << endl;
            cout << " Player Stamina  : " << this->Stamina << endl;
        }
};

int main(){

    cout << endl;

    BattleMage* Paladin = new BattleMage;
    Paladin->speak();
    cout << '\n'; 
    Paladin->cast_fire_spell();
    cout << '\n';   
    Paladin->cast_regen_spell();
    cout << '\n'; 
    Paladin->swing_light_sword();
    cout << '\n';   
    Paladin->swing_heavy_sword();
    cout << '\n';   
    Paladin->show_stats();
    
    delete Paladin;
    Paladin = nullptr;

    cout << endl;

    return 0;
}