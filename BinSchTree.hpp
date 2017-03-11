//Binary Search Tree that supports insertion, removal, and printing out a visual of the tree.
#include <iostream>
#pragma once

struct Node{
  int value;
  Node* left = 0, *right = 0;
  Node(int newValue){
    value = newValue;
  }
  ~Node(){
    delete left;
    delete right;
  }
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
};