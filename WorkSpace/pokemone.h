#include <iostream>
using namespace std;

class Pokemone{
    private:
        int ID;
        string Name;
    public:
        Pokemone(){
            ID = 6969;
            Name = "Frodo";
        }
        Pokemone(int givenID, string givenName){
            ID = givenID;
            Name = givenName;
        }
        int getID();
        void setID(int givenID);
        string getName();
        void setName(string givenName);
};

int Pokemone::getID(){return ID;}
void Pokemone::setID(int givenID) {ID = givenID;}
string Pokemone::getName() {return Name;}
void Pokemone::setName(string givenName) {Name = givenName;}