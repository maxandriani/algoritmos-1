/* 
 * File:   main->cpp
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
    struct node *next;
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
void listAddNode( dynList *list, int value, int pos ){
    int i = 0;
    dynList * currentNode = list;
    
    if (pos == -1){
        // Add to the end
        if (list->value == NULL){
            list->value = value;
        } else {
            while(currentNode->next != NULL){
                currentNode = currentNode->next;
            }

            currentNode->next = (dynList *)malloc(sizeof(dynList));
            //(struct node *)malloc(sizeof(struct node));
            currentNode->next->value = value;
            currentNode->next->next = NULL;
        }
    } else if (pos == 0) {
        // Add to head
        dynList *newNode;
        
        newNode = (dynList *)malloc(sizeof(dynList));
        
        newNode->value = value;
        newNode->next = list;
        list = newNode;
    } else {
        // Add to index
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
            i++;
            
            if (i == pos){
                break;
            }
        }
        
        dynList *newNode;
        
        newNode = (dynList *)malloc(sizeof(dynList));
        
        newNode->value = value;
        newNode->next = currentNode->next;
        
        currentNode->next = newNode;
    }
    
}

/**
 * Search on the dynamic list to the position of value and returns the position index
 * 
 * @param list The dynamic list
 * @param value The value to search
 * @return Returns the index of this value in the list
 */
int listIndexOf( dynList list, int value ){
    int index = -1;
    int i = -1;
    dynList node = list;
    
    while(node->next){
        i++;
        
        if (node->value == value){
            index = i;
            break;
        }
        
        node = node->next;
    }
    
    return index;
}

/**
 * Count the number of elements is in the dynamic list
 * 
 * @param list The dynamic list
 * @return The number of elements
 */
int listSizeOf( dynList list ){
    int i = 1;
    dynList node = list;
    
    while(node->next){
        i++;
        node = node->next;
    }
    
    if (!node->value){
        i = 0;
    }
    
    return i;
}

/**
 * Sort a dynamic list by descrescent value
 * 
 * @param list The dynamic list
 * @return a new Dynamic list
 */
dynList listSortDesc( dynList list ){
    dynList newList;
    dynList newListNode;
    
    dynList node;
    
    
    // Start the newList with the first value
    newList->value = list->value;
    
    // Navigate to the old list
    node = list;
    
    while(node->next){
        if (newList->value > node->value){
            // O item atual é menor do que o primeiro item da lista
            // Portanto a nova lista deve ser varrida para encontrar a posição correta
            newListNode = newList;
            
            while(newListNode->next){
                if (newListNode->value < node->value){
                    // O novo item é maior do que o nó atual, logo essa é a posição do novo item
                    dynList newNode;
                    newNode->value = node->value;
                    newNode->next = newListNode->next;
                    newListNode->next = *newNode;
                    break;
                } else if (!newListNode->next) {
                    // Chegamos ao final da lista, portanto, essa é a posição do novo nó
                    dynList newNode;
                    newNode->value = node->value;
                    newListNode->next = *newNode;
                    break;
                } else {
                    // Posição ainda não encontrada->->-> avança a lista
                    newListNode = newListNode->next;
                }
            }
            
        } else {
            // O item atual é maior que o primeiro item da lista
            // portanto, ele deve ser o primeiro item
            dynList newNode;
            dynList nextNode;
            
            // Save old list head
            nextNode = newList;
            
            // Create a new node
            newNode->value = node->value;
            newNode->next = *nextNode;
            
            // replace the new head
            newList = newNode;
        }
    }
    
    // Neste momento uma nova lista ordenada foi criada->->->
    // Porém a lista anterior continua na memória->->-> por questões de performance seria interessante deletar essa lista
    // Mas isso já está fora do escopo do trabalho
    
    return newList;
};

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
    
    cout "Value " << value << " was added-> The list has now " << size << " nodes\n";
    
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
    
    dynList *list = NULL;
    
    list = malloc(sizeof(dynList));
    
    list->value = NULL;
    list->next = NULL;
    
    uiStart( list );
    
    return 0;
}

