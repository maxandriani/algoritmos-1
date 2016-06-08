/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 *
 * Created on 8 de Junho de 2016, 16:11
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

void matrixPopulate(int ** matrix, int rows, int cols);

/*
 * 
 */
int main(int argc, char** argv) {
    
    int ** matrix;
    int n;
    
    // Ask user
    cout << "Por Favor, informe a quantidade de probabilidades:" << endl;
    cin >> n;
    
    if (n){
        // Creating rows
        matrix = new int*[(int)pow(2,n)];
        
        for (int x; x<pow(2,n); x++){
            matrix[x] = new int[n];
        }
        
        // Populate
        matrixPopulate(matrix, (int)pow(2, n), n);
        
    } else {
        cout << "Erro: o valor precisa ser inteiro" << endl;
    }
    
    return 0;
}

void matrixPopulate(int ** matrix, int rows, int cols){
    for (int y=0; y<rows; y++){
        
        for(int x=0; x<cols; x++){
            if (y & (int)pow(2,x)){
                cout <<  1;
                cout << " ";
            } else {
                cout <<  0;
                cout << " ";
            }
        }
        cout << endl;
        
    }
}
