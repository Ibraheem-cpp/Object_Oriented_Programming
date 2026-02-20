#include<iostream>
#include<fstream>
using namespace std;

class vehicle{
    public:
        string type;
        int id;
        int year;
        string model;
    public:
        vehicle(){}
        vehicle(string t , int i , int y , string m) : type(t) , id(i) , year(y) , model(m) {}
        vehicle(const vehicle& other){
            this->type = other.type;
            this->id = other.id;
            this->year = other.year;
            this->model = other.model;
        }

        virtual void display() = 0;
        virtual void input_details() = 0;
        virtual vehicle* clone() const = 0;
        virtual void save_file(ofstream& file) = 0;
    
        virtual ~vehicle(){
            //cout << "Vehicle Destroyed.\n";
        }
};

class Car : public vehicle{
    private:
       int car_id;
       int doors;
    public:
       
        Car(){}
        Car(string t , int i , int y , string m , int i_c , int d) : vehicle(t,i,y,m) , car_id(i_c) , doors(d) {}
        Car(const Car& other){
            Car* temp = new Car(other.type,other.id,other.year,other.model,other.car_id,other.doors);
            *this = *temp;
        }

        void display() override {
           cout << '\n';
            cout << model << " " << year << " " << doors << " " << car_id << " " << id;
            cout << '\n';
        }
        void input_details() override {
            cout << "Enter Car Details.\n";
        }
        void save_file(ofstream& file) override{
            file << this->car_id << " " << this->doors << endl;
        }
        vehicle* clone() const override {
          return new Car(*this); // Copy constructor
        }

        ~Car(){
           // cout << "Car Destroyed.\n";
        }
};  

class Bike : public vehicle{
    public:
        int bike_id;
        string body_type;
    public:
    
        Bike(){}
        Bike(string t , int i , int y , string m , int i_b , string body) : vehicle(t,i,y,m) , bike_id(i_b) , body_type(body) {}
        Bike(const Bike& other){
            
            Bike* temp = new Bike(other.type,other.id,other.year,other.model,other.bike_id,other.body_type);
            *this = *temp;
        }
       
        void display() override {
            cout << '\n';
            cout << model << " " << year << " " << body_type << " " << bike_id;
            cout << '\n';
        }
        void input_details() override {
            cout << "Enter Bike Details.\n";
        }
        void save_file(ofstream& file) override {
            file << this->bike_id << " " << this->body_type << endl;
        }
        vehicle* clone() const override {
            return new Bike(*this); // Copy constructor
        }
        ~Bike(){
            //cout << "Bike Destroyed.\n";
        }
};


class garage{
    private:
        vehicle** vehicles;
        int current_vehicles=0;
        int max_vehicles;
    public:
        garage(){
           
        }
        void load_file(){
            int current_v , max_v;
            ifstream file1;
            file1.open("vehicles.txt");
            if(!file1){
                cout << "Error Opening File !\n";
                return;
            }
            file1 >> current_v >> max_v;
            max_vehicles = max_v;
            vehicles = new vehicle*[max_vehicles];
            string t , m;
            int i_d , y;
            for(int i=0;i<current_v;i++){
                file1 >> t >> i_d >> y >> m;
                if(t == "Car" || t == "car"){
                    int c_id , d;
                    file1 >> c_id >> d;
                    vehicles[current_vehicles] = new Car(t,i_d,y,m,c_id,d);
                    current_vehicles++;
                }
                else if(t=="Bike" || t == "bike"){
                    int b_id;
                    string body_t;
                    file1 >> b_id >> body_t;
                    vehicles[current_vehicles] = new Bike(t,i_d,y,m,b_id,body_t);
                    current_vehicles++;
                }
            }

            file1.close();
        }
        void save_to_file(){
            ofstream file;
            file.open("vehicles.txt");
            if(!file){
                cout << "Error Opening File !\n";
                return;
            }
            file << current_vehicles << endl << max_vehicles << endl;
            for(int i=0;i<current_vehicles;i++){
                file << vehicles[i]->type << " " << vehicles[i]->id << " " << vehicles[i]->year << " " << vehicles[i]->model << " ";
                vehicles[i]->save_file(file);
            }
            file.close();
        }
        void show_all(){
            for(int i=0;i<current_vehicles;i++){
                vehicles[i]->display();
            }
        }
        void input_details(){
            for(int i=0;i<2;i++){
                vehicles[i]->input_details();
            }
        }
        void expand_garage(){
            vehicle** temp = new vehicle*[max_vehicles+1];
            for(int i=0;i<current_vehicles;i++){
                temp[i] = vehicles[i]->clone();
            }
            for(int i=0;i<current_vehicles;i++){
                delete vehicles[i];
            }
            delete[] vehicles;
            max_vehicles++;
            vehicles = temp;
            
        }
        void add_car(){
            vehicles[current_vehicles] = new Car("Car",3,2025,"Toyota",5,4);
            current_vehicles++;
        }
        ~garage(){
           for(int i=0;i<current_vehicles;i++){
            delete vehicles[i];
           }
           delete[] vehicles;
           vehicles = nullptr;
        }
        
};


int main(){

    garage* g1 = new garage;
    g1->load_file();
    g1->show_all();
    g1->expand_garage();
    g1->add_car();
    g1->show_all();
    g1->save_to_file();

    delete g1;

    return 0;
}
