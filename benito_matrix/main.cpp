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
#include <ctime>

using namespace std;

void matrixPopulate(int *matrix, int rows, int cols);
void matrixRecursivePopulate(int *matrix, int rows, int cols);

/*
 * 
 */
int main(int argc, char** argv) {
    
    int * matrix_a;
    int * matrix_b;
    
    int n;
    
    // Meassure
    time_t *m1_start, *m2_start, *m1_end, *m2_end;
    
    m1_start = new time_t;
    m1_end = new time_t;
    m2_start = new time_t;
    m2_end = new time_t;
    
    // Ask user
    cout << "Por Favor, informe a quantidade de probabilidades:" << endl;
    cin >> n;
    
    if (n){
        // Creating rows
        matrix_a = new int[(int)pow(2,n) * n];
        matrix_b = new int[(int)pow(2,n) * n];
        
        // Populate
        time( m1_start );
        matrixPopulate(matrix_a, (int)pow(2, n), n);
        time( m1_end );
        time( m2_start );
        matrixRecursivePopulate(matrix_b, (int)pow(2, n), n);
        time( m2_end );
        
        cout << endl << endl;
        cout << "Processamento concluído" << endl;
        cout << "Método A: " << difftime((time_t)m1_end, (time_t)m1_start) << endl;
        cout << "Método B: " << difftime((time_t)m2_end, (time_t)m2_start) << endl;
        cout << endl;
        
        for (int y; y<pow(2,n); y++){
            for(int x=0; x<n; x++){
                cout << matrix_a[y * (int)pow(2, n) + x];
            }
            cout << endl;
        }
        
        cout << endl;
        
        for (int y; y<pow(2,n); y++){
            for(int x=0; x<n; x++){
                cout << matrix_b[y * (int)pow(2, n) + x];
            }
            cout << endl;
        }
        
    } else {
        cout << "Erro: o valor precisa ser inteiro" << endl;
    }
    
    return 0;
}

void matrixPopulate(int *matrix, int rows, int cols){
    for  (int y=0; y<rows; y++){
        // Método 1
        //
        // & == bitwise AND
        // Esse operador compara um número a nível binário usando o outro como máscara
        // Apenas os valores em que ambos são iguais serão retornados
        //  6 => 0110
        // &13=> 1101
        //  = => 0100 (4)

        for(int x=0; x<cols; x++){
            
            if (y & (int)pow(2,x)){
                //cout <<  1;
                //cout << " ";
                matrix[x * rows + y] = 1;
            } else {
                //cout <<  0;
                //cout << " ";
                matrix[x * rows + y] = 0;
            }
        }
        
        cout << "  ";        
        cout << endl;
        
    }
}

void matrixRecursivePopulate(int *matrix, int rows, int cols){
    // --->
    // 1     1
    // 1     0 2/1
    // 0     1  
    // 0 4/2 0 2/1
    cout << "Método 2" << endl;
    
    int temp = 0;
    
    if (!cols){
        return;
    }
    
    for(int y=1; y<=rows; y++){
        
        //cout << temp;
        matrix[(y-1) * rows + (cols-1)] = temp;
        
        if (y == (pow(2,cols)/2)){
            temp = 0;
        } else {
            temp++;
        }
    
        cout << " ";
    }
    cout << endl;
    
    matrixRecursivePopulate(matrix, rows, (--cols));
}