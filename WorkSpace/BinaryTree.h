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
            Left = NULL;
            Right = NULL;
        }
        T getData() {return Data;}
        void setDaya(T givenData) {Data = givenData;}
};

template <typename T>
class BinaryList{
    private:
        BinaryNode<T>* Root;
    public:
        
};