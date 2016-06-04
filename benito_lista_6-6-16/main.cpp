/* 
 * File:   main.cpp
 * Author: Maxmiliano
 *
 * Created on 4 de Junho de 2016, 16:00
 */

#include <cstdlib>
#include <iostream>

using namespace std;

// declare exercises
void question5();
void question6();
void question7();
void question8();
void question9();
void question10();
void question11();

// declare interface
void uiStart();
void uiPrintHead();

/*
 * 
 */
int main(int argc, char** argv) {

    uiStart();
    
    return 0;
}

/**
 * UI Main screen
 */
void uiStart(){
    int key;
    
    system("cls");
    
    cout 
            << "******************************************" << endl
            << "* Lista de exercicios de matematica      *" << endl
            << "* Entrega: 06/06/16                      *" << endl
            << "* Maxmiliano Reipert andriani            *" << endl
            << "******************************************" << endl 
            << endl
            << endl
            << "Pressione 1, para ir ao exercicio 5" << endl
            << "Pressione 2, para ir ao exercicio 6" << endl
            << "Pressione 3, para ir ao exercicio 7" << endl
            << "Pressione 4, para ir ao exercicio 8" << endl
            << "Pressione 5, para ir ao exercicio 9" << endl
            << "Pressione 6, para ir ao exercicio 10" << endl
            << "Pressione 7, para ir ao exercicio 11" << endl
            << "Pressione 0 para encerrar" << endl;
    
    cin >> key;
    
    switch(key){
        case 1:
            question5();
            break;
        case 2:
            question6();
            break;
        case 3:
            question7();
            break;
        case 4:
            question8();
            break;
        case 5:
            question9();
            break;
        case 6:
            question10();
            break;
        case 7:
            question11();
            break;
        case 0:
            break;
        default:
            uiStart();
    }
}

/**
 * Print exercise HEAD
 */
void uiPrintHead( int e ){
    system("cls");
    
    cout 
        << "******************************************" << endl;
    if (e > 9){
        cout << "* Exercicio " << e << "                           *" << endl;
    } else {
     cout << "* Exercicio " << e << "                            *" << endl;
    }
    cout
        << "******************************************" << endl
        << endl << endl;
}

/**
 * Exercício 5
 * 
 * Escreva um algoritmo para ler um valor (do teclado) e escrever (na tela) 
 * o seu antecessor;
 */
void question5(){
    
    char val;
    int previous;
    int key;
    
    uiPrintHead(5);
    
    cout << "Informe um valor: " << endl;
    cin >> val;
    
    previous = (int)val - 1;
    
    cout << endl << endl 
            << "O valor informado foi: " << val 
            << "; e seu antecessor e: " << (char) previous 
            << endl << endl;
    
    cout
            << "Pressione 1, para ir ao proximo exercicio" << endl
            << "Pressione 2, para voltar a tela inicial" << endl;
    
    cin >> key;
    
    if (key == 1){
        question6();
    } else {
        uiStart();
    }
}

/**
 * Exercicio 6
 * 
 * Escreva um algoritmo para ler as dimens~es de um retângulo (base e altura), 
 * calcular e escrever a área dp retângulo
 */
void question6(){
    int key;
    int base;
    int altura;
    int area;
    
    uiPrintHead( 6 );
    
    cout << "Por favor, informe a base do retangulo" << endl;
    cin >> base;
    
    cout << "Agora, informe a altura" << endl;
    cin >> altura;
    
    area = base * altura;
    
    cout << "A area do retangulo e: " << area << endl << endl;
    
    cout
            << "Pressione 1, para ir ao proximo exercicio" << endl
            << "Pressione 2, para voltar a tela inicial" << endl;
    
    cin >> key;
    
    if (key == 1){
        question7();
    } else {
        uiStart();
    }    
}

/**
 * Questão 7
 * 
 * Faça um algoritmo que leia a idade de uma pessoa expressa em anos, meses e 
 * dias, e escreva a idade dessa pessoa espressa em dias. Considerar anos 
 * com 265 dias e meses com 30 dias;
 */
void question7(){
    int key;
    int ageYear;
    int ageMonth;
    int ageDays;
    int age;
    
    uiPrintHead( 7 );
    
    // Algoritmo
    cout << "Por favor, informe seu ano de nascimento" << endl;
    cin >> ageYear;
    
    cout << "Informe o mes de seu nascimento" << endl;
    cin >> ageMonth;
    
    cout << "Informe o dia de seu nascimento" << endl;
    cin >> ageDays;
    
    age = ageYear * 365;
    age = age + (ageMonth * 30);
    age = age + ageDays;
    
    cout << "Voce possui " << age << " dias de vida" << endl << endl;
    
    // Fim
    cout
            << "Pressione 1, para ir ao proximo exercicio" << endl
            << "Pressione 2, para voltar a tela inicial" << endl;
    
    cin >> key;
    
    if (key == 1){
        question8();
    } else {
        uiStart();
    }
};

/**
 * Questão 8
 * 
 * Escreva um algoritmo para ler o número total de eleitores de um município, 
 * o número de brancos, nulos e válidos. Calular e escrever o percentual que 
 * cada um representa em relação ao de eleitores
 */
void question8(){
    int key;
    int totalPeople;
    int blankVotes;
    int nullVotes;
    int votes;
    
    uiPrintHead(8);
    
    cout << "Informe o total de eleitores" << endl;
    cin >> totalPeople;
    
    cout << "Informe a quantidade de votos em branco" << endl;
    cin >> blankVotes;
    
    cout << "Informe a quantidade de votos nulos" << endl;
    cin >> nullVotes;
    
    cout << "Informe a quantidade de votos validos" << endl;
    cin >> votes;
    
    if (totalPeople < blankVotes){
        cout << "Erro: O numero de votos brancos e superior ao numero de eleitores" << endl;
    } else {
        cout << "O percentual de votos brancos e: " << ((float)blankVotes/(float)totalPeople*100.0) << "%" << endl;
    }
    
    if (totalPeople < nullVotes){
        cout << "Erro: O numero de votos nulos e superior ao numero de eleitores" << endl;
    } else {
        cout << "O percentual de votos nulos e: " << ((float)nullVotes/(float)totalPeople*100.0) << "%" << endl;
    }
    
    if (totalPeople < votes){
        cout << "Erro: O total de votos e superior ao numero total de eleitores" << endl;
    } else {
        cout << "O percentual de votos validos e: " << ((float)votes/(float)totalPeople*100.0) << "%" << endl;
    }
    
    cout << endl;

    // Fim
    cout
            << "Pressione 1, para ir ao proximo exercicio" << endl
            << "Pressione 2, para voltar a tela inicial" << endl;
    
    cin >> key;
    
    if (key == 1){
        question9();
    } else {
        uiStart();
    }
};

/**
 * Questão 9
 * 
 * Escreva um algoritmo para ler o salario mensal atual de um funcionario e o
 * percentual de reajuste. Calcular e escrever o valor do novo salario
 */
void question9(){
    int key;
    float salarioAtual;
    float reajuste;
    float novoSalario;
    
    uiPrintHead(9);
    
    cout << "Informe o salario atual" << endl;
    cin >> salarioAtual;
    
    cout << "Informe o percentual de reajuste" << endl;
    cin >> reajuste;
    
    novoSalario = salarioAtual + (salarioAtual*(reajuste/100.0));
    
    cout << "O novo salario e de R$" << novoSalario << endl << endl; 
    
    // Fim
    cout
            << "Pressione 1, para ir ao proximo exercicio" << endl
            << "Pressione 2, para voltar a tela inicial" << endl;
    
    cin >> key;
    
    if (key == 1){
        question10();
    } else {
        uiStart();
    }
}

/**
 * Questão 10
 * 
 * O custo de um carro novo ao consumidor é a soma do custo de fábrica com a
 * porcentagem do distribuidor e dos impostos (aplicados ao custo de fábrica).
 * Supondo que o percentual do distribuidor seja de 28% e os impostos de 45%, 
 * escreva um algoritmo para ler o custo de fábrica de um carro, calcular e 
 * escrever o custo final ao consumidor.
 */
void question10(){
    int key;
    float cost;
    float price;
    
    uiPrintHead(10);
    
    cout << "Informe o preco de custo do automovel" << endl;
    cin >> cost;
    
    // price -> 100%
    // cost  -> ( 100% - taxes - comission )
    //
    // x     -> 100
    // cost  -> (100 - taxes - comission)
    //
    // x * (100 - taxes - comission) -> cost * 100
    // x -> (cost * 100) / (100 - taxes - comission)
    price = (cost * 100.0) / (100.0 - 45.0 - 28.0);
    
    cout << "O preco final sera R$" << price << endl;
    cout << "A comissao sera R$" << (price*0.28) << " 28%" << endl;
    cout << "Os impostos serao R$" << (price*0.45) << " 45%" << endl;
    
    cout << endl;
    
    // Fim
    cout
            << "Pressione 1, para ir ao proximo exercicio" << endl
            << "Pressione 2, para voltar a tela inicial" << endl;
    
    cin >> key;
    
    if (key == 1){
        question11();
    } else {
        uiStart();
    }
}

/**
 * Questão 11
 * 
 * Uma revendedora de carros usados paga a seus funcionários vendedores um 
 * salário fixo por mês, mais uma comissão também fixa para cada carro vendido
 * e mais 5% do valor das vendas por ele efetuadas. Escrever um algoritmo que 
 * leia o número de carros por ele vendidos, o valor total de suas vendas,
 * o salário fixo e o valor que ele recebe por carro vendido. Calcule e escreva 
 * o salário final do vendedor
 */
void question11(){
    float salario;
    float salarioFixo;
    float comissaofixa;
    int carrosVendidos;
    float totalVendas;
    
    uiPrintHead(11);
    
    cout << "Informe o salario fixo do vendedor" << endl;
    cin >> salarioFixo;
    
    cout << "Informe a quantidade de carros vendidos" << endl;
    cin >> carrosVendidos;
    
    cout << "Informe o valor total das vendas" << endl;
    cin >> totalVendas;
    
    cout << "Informe o valor da comissao fixa por carro vendido" << endl;
    cin >> comissaofixa;
    
    // Iniciando inscremento
    salario = salarioFixo + ( (float)carrosVendidos * comissaofixa ) + ( totalVendas * 0.05 );
    
    cout << "O salario final deste vendedor sera R$" << salario << endl << endl;
    
    // Fim
    system("pause");
    
    uiStart();
};