/*
 * A program that places numbers (entered by the user or from a file)
 * into a binary search tree. The user can remove individual numbers
 * from the tree, which updates itself. You can print out the tree.
 * Artur Drobot, Mar 2017.
 */
#include <iostream>
#include "BinSchTree.hpp"
#include <fstream>

using namespace std;

void populate(BinSchTree &binSchTree, char *list);

int main(){
    while(true){
        BinSchTree binSchTree;
        char input;
        cout << "Choose an option to populate the tree: \n(1) Enter numbers manually.\n(2) Enter file name.\n(q) Quit." << endl;
        cin >> input;
        if(input == '1'){
            char list[150];
            cout << "Enter the numbers, separated by commas and/or spaces:" << endl;
            cin.ignore();
            cin.getline(list, 150);
            populate(binSchTree, list);
        }
        else if(input == '2'){
            char filename[32];
            cout << "Enter the file name: ";
            cin >> filename;
            ifstream stream(filename);
            if(stream.is_open()){
                char list[16384];
                stream.getline(list, 16384, 0);
                stream.close();
                populate(binSchTree, list);
            }
            else{
                cout << "Could not open file." << endl;
                continue;
            }
        }
        else if (input == 'q'){
            break;
        }
        else{
            cout << "Command not recognized." << endl;
        }
        
        while(true){
            cout << "What do you want to do now?: \n(1) Print out the tree.\n(2) Add a number.\n(3) Remove a number.\n(4) Start a new list.\n(q) Quit program.\n(9) Sleep for 9 hours." << endl;
            cin >> input;
            if(input == '1'){
                cout << "Tree:" << endl;
                binSchTree.print();
            }
            else if (input == '2'){
                int num;
                cout << "Enter the number: ";
                cin >> num;
                cout << endl;
                binSchTree.insert(num);
                cout << "Done." << endl;
            }
            else if (input == '3'){
                int num;
                cout << "Enter the number: ";
                cin >> num;
                cout << endl;
                if(binSchTree.remove(num)){
                    cout << "Number removed." << endl;
                }
                else{
                    cout << "Number not found in the tree." << endl;
                }
            }
            else if (input == '4' || input == 'q'){
                break;
            }
            else if (input == '9'){
                cout << "Access denied by the International Baccalaureate Programme. Your attempt has been logged." << endl;
            }
            else{
                cout << "Command not recognized." << endl;
            }
            cout << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
        if(input == 'q'){
            break;
        }
        
    }
    return 0;
}

void populate(BinSchTree &binSchTree, char *list){
    int index = 0;
    while(list[index]){
        if(isdigit(list[index])){
            int num = list[index] - '0';
            while(isdigit(list[++index])){
                num = 10*num + (list[index] - '0');
            }
            binSchTree.insert(num);
        }
        else{
            index++;
        }
    }
}