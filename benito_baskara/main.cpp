/* 
 * File:   main.cpp
 * Author: Maxmiliano
 *
 * Created on 4 de Junho de 2016, 11:08
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

// Declare global typedefs
typedef struct Point {
    double x = 0;
    double y = 0;
} point;

typedef struct Roots {
    point *x1;
    point *x2;
} roots;

// Declare bhaskara functions
roots *bhaskara( int a, int b, int c );
int bhaskaraDelta( int a, int b, int c);
point *bhaskaraVertex( int a, int b, int c );

// Declare ui functions
void uiStart(int *a, int *b, int *c);
void uiInsertFunction(int *a, int *b, int *c);
void uiCalcBhaskara(int *a, int *b, int *c);
void uiFindVertex(int *a, int *b, int *c);
void uiPrintFunction(int *a, int *b, int *c);

/**
 * Perform bhaskara calulations
 * 
 * @param {int} a (a).x^2 x +1
 * @param {int} b x^2 (b).x +1
 * @param {int} c x^2 x +(c)
 * @return roots struct with point roots->x1 and point roots->x2
 */
roots *bhaskara( int a, int b, int c){
    int delta;
    roots *r;
    
    // Memory alloc
    r = (roots *) malloc(sizeof(roots));
    
    // Find delta
    delta = bhaskaraDelta( a, b, c );
    
    // Validations
    if (delta < 0){
        // There is not real roots
        r = NULL;
    } else {
        // The parable touch or cross the real line
        
        // Memory alloc
        r->x1 = (point *) malloc(sizeof(point));
        r->x2 = (point *) malloc(sizeof(point));
        
        // Find x1
        r->x1->y = ((double)(-1 * b) + sqrt( (double) delta )) / (double)( 2 * a );
        
        if (delta == 0){
            // The parable only touch the real line, so there is not two roots
            r->x2 = r->x1;
        } else {
            r->x2->y = (double)((-1 * b) - sqrt( delta )) / (double)( 2 * a );
        }
    }
    
    return r;
}

/**
 * Perform bhaskara's delta
 * 
 * @param {int} a (a).x^2 x +1
 * @param {int} b x^2 (b).x +1
 * @param {int} c x^2 x +(c)
 * @return Returns an int with delta
 */
int bhaskaraDelta( int a, int b, int c){
    int delta;
    
    // Function POW is an point floating operation. It means that the result will not be extacle, and it will always be aproxmately.
    // If the result is a little bit higher, it will be converted right to int
    // If the result is a little bit lower, it will be converted wrong to int ;/
    // Because I do not want to change all my program to work with floating point (double or float),
    // i'll use b*b instead of pow((double) b, 2.0);
    
    delta = (b*b) - (4*a*c);
    
    return delta;
}

/**
 * Find bhaskara's vertex
 * 
 * @param {int} a (a).x^2 x +1
 * @param {int} b x^2 (b).x +1
 * @param {int} c x^2 x +(c)
 * @return The vertex point
 */
point *bhaskaraVertex( int a, int b, int c){
    int delta;
    float A;
    double B;
    point *vertex;
    
    vertex = (point *) malloc(sizeof(point));
    
    // Find x vertex
    // -b / (2*a);
    vertex->x = (double)(-1 * b) / (double)(2 * a);
    
    // Find y vertex
    // - delta / (4*a);
    delta = bhaskaraDelta(a, b, c);
    vertex->y = (double)(-1 * delta) / (double)(4 * a);
    
    return vertex;
}

/**
 * Program Main screen
 * 
 * @param *a
 * @param *b
 * @param *c
 */
void uiStart(int *a, int *b, int *c){
    int key;
    
    system("cls");
    
    cout << "*****************************" << endl;
    cout << "* Bhaskara calculator       *" << endl;
    cout << "*****************************" << endl << endl;
    
    cout << "Press 1 to insert the function" << endl;
    cout << "Press 2 to calc Bhaskara" << endl;
    cout << "Press 3 to find vertex" << endl;
    cout << "Press any other key to exit" << endl << endl;
    
    cin >> key;
    
    switch(key){
        case 1:
            uiInsertFunction(a, b, c);
            break;
        case 2:
            uiCalcBhaskara(a, b, c);
            break;
        case 3:
            uiFindVertex(a, b, c);
            break;
    }
}

/**
 * Insert or replace F
 * @param *a
 * @param *b
 * @param *c
 */
void uiInsertFunction(int *a, int *b, int *c){
    system("cls");
    
    cout << "f(x) = (a)x^2 (b)x (c)" << endl << endl;
    cout << "Insert A" << endl;
    scanf("%i", &a);
    cout << "Insert B" << endl;
    scanf("%i", &b);
    cout << "Insert C" << endl;
    scanf("%i", &c);
    
    cout << endl << endl;
    
    uiPrintFunction(a, b, c);
    
    system("pause");
    
    uiStart(a, b, c);
}

/**
 * Calc Bhaskara
 * 
 * @param *a
 * @param *b
 * @param *c
 */
void uiCalcBhaskara(int *a, int *b, int *c){
    roots *roots;
    int va, vb, vc;
    
    va = (int) a;
    vb = (int) b;
    vc = (int) c;
    
    roots = bhaskara(va, vb, vc);
    
    cout << "Calc Bhaskara to the follow function:" << endl;
    
    uiPrintFunction(a, b, c);
    
    if (roots != NULL){
        cout << "x1: " << roots->x1->y << endl;
        cout << "x2: " << roots->x2->y << endl;
    } else {
        cout << "Delta is negative, so there is not real roots" << endl;
    }
    
    cout << endl;
    
    system("pause");
    
    uiStart(a, b, c);
}

/**
 * Find function vertex
 * 
 * @param *a
 * @param *b
 * @param *c
 */
void uiFindVertex(int *a, int *b, int *c){
    point * vertex;
    int va, vb, vc;
    
    va = (int) a;
    vb = (int) b;
    vc = (int) c;    
    
    vertex = bhaskaraVertex(va, vb, vc);
    
    cout << "Calc vertex point to the follow function:" << endl;
    
    uiPrintFunction(a, b, c);
    
    cout << endl;
    cout << "Xv: " << vertex->x << endl;
    cout << "Yv: " << vertex->y << endl;
    
    system("pause");
    
    uiStart(a, b, c);
}

/**
 * Print the current function
 * 
 * @param *a
 * @param *b
 * @param *c
 */
void uiPrintFunction(int *a, int *b, int *c){
    cout << "The function is: f(x) = " << (int) a << "x^2 " << (int) b << "x " << (int) c << endl;
}

/*
 * The program
 */
int main(int argc, char** argv) {
    
    int *a;
    int *b;
    int *c;
    
    a = (int *) malloc(sizeof(int));
    b = (int *) malloc(sizeof(int));
    c = (int *) malloc(sizeof(int));
    
    uiStart(a, b, c);
    
    cout << endl;
    cout << "Bye";
    
    return 0;
}

