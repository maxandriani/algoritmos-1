/* 
 * File:   main->cpp
 * Author: Max
 * Authos: Hugo
 *
 * Created on 2 de Junho de 2016, 22:39
 */

// C++ 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void uiClear();

// Declare dynLists
typedef struct node {
    int value;
    struct node *next;
} dynList;

dynList *  listAddNode( dynList *list, int value);
int listSizeOf( dynList *list );
int listValueOf( dynList *list, int index );

// Declare calcs
int calcFindMultiple( int *dividendo, int *divisor );
string calcFormatResponse( dynList *quocienteMemory, int length );
string calcToStr( int x );
int calcFindPeriod( dynList *quocienteMemory, dynList *restoMemory, int index, int divisor);
int calcFindDecimalSize(int n);
string calcPerformDivision( int n );

/**
 * Dyn Lists
 */

/**
 * Add note to the end of array
 * 
 * @param list
 * @param value
 */
dynList * listAddNode( dynList *list, int value){
    dynList *newNode;
    dynList *node;
    
    node = list;
    
    if (node == NULL){
        newNode = (dynList *) malloc(sizeof(dynList));
        newNode->value = value;
        newNode->next = NULL;
        list = newNode;
    } else {
        while(node->next != NULL){
            node = node->next;
        }
        
        newNode = (dynList *) malloc(sizeof(dynList));
        newNode->value = value;
        newNode->next = NULL;
    
        node->next = newNode;
    }
    
    return list;
};

/**
 * Calc the size of an list
 * 
 * @param list
 * @return 
 */
int listSizeOf( dynList *list ){
    int size = 0;
    dynList *node;
    
    node = list;
    
    while(node != NULL){
        node = node->next;
        size++;
    }
    
    return size;
}

/**
 * Get the value of index parameter
 * 
 * @param list
 * @param index
 * @return 
 */
int listValueOf( dynList *list, int index ){
    int i = 0;
    dynList *node;
    
    node = list;
    
    while(node != NULL){
        if (i == index){
            return node->value;
        } else {
            i++;
            node = node->next;
        }
    }
    
    return -1;
}

/**
 * Calcs
 */

/**
 * Find an quocient multiple
 * 
 * @param dividendo
 * @param dividor
 * @return 
 */
int calcFindMultiple( int dividendo, int divisor ){
    int n = 0;
    
    if (dividendo >= divisor){
        for (int x=9; x>=0; x--){
            if ( (divisor * x) <= dividendo ){
                n = x;
                break;
            }
        }
    }
    
    return n;
}

/**
 * Format the response to the standard mode
 * 
 * @param quocienteMemory
 * @param length
 * @return 
 */
string calcFormatResponse( dynList *quocienteMemory, int length ){
    string output(".");
    dynList *quocienteNode;
    int periodSize;
    int count = 0;
    
    /**
     * Format the response in the follow pattern
     * .5 0
     * .3
     * .25 0
     * .2 0
     * .1 6
     * .142857
     * ...
     * .02 0
     * 
     * -1 => Divisão exata
     *  0 => Dízima simples (remover 1)
     *  x => Dizima complexa (Número de casas para suprimir)
     */
    
    if (length == -1){
        quocienteNode = quocienteMemory;
        while(quocienteNode != NULL){
            output = output + calcToStr( quocienteNode->value );
            quocienteNode = quocienteNode->next;
        }
        output = output + " 0";
    } else if (length == 0){
        quocienteNode = quocienteMemory;
        while( quocienteNode->next != NULL ){
            if (quocienteNode->next->next == NULL){
                // last node
                if (count == 0){
                    output = output + calcToStr( quocienteNode->value );
                } else {
                    output = output + " " + calcToStr( quocienteNode->value );
                }
            } else {
                // normla node
                output = output + calcToStr( quocienteNode->value );
            }
            quocienteNode = quocienteNode->next;
            count++;
        }
    } else {
        periodSize = listSizeOf( quocienteMemory ) - (length*2);
        quocienteNode = quocienteMemory;
        for (int i=0; i<( listSizeOf( quocienteMemory ) - length ); i++){
            if (periodSize > 0 && periodSize == i){
                output = output + " ";
            }
            output = output + calcToStr( quocienteNode->value );
            quocienteNode = quocienteNode->next;
        }
    }
    
    // Only for tests
    // char to supress
//    output += '/';
    
    return output;
}

/**
 * Convert int to char
 * 
 * @param x
 * @return 
 */
string calcToStr( int x ){
    string y;
    
    switch(x){
        case 9:
            y = "9";
            break;
        case 8:
            y = "8";
            break;
        case 7:
            y = "7";
            break;
        case 6:
            y = "6";
            break;
        case 5:
            y = "5";
            break;
        case 4:
            y = "4";
            break;
        case 3:
            y = "3";
            break;
        case 2:
            y = "2";
            break;
        case 1:
            y = "1";
            break;
        default:
            y = "0";
    }
    
    return y;
}

/**
 * Calc the quocienteMemory and restoMemory to find periods
 * 
 * @param quocienteMemory
 * @param restoMemory
 * @param index
 * @return 
 */
int calcFindPeriod( dynList *quocienteMemory, dynList *restoMemory, int index, int divisor){
    int indexCounter = 0;
    int isOdd = true;
    string leftSide = "";
    string rightSide = "";
    int leftTemp;
    int rightTemp;
    int tempValue = NULL;
    int divisorSize = calcFindDecimalSize( divisor );
    
    dynList *quocienteNode;
    int quocienteValue;
    dynList *restoNode;
    int restoValue;
    
    /**
     * Verifica se o resto é igual a zero, se for, a divisão é precisa.
     */
    tempValue = listValueOf( restoMemory, (index-1) );
    if (tempValue == 0){
        return -1;
    }
    
    /**
     * Verifica dízimas simples, ou seja, aquelas na qual são compostas por um número unitário
     * repetido infinitamente. Entretando, em dízimas compostas, na qual existe um número que não se 
     * repete e que pode ser maior que 10, é necessário testar apenas as duas últimas posições.
     * 
     * Para detectar isso, serão comparados os n últimos restos, que nessa situação sempre serão iguais,
     * junto aos n ultimos quocientes, que sejam diferentes de zero, onde n é o tamanho de decimais do
     * divisor
     */
    if (index > divisorSize){
        restoNode = restoMemory;
        quocienteNode = quocienteMemory;
        
        while(quocienteNode->next->next != NULL){
            restoNode = restoNode->next;
            quocienteNode = quocienteNode->next;
        }
        
        if ( restoNode->value == restoNode->next->value
             && quocienteNode->value == quocienteNode->next->value
             && quocienteNode->value != 0){
            return 0;
        }
    }
    
    /**
     * Calcula a metade arredondada para baixo da quantidade de casas.
     */
    for(int x=0; x<index; x++){
        if (isOdd){
            isOdd = 0;
        } else {
            indexCounter++;
            isOdd = 1;
        }
    }
    
    /**
     * Estratégia:
     * Para detectar as dízimas complexas, ou seja, aquelas na qual o período é um número com mais
     * de uma casa decimal, é necessário separar o conjunto de caracteres em dois grupos e compará-los.
     * 
     * O problema
     * Entretanto existem situações onde a dízima é composta por dois segmentos, o primeiro composto
     * por um número que não se repete e o segundo pelo período em si, que também pode ser complexo.
     * 
     * Portanto é necessário fazer duas verificações, uma horizontal e outra vertical.
     * 
     * A verificação horizontal deverá pegar o número da metade do tamanho da dízima, e fazer um teste
     * vertical para cada um, dubtraindo uma casa decimal a cada teste
     * 
     * Fix: Foi observado que um a quantidade de números repetidos, porém, que não são sízimas
     * cresce conforme o tamanho do divisor, com base nisso, foram feitas adaptações para
     * proteger o código de falsos positivos.
     * 
     * 111222 6 6
     *  01122 5 4
     *   1122 4 4
     *    012 3 2
     *     12 2 2
     */
    
    //03571428571428 14
    
    if (index > divisorSize){
        for (int y=indexCounter; y>(divisorSize); y--){
            
            // Reset hands
            leftSide = "";
            rightSide = "";
            
            for (int x=0; x<y; x++){
                leftTemp = ((index - (y * 2)) + x); // 0 + x
                rightTemp = ((index - (y)) + x); // 6 + x

                leftSide += calcToStr( listValueOf( quocienteMemory, leftTemp ));
                rightSide += calcToStr( listValueOf( quocienteMemory, rightTemp ));
            }

            //if (rightInt == leftInt && restoMemory[index] == restoMemory[indexCounter]){
            if (rightSide == leftSide){
                return y;
            }
        }
    }
    
    return -2;
}

/**
 * Find Deciaml Size
 * 
 * @param n
 * @return 
 */
int calcFindDecimalSize( int n ){
    int i = 1;
    int c = 1;
    
    while((i*10) <= n){
        i = i * 10;
        c++;
    }
    
    return c;
};

/**
 * Perform de division 1/n
 * 
 * @param n
 * @return Well formated perdiod response
 */
string calcPerformDivision( int n ){
    
    // dividendo -> divisor
    //              ---------
    // resto        quociente

    int quociente = NULL;
    dynList *quocienteMemory = NULL;
    int divisor = n;
    int dividendo = NULL;
    int resto = 1;
    dynList *restoMemory = NULL;
    int isPerforming = -2;
    int listSize = 1;
    
    while(isPerforming == -2){
        // Acrescenta uma dezena à divisão
        dividendo = resto * 10;
        quociente = calcFindMultiple( dividendo, divisor );
        resto = dividendo - ( quociente * divisor );
        
        quocienteMemory = listAddNode( quocienteMemory, quociente );
        restoMemory = listAddNode( restoMemory, resto );
        
        listSize = listSizeOf( quocienteMemory );
        
        isPerforming = calcFindPeriod( quocienteMemory, restoMemory, listSize, divisor);
        
    }
    
    return calcFormatResponse( quocienteMemory, isPerforming );

}

/*
 * The core function
 */
int main(int argc, char** argv) {
    
    string output;
    int startNum, finishNum;
    ofstream outputFile;
    
    // Open file
    remove( "output.txt" );
    outputFile.open ("output.txt");
    
    cout << "*******************" << endl;
    cout << " Welcome           " << endl;
    cout << "*******************" << endl << endl;
    cout << "Este programa ira fazer uma divisao de 1/n, onde n e um intervalo definido a seguir:" << endl;
    cout << "Por favor, informe o numero INICIAL: (devera ser maior que que zero)" << endl;
    scanf("%i", &startNum);
    cout << "Por favor, informe o numero FINAL: (devera ser maior que o numero inicial)" << endl;
    scanf("%i", &finishNum);
    
    if (startNum > 0){
        
        if (startNum <= finishNum){
            
            cout << "--- Iniciando calculoss ---" << endl;
            
            for (int n = startNum; n<=finishNum; n++){
                // ui
                cout << "1/" << n << ": ";
                // Perform
                output = calcPerformDivision( n );
                cout << output;
                // Imprimindo arquivo
                outputFile << output << "\n";
                cout << " saved" << endl;
            }
            
            cout << "--- processamento concluído ---" << endl;
            
        } else {
            cout << "ERRO: O numero final deve ser maior que o inicial" << endl;
        }
        
    } else {
        cout << "ERRO: O numero inicial deve ser maior que zero" << endl;
    }
    
    outputFile.close();
    
    system("pause");
    
    return 0;
}

