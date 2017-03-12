#include <iostream>
#include "BinSchTree.hpp"
#include <cmath>
#include <cstring>

using namespace std;

BinSchTree::BinSchTree(){
    //Head is assigned NULL already.
}

BinSchTree::~BinSchTree(){
    head->deleteSubtree();
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

bool BinSchTree::remove(int num){
    Node** toRemove = find(head, num);
    if(toRemove == 0){//Node not found
        return false;
    }
    else{
        removeNode(toRemove);
        return true;
    }
}

void BinSchTree::removeNode(Node** toRemove){
    if((*toRemove)->left == 0 && (*toRemove)->right == 0){//No children
        delete *toRemove;
        *toRemove = 0;
    }
    else if((*toRemove)->left != 0 && (*toRemove)->right != 0){//2 Children
        Node** nextLargest = &((*toRemove)->right);
        while((*nextLargest)->left != 0){
            nextLargest = &((*nextLargest)->left);
        }
        (*toRemove)->value = (*nextLargest)->value;
        removeNode(nextLargest);
    }
    else{//1 child
        Node* child = (*toRemove)->left == 0 ? (*toRemove)->right : (*toRemove)->left;
        delete *toRemove;
        *toRemove = child;
    }
}

void BinSchTree::print(){
    int numLevels = getNumLevels(head, 0);
    //I'll use the same algorithm I developed for the heap, converting the data
    //to an array first.
    int nodes[(int)(pow(2, numLevels)) - 1];
    int* arrPtr = nodes;
    memset(nodes, 0, sizeof(nodes));
    populateArray(arrPtr, 0, head);
    
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

Node** BinSchTree::find(Node *& node, int num){
    //Returns pointer to the (parent) pointer to the
    //first node with value == num.
    if(node == 0){
        return 0;
    }
    if(node->value == num){
        Node** ptr = &node;
        return ptr;
    }
    else if(node->value < num){
        return find(node->right, num);
    }
    else{
        return find(node->left, num);
    }
}