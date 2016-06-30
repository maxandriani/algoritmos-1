/* 
 * File:   main.cpp
 * Author: Maxmiliano
 *
 * Created on 6 de Junho de 2016, 10:11
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void findDivisibles( int n );

/*
 * Main function
 */
int main(int argc, char** argv) {
    
    cout << "***********************************************" << endl;
    cout << "* Aula do dia 06/06/2016                       " << endl;
    cout << "***********************************************" << endl << endl;
    
    cout << "Exercicio 1: Encontrar os divisores de um determinado numero." << endl;
    findDivisibles( 2 );
    findDivisibles( 4 );
    findDivisibles( 10 );
    findDivisibles( 12 );
    findDivisibles( 14 );
    findDivisibles( 15 );
    findDivisibles( 21 );
    findDivisibles( 123 );
    
    findDivisibles( 125 );
    findDivisibles( 257 );
    findDivisibles( 2564971 );
    findDivisibles( 2584973 );
    findDivisibles( 52729 );
    
    cout << endl;
    
    system("pause");
    
    return 0;
}

/**
 * Find the divisor of a number
 */
void findDivisibles( int n ){
    
    //int n;
    int d = 1;
    //int key;
    
    cout << "Testando: " << n << endl;    
    
    while(d <= n){
        
        if (n % d == 0){
            cout << "The number " << n << " is divisible by " << d << endl;
        }
        
        if (d == 4 && n%2 == 0 && n%3==0) {
            cout << "Pulou para 6" << endl;
            d = 6;
        } else if (d == 8 && n%2 == 0 && n%7 == 0){
            cout << "Pulou para o 14" << endl;
            d = 14;
        } else if (d == 6 && n%3 == 0 && n%5 == 0){
            cout << "Pulou para o 15" << endl;
            d = 15;
        } else if (d == 8 && n%3 == 0 && n%7 == 0){
            cout << "Pulou para o 21" << endl;
            d = 21;
        } else {
            d ++;
        }
    
    }
    
    cout << endl;
   
}