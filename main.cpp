//
//  main.cpp
//  Tarea Programada
//
//  Created by Javi Donato on 10/4/20.
//

#include <iostream>

class Symbol{
    public:
    char symbol;
    int count;
};
class CodingTree{
    public:
        class BinaryNode{
            public:
            int count;
            char symbol;
            BinaryNode *left, *right;
            BinaryNode(char c, int p){
                symbol =c;
                left=0;
                right=0;
                count = p;
            }
            ~BinaryNode (){
                if (left) {
                    delete left;
                }
                if (right) {
                delete right;
        }
    
    }
            int index=0;
            bool inOrder(BinaryNode* r, char c, char* code){
                bool encode =false;
                if (r != NULL) {
                    if (r->symbol ==c) {
                        encode = true;
                        return encode;
                    } else{
                        code [index]= 0;
                        index++;
                        inOrder(r ->left, c, code);
                        code[index] = 1;
                        index++;
                        inOrder(r->right, c, code);
                        
                        
                    }
                }
                return encode;
            }
            
            unsigned int countMethod(BinaryNode* r){
                unsigned int suma=0;
                if (r!= NULL) {
                    while (r->left || r->right) {
                        suma =suma + r->count;
                        countMethod(r->left);
                        countMethod(r->right);
                    }
                }
                return suma;
            }
        };
    BinaryNode *root;
public:
    CodingTree(){
        root =0;
    }
    ~CodingTree(){
        if (root) {
            delete root;
        }
    }
    void insert(char c, int p){
        if(root){
            BinaryNode* temp = root;
            while ((c < temp->symbol && temp->left) || (c > temp->symbol && temp ->right)) {
                if(c < temp->symbol){
                    temp = temp->left;
                }else {
                    temp = temp->right;
                    
                }
            }
            if(c != temp->symbol){
                if(c < temp->symbol){
                    temp->left = new BinaryNode(c, p);
                }else{
                    temp->right = new BinaryNode(c, p);
                }
            }
        }else{
            root = new BinaryNode(c, p);
            
        }
    }
    
    bool encode(char* code, char c){
      bool encode= (root->inOrder(root, c, code));
        return encode;
    }
    
    char decode(const char* code,unsigned int &read){
        BinaryNode *temp;
        temp = root;
        int count =sizeof(code)/sizeof(int);
        
        for (int i=0; i<count; i++) {
            if (code[i] == 1) {
                temp = temp->right;
            } else if (code [i] == 0){
                temp = temp->left;
            }
            read++;
        }
        return temp->symbol;
    }
    
    unsigned int count(){
        return root->countMethod(root); 
    }
};
class PriorityQueue{
private:
    class Nodo{
        public:
        Nodo* siguiente;
        CodingTree::BinaryNode* binaryNode;
        ;
        int count;
        Nodo(){
            siguiente=0;
        }
        Nodo(CodingTree::BinaryNode* dato, int count){
            this->binaryNode = dato;
            siguiente =0;
            this -> count =count;
        }
        ~Nodo(){
            if (siguiente != 0) {
                delete siguiente;
            }
        }
    };
    //Nodo *cabeza, *ultimo;
    unsigned int tamano;
public:
    Nodo *cabeza, *ultimo;
    void ordenar(){
        Nodo *temp ;
        Nodo *temp2 ;
        CodingTree::BinaryNode* tempBinaryNode;
        int tempCount;
        
        temp = cabeza->siguiente;
        
        while (temp->siguiente != NULL) {
            temp2 = temp -> siguiente;
            while (temp2 != NULL) {
                if (temp->count >= temp2 ->count) {
                    tempBinaryNode = temp->binaryNode;
                    tempCount = temp -> count;
                    
                    temp->binaryNode = temp2->binaryNode;
                    temp->count =temp2->count;
                    
                    temp2 ->binaryNode =tempBinaryNode;
                    temp2->count =tempCount;

                }
                temp2 = temp2 -> siguiente;
            }
            temp = temp->siguiente;
        }
    }
    
    PriorityQueue(){
        cabeza= new Nodo();
        ultimo= cabeza;
        tamano=0;
    }
    unsigned int getTamano(){
        return tamano;
    }
    PriorityQueue::Nodo pop(){
        Nodo *temp;
        int tempCount;
        CodingTree::BinaryNode* tempBinaryNode;
        ;
        
        temp = cabeza;
        tempBinaryNode = temp->binaryNode;
        tempCount = temp->count;
        
        cabeza = cabeza->siguiente;
        //delete temp;
        tamano=tamano-1;
        
        return *temp;
            }
    void push (CodingTree::BinaryNode* b, int c){
        ultimo ->siguiente = new Nodo(b, c);
        ultimo = ultimo->siguiente;
        tamano++;
        ordenar();
    }
};

CodingTree* createCode(Symbol** symbols, char* code){
    PriorityQueue cola = *new PriorityQueue();
    for (int i =0; i>256; i++) {
        if (symbols [i]->count !=0) {
        char tempSymbol = symbols[i]->symbol;
        int tempCount = symbols[i]->count;
        CodingTree::BinaryNode binaryNode = CodingTree::BinaryNode(tempSymbol, tempCount);
        CodingTree::BinaryNode* ptrBinary =& binaryNode;
        cola.push(ptrBinary, tempCount);
    }
    }
    CodingTree* cd = new CodingTree();
    int tamaño = cola.getTamano();
    for (int i=0; i< tamaño; i++) {
        cd->encode(code, cola.cabeza->binaryNode->symbol);
    }
    return cd;
}
        
    
    


int main() {

}
