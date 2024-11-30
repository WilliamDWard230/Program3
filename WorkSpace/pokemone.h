#ifndef POKEMONE_H
#define POKEMONE_H
#include <iostream>
using namespace std;

class Pokemone{
    private:
        int ID;
        string Name;
    public:

        //constructor
        Pokemone(){
            ID = 6969;
            Name = "Frodo";
        }
        Pokemone(int givenID, string givenName){
            ID = givenID;
            Name = givenName;
        }
        //getters and setters
        int getID();
        void setID(int givenID);
        string getName();
        void setName(string givenName);

        // overloaded operators
        bool operator<(Pokemone &right_comparison) { return this->ID < right_comparison.ID;}
        bool operator==(Pokemone &right_comparison) { return this->ID == right_comparison.ID; }
        friend ostream &operator<<(ostream &os, Pokemone &aPoke) //overloaded << operator 
    {
        os << "The pokemone " << aPoke.Name << " is in the pokedex" << endl;
        return os;
    }
};

//function definitions

int Pokemone::getID(){return ID;}
void Pokemone::setID(int givenID) {ID = givenID;}
string Pokemone::getName() {return Name;}
void Pokemone::setName(string givenName) {Name = givenName;}



#endif