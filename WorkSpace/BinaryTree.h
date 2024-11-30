#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "pokemone.h"
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree{
    private:
        struct BinaryNode{  //node struct
            T value;
            BinaryNode* Left;
            BinaryNode* Right;
        };

        BinaryNode* Root;
        //inserts node
        void insert(BinaryNode *&nodePtr, BinaryNode *&newNode){
            if (nodePtr == NULL)
                nodePtr = newNode;
            else if (newNode->value < nodePtr->value)
                insert(nodePtr->Left, newNode);
            else
                insert(nodePtr->Right, newNode);
        }
        //deletes tree
        void destroySubtree(BinaryNode *nodePtr)
        {
            if (nodePtr)
            {
                if (nodePtr->left)
                    destroySubTree(nodePtr->left);
                if (nodePtr->right)
                    destroySubTree(nodePtr->right);
                delete nodePtr;
            }
        }
        //called in public function to print tree
        void displayInOrder(BinaryNode *nodePtr)
        {
            
            if(nodePtr)
            {
                displayInOrder(nodePtr->Left);
                cout << nodePtr->value.getID() << ".\t" << nodePtr->value.getName() << endl;
                
                displayInOrder(nodePtr->Right);  
            }
        }

    public:
    //constructor
        BinaryTree(){
            Root = NULL;

        }
        BinaryNode* getRoot() {return Root;}
        //inserts a node
        void insertNode(Pokemone newPokemon){
            BinaryNode *newNode = new BinaryNode;

            if(this->searchPokemon(newPokemon))
            {
                cout << "Oops! " << newPokemon.getName() << " is already in the tree." << endl;
            }
            else{
            newNode->value = newPokemon;
            newNode->Left = NULL;
            newNode->Right = NULL;

            insert(Root, newNode);
            }

        }
        //reads in file of pokemon and creates tree
        int readInPokemon(string testString){

            string Name;
            string ID;
            int count = 0;

            while ((testString.find('#')) != std::string::npos) 
            {   
            int IDEnd = testString.find('#');
            ID = testString.substr(0, IDEnd);
            testString.erase(0, IDEnd +1);

            int nameEnd = testString.find('#');
            Name = testString.substr(0,nameEnd);
            testString.erase(0, nameEnd+1);

            int cID = stoi(ID);

            Pokemone* tempPoke;
            tempPoke = new Pokemone(cID,Name);
            if(!this->searchPokemon(*tempPoke))
            {
                count++;
            }
            cout << "Inserting Pokemon with index " << tempPoke->getID() << " into the Pokedex." << endl;
            insertNode(*tempPoke);
            
            }

            return count;
        }
        //Prints the binary tree
        void printInOrder(BinaryNode* nodePtr)
        {
            cout << endl;
            cout << "************************ Pokedex ************************" << endl;
            displayInOrder(nodePtr);
        }
        //adds a node to the tree
        void addAPokemon(){
            string Name;
            int ID;

            cout << "What is the pokemone's name?";
            cin >> Name;
            cout << "What is " << Name << "'s ID?";
            cin >> ID;

            Pokemone* tempPoke = new Pokemone(ID, Name);
            insertNode(tempPoke);
        }
        //returns if the searched node is in tree
        bool searchPokemon(Pokemone searchPokemon)
        {
            BinaryNode *nodePtr = Root;

            while (nodePtr)
            {
                if (nodePtr->value == searchPokemon)
                    return true;
                else if (searchPokemon < nodePtr->value)
                    nodePtr = nodePtr->Left;
                else
                    nodePtr = nodePtr->Right;
            }
            return false;
        }
        //deletes node
        void deleteNode(Pokemone pokemon, BinaryNode *nodePtr)
        {
            if (pokemon < nodePtr->value)
                deleteNode(pokemon, nodePtr->Left);
            else if (pokemon.getID() > nodePtr->value.getID())
                deleteNode(pokemon, nodePtr->Right);
            else
                deleteAndR(nodePtr);
        }
        //called in delete node to reattach tree nodes
        void deleteAndR(BinaryNode *&nodePtr)
        {

            BinaryNode *tempNodePtr = NULL;

            if (nodePtr == NULL)
                cout << "Cannot delete empty node.\n";
            else if (nodePtr->Right == NULL)
            {
                tempNodePtr = nodePtr;
                nodePtr = nodePtr->Left;   
                delete tempNodePtr;
            }
            else if (nodePtr->Left == NULL)
            {
                tempNodePtr = nodePtr;
                nodePtr = nodePtr->Right;
                delete tempNodePtr;
            }
        
            else
            {

                tempNodePtr = nodePtr->Right;

                while (tempNodePtr->Left)
                    tempNodePtr = tempNodePtr->Left;

                tempNodePtr->Left = nodePtr->Left;
                tempNodePtr = nodePtr;

                nodePtr = nodePtr->Right;
                delete tempNodePtr;
            }
        }

};

#endif