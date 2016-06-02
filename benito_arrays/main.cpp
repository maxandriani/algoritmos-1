/* 
 * File:   main.cpp
 * Author: Max
 *
 * Created on 2 de Junho de 2016, 15:00
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
  * keys
  */
struct keys {
    int F1 = 0;
    int F2 = 1;
    int F3 = 2;
    int F4 = 3;
};

/**
 * Typedefs
 */
// Dynamic lists
typedef struct node {
    int value;
    struct node * next;
} dynList;

/**
 * Array funcs
 */

/**
 * Add a new node to an existent list
 * 
 * @param list
 * @param value
 */
void listAddNode( dynList list, int value ){}

/**
 * Search on the dynamic list to the position of value and returns the position index
 * 
 * @param list The dynamic list
 * @param value The value to search
 * @return Returns the index of this value in the list
 */
int listIndexOf( dynList list, int value ){}

/**
 * Count the number of elements is in the dynamic list
 * 
 * @param list The dynamic list
 * @return The number of elements
 */
int listSizeOf( dynList list ){}

/**
 * Sort a dynamic list by descrescent value
 * 
 * @param list The dynamic list
 * @return a new Dynamic list
 */
dynList listSortDesc( dynList list ){};

/**
 * UI funcs
 */

/**
 * Clear the console
 */
void uiClear(){
    system("cls");
}

/**
 * UI Main interface
 * 
 * @param list
 */
void uiStart( dynList *list ){
    int key;
    
    uiClear();
    
    cout
        << "*********************************\n"
        << "Welcome to List Manager\n"
        << "*********************************\n\n\n"
        << "Waiting interaction:\n"
        << "Press F1 to Add Values\n"
        << "Press F2 to Search Values\n"
        << "Press F3 to Print Values\n"
        << "Press F4 to Exit\n";
    
    cin >> key;
    
    if (key == keys->F1){
        uiPopulateList( list );
    } else if (key == keys->F2){
        uiSearch( list );
    } else if (key == keys->F3){
        uiPrintList( list );
    }
};

/**
 * Function to add elements to list
 * 
 * @param list
 */
void uiPopulateList( dynList *list ){
    int key;
    int size = listSizeOf( list );
    int value;
    
    uiClear();
    
    cout "The list has " << size << " nodes, type a number and press enter to add another node\n";
    cin >> value;
    
    listAddNode( list, value );
    size = listSizeOf( list );
    
    cout "Value " << value << " was added. The list has now " << size << " nodes\n";
    
    cout 
        << "Waiting interaction:\n"
        << "Press F1 to back Main Screen\n"
        << "Press F2 to add another value\n"
        << "Press F4 to exit\n";
    
    cin >> key;
    
    if (key == keys->F1){
        uiStart( list );
    } else if (key == keys->F2){
        uiPopulateList( list );
    }
};

/**
 * Function to search the array 
 * 
 * @param list
 */
void uiSearch( dynList *list ){
    int index;
    int value;
    int key;
    
    uiClear();
    
    cout << "Type the value to search:\n";
    cin >> value;
    
    cout << "--- Start ---\n";
    
    index = listIndexOf( list, value );
    
    if (index > -1){
        // Position fount
        cout << "--- Finished ---\n"
             << "The value (" << value << ") is on position: " << index << "\n";
        
    } else {
        // No results
        cout << "Error: Value not found\n";
    }
        
    cout 
        << "Waiting interaction:\n"
        << "Press F1 to back Main Screen\n"
        << "Press F2 to search another value\n"
        << "Press F4 to exit\n";
    
    cin >> key;
    
    if (key == keys->F1){
        uiStart( list );
    } else if (key == keys->F2){
        uiSearch( list );
    }
    
};

/**
 * Primt all list values
 * 
 * @param list
 */
void uiPrintList( dynList *list ){
    int index = 0;
    int key;
    dynList node = list;
    
    uiClear();
    
    // ui interaction
    cout << "--- Start ---\n";
    
    // Start print
    while(node->next){
        cout << "Index: " << index << " > " << node->value << "\n";
        
        index++;
        
        if (node->next){
            node = node->next;
        }
    }
    
    // ui interaction
    cout << "--- finished ---\n";
    
    cout 
        << "Waiting interaction:\n"
        << "Press F1 to back Main Screen\n"
        << "Press F4 to exit\n";
    
    cin >> key;
    
    if (key == keys->F1){
        uiStart( list );
    }
};

/*
 * Main function
 */
int main(int argc, char** argv) {
    
    dynList list;
    
    uiStart( list );
    
    return 0;
}

