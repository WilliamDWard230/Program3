#include "pokemone.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream>


int main()
{
    int sID;
    int count;
    int menuChoice;
    int ID;
    string Name;
    string fN;
    Pokemone* tempPoke = new Pokemone;

    BinaryTree<Pokemone> Tree;
    BinaryTree<Pokemone>* Root;
    std::string fileString;
    std::ifstream file("pokedex.txt");
    file >> fileString;

    do{
        cout << "\n1: Read in a pokedex file." << endl;
        cout << "2: Add a Pokemon." << endl;
        cout << "3: Print the pokedex." << endl;
        cout << "4: Delete a pokemon from the pokedex." << endl;
        cout << "5: Exit." << endl;

        cin >> menuChoice;

        switch(menuChoice){
            case 1:
                std::cout << "Enter in the file \n";
                std::cin >>fN;
                count = Tree.readInPokemon(fileString);
                break;
            case 2:
                std::cout << "Enter the Pokemon's ID. \n";
                std::cin >> ID;
                std::cout << "Enter the Pokemon's name. \n";
                std::cin >> Name;

                *tempPoke = Pokemone(ID,Name);
                Tree.insertNode(*tempPoke);
                count++;
                break;
            case 3:
                Tree.printInOrder(Tree.getRoot());
                cout << "\nThere are " << count << " pokemon in the pokedex. \n";
                break;
            case 4:
                std::cout << "Enter the Pokemon's ID to be deleted. \n";
                std::cin >> ID;
                std::cout << "Enter the Pokemon's name to be deleted. \n";
                std::cin >> Name;

                *tempPoke = Pokemone(ID,Name);
                Tree.deleteNode(*tempPoke, Tree.getRoot());
                count--;
                break;
            case 5:
                std::cout << "\nHave a nice day!";
                break;
        }
    } while(menuChoice !=5);

    return 0;

}