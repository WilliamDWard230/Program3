#include <iostream>
using namespace std;

template <typename T>
class BinaryNode{
    private:
        T Data;
        BinaryNode<T>* Left;
        BinaryNode<T>* Right;
    public:
        BinaryNode(){
            Left = NULL;
            Right = NULL;
        }
        BinaryNode(T givenData){
            Data = givenData;
        }
        void insertNode() {}
};