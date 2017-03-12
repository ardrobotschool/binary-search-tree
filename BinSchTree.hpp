//Binary Search Tree that supports insertion, removal, and printing out a visual of the tree.
#include <iostream>
#pragma once

struct Node{
  int value;
  Node* left, *right;
  Node(int newValue) : left(0), right(0){
    value = newValue;
  }
  void deleteSubtree(){
    if(left!=0){
      left->deleteSubtree();
    }
    if(right!=0){
      right->deleteSubtree();
    }
    delete left;
    delete right;
  }
  ~Node(){}
};

class BinSchTree{
  public:
    BinSchTree();
    ~BinSchTree();
    void insert(int num);
    bool remove(int num);
    bool isEmpty();
    void print();
  private:
    Node* head = NULL;
    void insertPrivate(Node *& parent, int num);
    int getNumLevels(Node* root, int level);
    void populateArray(int *& array, int index, Node* node);
    Node** find(Node *& node, int num);
    void removeNode(Node** toRemove);
};