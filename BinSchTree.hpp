//Binary Search Tree that supports insertion, removal, and printing out a visual of the tree.
#include <iostream>
#pragma once

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
};