/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Maxmiliano
 *
 * Created on 8 de Junho de 2016, 10:52
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int n;
    int v;
    int ** matrix;
    
    cout << "Informe a quantidade de referencias circulares" << endl;
    cin >> n;
    
    // Gerando linhas
    matrix = new int*[(2*n)];
    
    // /gerando colunas
    for(int x=0; x<(2*n); x++){
        matrix[x] = new int[n];
        
        v=0;
        
        // Populando
        
    }
    
    // Imprimindo
    cout << "Valor 0:0 " << matrix[0][0] << endl;
    
    system("pause");
    
    return 0;
}

