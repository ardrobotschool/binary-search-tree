#include <iostream>
#include "BinSchTree.hpp"
#include <cmath>
#include <cstring>

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
    int numLevels = getNumLevels(head, 0);
    //I'll use the same algorithm I developed for the heap, converting the data
    //to an array first.
    int nodes[(int)(pow(2, numLevels)) - 1];
    int* arrPtr = nodes;
    memset(nodes, 0, sizeof(nodes));
    populateArray(arrPtr, 0, head);
    
    cout << nodes[1] << endl;
    int index = 0;
    for(int l=1; l <= numLevels; l++){
        //Initial spaces:
        for(int i=0; i < pow(2, numLevels-l)-1; i++){
            cout << ' ';
        }
        //Nodes:
        for(int n=0; n < pow(2, l-1); n++){
            if(nodes[index]!=0){
                cout << nodes[index];
            }
            else{
                cout << ' ';
            }
            index++;
            //Spaces between nodes:
            for(int i=0; i < pow(2, numLevels - l + 1) - 1; i++){
                cout << ' ';
            }
        }
        cout << endl;
    }
}

void BinSchTree::insertPrivate(Node *& parent, int num){
    if(parent == 0){
        parent = new Node(num);
        return;
    }
    if(num < parent->value){
        insertPrivate(parent->left, num);
    }
    else{
        insertPrivate(parent->right, num);
    }
}

int BinSchTree::getNumLevels(Node* root, int level = 0){
    if(root == 0){
        return level;
    }
    return max(getNumLevels(root->left, level + 1), getNumLevels(root->right, level + 1));
}

void BinSchTree::populateArray(int *& array, int index, Node* node){
    if(node == 0){
        return;
    }
    array[index] = node->value;
    populateArray(array, index*2+1, node->left);
    populateArray(array, index*2+2, node->right);
}