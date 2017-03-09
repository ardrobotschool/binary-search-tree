#include <iostream>
#include "BinSchTree.hpp"
#include <cmath>

using namespace std;

BinSchTree::BinSchTree(){
    //Head is assigned NULL already.
}

BinSchTree::~BinSchTree(){
    delete head;
}

bool BinSchTree::isEmpty(){
    return head == NULL;
}

void BinSchTree::insert(int num){
    if(head == 0){
        head = new Node(num);
        return;
    }
    insertPrivate(head, num);
}

void BinSchTree::print(){
    //I made it look pretty, but only if the numbers are 1 or 2 digit.
    /*int numLevels = ceil(log2(count + 1));
    int index = 0;
    for(int l=1; l <= numLevels; l++){
        //Initial spaces:
        for(int i=0; i < pow(2, numLevels-l)-1; i++){
            cout << ' ';
        }
        //Nodes:
        for(int n=0; n < pow(2, l-1); n++){
            if(nodes[index] != 0){
                cout << nodes[index++]; // Node
            }
            else{
                break;
            }
            //Spaces between nodes:
            for(int i=0; i < pow(2, numLevels - l + 1) - 1; i++){
                cout << ' ';
            }
        }
        cout << endl;
    }*/
}

void BinSchTree::insertPrivate(Node* parent, int num){
    if(parent == 0){
        parent = new Node(num);
        return;
    }
    if(num < parent){
        insertPrivate(parent->left, num);
    }
    else{
        insertPrivate(parent->right, num);
    }
}