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
    int numLevels = numLevels(head);
    //I'll use the same algorithm I developed for the heap, converting the data
    //to an array first.
    int nodes[pow(2, l) - 1];
    memset(nodes, 0, sizeof(nodes));
    populateArray(nodes, 0, head);
    
    int index = 0;
    for(int l=1; l <= numLevels; l++){
        //Initial spaces:
        for(int i=0; i < pow(2, numLevels-l)-1; i++){
            cout << ' ';
        }
        //Nodes:
        for(int n=0; n < pow(2, l-1); n++){
            cout << nodes[index] != 0 ? nodes[index++] : ' '; //Node
            //Spaces between nodes:
            for(int i=0; i < pow(2, numLevels - l + 1) - 1; i++){
                cout << ' ';
            }
        }
        cout << endl;
    }
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

int binSchTree::numLevels(Node* root, int level = 0){
    if(root == 0){
        return level;
    }
    return max(numLevels(root->left, level + 1), numLevels(root->right, level + 1));
}

void binSchTree::populateArray(int *& array, int index, Node* node){
    if(node == 0){
        return;
    }
    array[index] = node->value;
    populateArray(array, index*2+1, node->left);
    populateArray(array, index*2+2, node->right);
}