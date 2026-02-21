#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

class character{
    protected:
        string name;
        string attack_type;
        string special_attack;
        int attack_power;
        int stamina = 11;
        int max_stamina = 11;
        int health;
        int max_health;
    public:
        character() {}

        character(string n , string AT , string ST , int AP , int HP , int maxHP) 
            : name(n) , attack_type(AT) , special_attack(ST) , attack_power(AP) , health(HP) , max_health(maxHP) {}

        virtual void speak() = 0;

        void display_details(){
            cout << "Name           : " << name << endl;
            cout << "Attack Type    : " << attack_type << endl;
            cout << "Special Attack : " << special_attack << endl;
            cout << "Attack Power   : " << attack_power << endl;
            cout << "Stamina        : " << stamina << endl;
            cout << "Health         : " << health << endl << endl;
        }

        void player_attack(character* enemy){
            cout << endl << "                   YOUR TURN" << endl << endl;
            int attack;
            do{
            cout << endl << "Choose Your Attack : \n"
                         << "1. Light Attack   :   1 Stamina\n"
                         << "2. Heavy Attack   :   2 Stamina\n"
                         << "3. Special Attck  :   4 Stamina\n\n"
                         << "Enter Attack : ";
            cin >> attack;
            }while(!(valid_attack(attack)));

            if(attack == 1){
                if(this->stamina - 1 < 0){cout << "\n Not Enough Stamina.\n";}
                else {
                    cout << "\nLight Attack Used.\n\n";
                    cout << "       Player  -1 Stamina\n";
                    cout << "       Enemy   -" << (this->attack_power) << " Health\n";
                    enemy->health = enemy->health - this->attack_power;
                    this->stamina = this->stamina - 1;
                }
            }
            else if(attack == 2){
                if(this->stamina - 2 < 0){cout << "\n Not Enough Stamina.\n";}
                else {    
                    cout << "\nHeavy Attack Used.\n\n";
                    cout << "       Player  -2 Stamina\n";
                    cout << "       Enemy   -" << (this->attack_power + 1) << " Health\n";
                    enemy->health = enemy->health - (this->attack_power + 1);
                    this->stamina = this->stamina - 2;
                }
            }
            else if(attack == 3){
                if(this->stamina - 4 < 0){cout << "\n Not Enough Stamina.\n";}
                else {             
                    cout << endl << this->special_attack << " Used.\n\n";
                    cout << "       Player  -4 Stamina\n";
                    cout << "       Enemy   -" << (this->attack_power + 3) << " Health\n";
                    enemy->health = enemy->health - (this->attack_power + 3);
                    this->stamina = this->stamina - 4;
                }
            }
        }

        void enemy_attack(character* player){
            cout << endl << "                   ENEMY TURN" << endl << endl;
            int attack = (rand() % 3) + 1;
            if(attack == 1){
                cout << "Enemy Used Light Attack.\n\n";
                cout << "       Player  -" << this->attack_power << " Health\n";
                player->health = player->health - this->attack_power; 
            }
            else if(attack == 2){
                cout << "Enemy Used Heavy Attack.\n\n";
                cout << "       Player  -" << (this->attack_power + 1) << " Health\n";
                player->health = player->health - (this->attack_power + 1); 
            }
            else if(attack == 3){
                cout << "Enemy Used " << this->special_attack << "\n\n";
                cout << "       Player  -" << (this->attack_power + 3) << " Health\n";
                player->health = player->health - (this->attack_power + 3); 
            }

        }

        bool valid_attack(int attack){
            if(attack == 1 || attack == 2 || attack == 3){return true;}
            return false;
        }

        int get_health() const {
            return this->health;
        }

        int get_stamina() const {
            return this->stamina;
        }

        int get_MAX_health() const {
            return this->max_health;
        }

        int get_MAX_stamina() const {
            return this->max_stamina;
        }

        const string get_name() const {
            return this->name;
        }


        virtual ~character() = default;    
};

class warrior : public character{
    public:
        warrior() {}

        warrior(string name) : 
            character(name,"Melee Attacker","Dragon Fang Strike",2,25,25) {}

        void speak() override {
            cout << "Thanks for Choosing me. I am a warrior and my sword will not let you down.\n";
        }

        ~warrior() override = default;
};

class mage : public character{
    public:
        mage() {}

        mage(string name) : 
            character(name,"Magic User","Abyssal Flame",3,21,21) {}

        void speak() override {
            cout << "So, you like magic, then OK, this staff of mine will show you a lot of magic.\n";
        }

        ~mage() override = default;

};

class archer : public character{
    public:
        archer() {}
 
        archer(string name) : 
            character(name,"Ranged Attacker","Phantom Shot",4,19,19) {}

        void speak() override{
            cout << "With me, the enemy won't know what hit them, my arrow never misses.\n";
        }

        ~archer() override = default;

};



class game{
    private:
        character* player;
        character* enemy;
        string name;
    public:
        game() {}

        void start_playing(){
            
            cout << "\n                             | WELCOME TO A  1 Vs 1  GAME |" << endl << endl;
            cout << "Enter Your In Game Name : ";
            getline(cin,this->name);
            
            select_player();
            cin.ignore();
            wait();
            cout << "\033[2J\033[1;1H";
            select_enemy();
            cin.ignore();
            wait();
            cout << "\033[2J\033[1;1H";

            do{

                combat_HUD();
                player->player_attack(enemy);
                cin.ignore();
                wait();
                cout << "\033[2J\033[1;1H";

                if(enemy->get_health() > 0){
                    enemy->enemy_attack(player);
                    wait();
                    cout << "\033[2J\033[1;1H";
                }

            }while(!(game_over()));

            game_result();

            play_again();
        }

        void select_player(){
            int choice;
            do{
                cout << "Choose a Player : \n\n";
                cout << " 1. Warrior  : More Health , Less Attack Power.\n"
                     << " 2. Mage     : Medium Health , Good Attack Power.\n"
                     << " 3. Archer   : Less Health , Great Attck Power.\n\n";
                cout << "Enter Player Number : ";
                cin >> choice;
            }while(choice != 1 && choice != 2 && choice != 3);

            cout << endl;

            switch (choice)
            {
                case 1:
                    player = new warrior(name);
                    break;
                case 2:
                    player = new mage(name);
                    break;
                case 3:
                    player = new archer(name);
                    break;
                default:
                   break;
            }
            player->speak();
            cout << endl;
            player->display_details();
        }

        void select_enemy(){
            int choice;
             do{
                cout << "Choose Your Enemy : \n\n";
                cout << " 1. Warrior.\n"
                     << " 2. Mage.\n"
                     << " 3. Archer.\n\n";
                cout << "Enter Enemy Number : ";
                cin >> choice;
            }while(choice != 1 && choice != 2 && choice != 3);

            cout << endl;
            string enemyName = "COMPUTER";

            switch (choice)
            {
                case 1:
                    enemy = new warrior(enemyName);
                    break;
                case 2:
                    enemy = new mage(enemyName);
                    break;
                case 3:
                    enemy = new archer(enemyName);
                    break;
                default:
                   break;
            }
            cout << endl;
            enemy->display_details();
        }

        void combat_HUD(){
                cout << "\n                             | " << enemy->get_name() << " HEALTH  : " << enemy->get_health() << "/" << enemy->get_MAX_health() << " |\n";
                cout << "                 -------------------------------------------------------\n";
                cout << "                             | " << player->get_name() << " HEALTH  : " << player->get_health() << "/" << player->get_MAX_health() << " |\n";
                cout << "                             | " << player->get_name() << " STAMINA : " << player->get_stamina() << "/" << player->get_MAX_stamina() << " |\n\n";
        }

        bool game_over(){
            if(player->get_health() <= 0 || enemy->get_health() <= 0){
                cout << "\n                 GAME OVER !!!\n";
                return true;
            }
            return false;
        }

        void game_result(){
            if(enemy->get_health() <= 0){
                cout << "\n         " << player->get_name() << " WON the Game :) \n\n";
                cout << "           CONGRATULATIONS !!!!\n\n";
            }
            else{
                cout << "\n         " << enemy->get_name() << " WON the Game :( \n\n";
                cout << "           BETTER LUCK NEXT TIME !!\n\n";
            }
        }

        void wait(){
            cout << endl << " Press Enter To Continue.";
            cin.get();
        }

        void play_again(){
            char choice = 'y';
            cout << "\n\n   Do You Want to Play Again ? (y/n) : ";
            cin >> choice;
            cin.ignore();
            if(choice == 'y' || choice == 'Y'){start_playing();}
            else{
                cout << "\n\n                 THANKS FOR PLAYING :)\n\n";
            }
        }

        ~game(){
            delete player;
            delete enemy;
        }

};




int main(){
    
    srand(time(0));

    game Game;
    Game.start_playing();

    return 0;
}