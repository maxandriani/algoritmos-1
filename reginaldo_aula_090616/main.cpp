/* 
 * File:   main.cpp
 * Author: Maxmiliano
 *
 * Created on 9 de Junho de 2016, 10:00
 */

#include <cstdlib>
#include <iostream>

using namespace std;

// Declarações
void mainScreen();
void exercicio_88();
void exercicio_89();
void exercicio_90();
void exercicio_91();
void exercicio_92();
void exercicio_93();
void exercicio_94();
void exercicio_94_opcao_a();
void exercicio_94_opcao_b();
void exercicio_94_opcao_c();
void exercicio_94_opcao_d();
int exercicio_94_get_a();
int exercicio_94_get_b();
void exercicio_95();
void exercicio_96();
void exercicio_97();
void exercicio_98();
void exercicio_99();
void exercicio_100();
void exercicio_101();
void exercicio_102();
void exercicio_102_add_room(int *rooms[], int *clients[], int room);
void exercicio_102_remove_room(int *rooms[], int *clients[], int room);
void exercicio_102_calc_client(int *rooms[], int *clients[], int room);
void exercicio_102_calc_total(int *rooms[], int *clients[]);
float exercicio_102_calc_total_by_client(int diarias);
void exercicio_103();
void exercicio_104();
void exercicio_105();

/*
 * Aula de algoritmos do dia 09/06/2016
 */
int main(int argc, char** argv) {
    
    cout << "Lista de exercicios da aula do dia 09/06/2016" << endl << endl;
    
    mainScreen();
    
    return 0;
}

/**
 * Interface de consulta
 */
void mainScreen(){
    
    int key;
    
    cout << "Digite o numero do exercicio ou zero para sair: (88 a 105) " << endl;
    cin >> key;
    
    // Chamar exercícios
    system("cls");
    switch(key){
        case 88:
            exercicio_88();
            break;
        case 89:
            exercicio_89();
            break;
            
        case 90:
            exercicio_90();
            break;
            
        case 91:
            exercicio_91();
            break;
            
        case 92:
            exercicio_92();
            break;
            
        case 93:
            exercicio_93();
            break;
            
        case 94:
            exercicio_94();
            break;
            
        case 95:
            exercicio_95();
            break;
            
        case 96:
            exercicio_96();
            break;
            
        case 97:
            exercicio_97();
            break;
            
        case 98:
            exercicio_98();
            break;
            
        case 99:
            exercicio_99();
            break;
            
        case 100:
            exercicio_100();
            break;
            
        case 101:
            exercicio_101();
            break;
            
        case 102:
            exercicio_102();
            break;
            
        case 103:
            exercicio_103();
            break;
            
        case 104:
            exercicio_104();
            break;
            
        case 105:
            exercicio_105();
            break;
    }
    
    if (key != 0){
        system("cls");
        mainScreen();
    }
            
}

/**
 * Some os números de 1 a 100 e imprima o valor
 */
void exercicio_88(){
    int s = 0;
    
    cout << "Somando valores de 1 a 100:" << endl;
    
    for (int i=1; i<=100; i++){
        s = s + i;
    }
    
    cout << s << endl;
    
    system("pause");
}

/**
 * Construa um algoritmo que, para um grupo de 50 valores, determine:
 * a) A soma dos números positivos;
 * b) A quantidade de valores negativos
 */
void exercicio_89(){
    int vet[50];
    
    int positiveSum = 0;
    int negativeAmmount = 0;
    
    cout << "Esse exercicio devera avaliar uma lista de 50 numeros, onde devera somar os positivos e a quantidade de negativos" << endl << endl;
    
    // Generate random integers
    for (int x=0; x<50; x++){
        vet[x] = rand() % 100 - 50;
        
        cout << vet[x] << " ";
        
        if (vet[x] >= 0){
            positiveSum += vet[x];
        } else {
            negativeAmmount++;
        }
    }
    
    cout << endl << endl;
    cout << "Soma dos numeros positivos: " << positiveSum << endl;
    cout << "Quantidade de numeros nevativos: " << negativeAmmount << endl;
    
    system("pause");
    
}

/**
 * Faça um algoritmo que imprima os multiplos de 7, inferiores a 1000
 */
void exercicio_90(){
    int multiplo = 0;
    int i = 1;
    
    cout << "Multiplos de 7 inferiores a 1000:" << endl;
    
    while(multiplo < 1000){
        multiplo = 7 * i;
        
        if (multiplo < 1000){
            cout << multiplo << ", ";
        }
        
        i++;
    }
    
    cout << endl;
    
    system("pause");
}

/**
 * Faça um algoritmo que imprima todos os números pares compreendidos entre 85
 * e 907. O algoritmo também deve calcular a soma desses valores.
 */
void exercicio_91(){
    int sum;
    
    cout << "Numeros pares do intervalo de 85 à 907: " << endl;
    
    for(int x=85; x<907; x++){
        if (x % 2 == 0){
            cout << x << " ";
            sum += x;
        }
    }
    
    cout << endl;
    cout << "Soma: " << sum << endl;
    
    system("pause");
}

/**
 * Faça um algoritmo que calcule o valor de A, dado por:
 * 
 * a = n + ( (n-1)/2 ) + ( (n-2)/3 ) + ... + (1/n)
 * 
 * Onde N é um número inteiro positivo
 */
void exercicio_92(){
    int n;
    int a;
    
    cout << "Calcular a função: a = n + ( (n-1)/2 ) + ( (n-2)/3 ) + ... + (1/n)" << endl;
    cout << "Informe o valor de N:" << endl;
    cin >> n;
    
    // processando
    if (n > 0){
        // processa
        a = n;
        
        for (int x=2; x<n; x++){
            a = a + (n - (x-1))/x;
        }
        
        a = a + (1/n);
        
        cout << "A: " << a << endl;
        
    } else {
        // Erro
        cout << "Erro: N deve ser maior que zero" << endl;
    }
    
    system("pause");
}

/**
 * Uma rainha requisitou os serviços de um monge e disse-lhe que pagaria
 * qualquer preço. O monge, necessitando de alimentos, indagou à rainha sobre 
 * o pagamento, se poderia ser feito com grãos de trigo dispostos em um 
 * tabuleiro de xadrez (que possui 64 casas), de tal forma que o primeiro quadro 
 * deveria conter apenas um grão e os quatro subsequêntes, o dobro do quadro 
 * anterior. Crie um algoritmo para calcular o total de grãos que o monge recebeu.
 */
void exercicio_93(){
    double graos = 1;
    
    for(int x=2; x<=64; x++ ){
        graos = (graos * 2);
    }
    
    cout << "O total de graos no tabuleiro e: " << graos << endl << endl;
    
    system("pause");
}

/**
 * Dado o conjunto de instruções a seguir, faça um algoritmo com quatro 
 * variações, colocando o comando de repetição adequadamente, de forma a:
 * a) Executar o conjunto 10 vezes;
 * b) Não execuar nenhuma vez;
 * c) Executar o conjunto 100 vezes utilizando duas estruturas de repetição;
 * d) Executar N vezes, onde N é uma variável informada pelo usuário;
 */
void exercicio_94(){
    int k;
    
    cout << "Escolha uma opcao do menu abaixo: " << endl;
    cout << "1: Executar o conjunto 10 vezes;" << endl;
    cout << "2: Nao executar nenhuma vez;" << endl;
    cout << "3: Executar o conjunto 100 vezes utilizando duas estruturas de repeticao;" << endl;
    cout << "4: Executar N vezes, onde voce deve informar o valor de N;" << endl;
    cout << "5: Sair" << endl;
    cin >> k;
    
    system("cls");
    
    switch(k){
        case 1:
            exercicio_94_opcao_a();
            system("pause");
            break;
        case 2:
            exercicio_94_opcao_b();
            system("pause");
            break;
        case 3:
            exercicio_94_opcao_c();
            system("pause");
            break;
        case 4:
            exercicio_94_opcao_d();
            system("pause");
            break;
        case 5:
            break;
        default:
            system("cls");
            exercicio_94();
    }
}

/**
 * Executar o conjunto 10 vezes
 */
void exercicio_94_opcao_a(){
    int a;
    int b;
    int modulo;
    
    for (int x=0; x<10; x++){
        cout << "Repeticao " << (x+1) << endl;
        a = exercicio_94_get_a();
        b = exercicio_94_get_b();
        modulo = a % b;
        cout << "O modulo de (a % b) e: " << modulo << endl << endl;
    }
};

/**
 * Não executar nenhuma vez
 */
void exercicio_94_opcao_b(){
    int a;
    int b;
    int modulo;
    int ctrl = false;
    
    while (ctrl){
        a = exercicio_94_get_a();
        b = exercicio_94_get_b();
        modulo = a % b;
        cout << "O modulo de (a % b) e: " << modulo << endl << endl;
    }
};

/**
 * Executar o conjunto 100x com 2 estruturas de repetição
 */
void exercicio_94_opcao_c(){
    int a;
    int b;
    int modulo;
    int i = 0;
    
    while (i < 100){
        cout << "Repeticao " << (i+1) << endl;
        
        for (int x=0; x<2; x++){
            if (x == 0){
                a = exercicio_94_get_a();
            } else {
                b = exercicio_94_get_b();
            }
        }

        modulo = a % b;
        cout << "O modulo de (a % b) e: " << modulo << endl << endl;
        i++;
    }
};
void exercicio_94_opcao_d(){
    int a;
    int b;
    int modulo;
    int n;
    int i=0;
    
    cout << "Informe o valor de N" << endl;
    cin >> n;
    
    while (i<n){
        cout << "Repeticao " << (i+1) << endl;
        a = exercicio_94_get_a();
        b = exercicio_94_get_b();
        modulo = a % b;
        cout << "O modulo de (a % b) e: " << modulo << endl << endl;
        i++;
    }
};
int exercicio_94_get_a(){
    int a;
    cout << "Informe o valor de A (int): " << endl;
    cin >> a;
    return a;
}
int exercicio_94_get_b(){
    int b;
    cout << "Informe o valor de B (int): " << endl;
    cin >> b;
    return b;
}

/**
 * Para uma turma de 45 alunos, contrua um algoritmo que determine:
 * a) A idade média dos alunos com menos de 1,70m de altura;
 * b) A altura média dos alunos com mais de 20 anos;
 */
void exercicio_95(){
    int idades[45];
    float alturas[45];
    
    int idadeCount = 0;
    int alturaCount = 0;
    
    float alturaMedia = 0;
    float idadeMedia = 0;
    
    // Entrada
    for (int x=0; x<45; x++){
        cout << "Dados do aluno " << (x+1) << endl << endl;
        cout << "Altura (m): ";
        cin >> alturas[x];
        cout << endl;
        cout << "Idade: ";
        cin >> idades[x];
        cout << endl << endl;
    }
    
    // Processamento
    for (int x=0; x<45; x++){
        if (alturas[x] < 1.7){
            idadeMedia += (float) idades[x];
            idadeCount++;
        }
        
        if (idades[x] > 20){
            alturaMedia += (float) alturas[x];
            alturaCount++;
        }
    }
    
    idadeMedia = idadeMedia / (float) idadeCount;
    alturaMedia = alturaMedia / (float) alturaCount;
    
    // Saída
    cout << "A idade media dos alunos com menos de 1,70 e: " << idadeMedia << endl;
    cout << "A altura media dos alunos com mais de 20 anos e: " << alturaMedia << endl << endl;
    
    system("pause");
}

/**
 * Escreva um algoritmo que calcule o produto dos inteiros impares de 1 a 15 e,
 * então, exiba os resultados
 */
void exercicio_96(){
    int sum = 1;
    
    cout << "Produto dos inteiros impares de 1 a 15: " << endl;
    
    for (int x=1; x<=15; x++){
        if (x % 2 != 0){
            sum = sum * x;
        }
    }
    
    cout << sum << endl << endl;
    
    system("pause");
}

/**
 * Faça um algoritmo que leia um numero e imprima a sua tabela de multiplicacao 
 * de 1 ate 13
 */
void exercicio_97(){
    int mult;
    
    cout << "Tabela de multiplicação de 13:" << endl;
    
    for(int x=1; x<=13; x++){
        mult = 13*x;
        cout << "13x" << x << ": " << mult << endl;
    }
    
    system("pause");
}

/**
 * Escreva um algoritmo que calcule os quadrados e cubos dos numeros de 0 a 10
 * e imprima os valores resultantes no formato de tabela, como segue:
 */
void exercicio_98(){
    int square, cube;
    
    cout << "Tabela de exponenciacao de 0 a 10:" << endl;
    
    cout << endl;
    cout << "+-----+--------+--------+" << endl;
    cout << "| Num | square |  cube  |" << endl;
    cout << "+-----+--------+--------+" << endl;
    
    for (int x=0; x<=10; x++){
        square = x*x;
        cube = square * x;
        
        if (x < 10){
            cout << "|   " << x << " |";
        } else {
            cout << "|  " << x << " |";
        }
        
        if (square < 10){
            cout << "      " << square << " |";
        } else if (square < 100){
            cout << "     " << square << " |";
        } else {
            cout << "    " << square << " |";
        }
        
        if (cube < 10){
            cout << "      " << cube << " |";
        } else if (cube < 100){
            cout << "     " << cube << " |";
        } else if (cube < 1000){
            cout << "    " << cube << " |";
        } else {
            cout << "   " << cube << " |";
        }
        cout << endl;
    }
    
    cout << "+-----+--------+--------+" << endl;
    
    system("pause");
    
}

/**
 * Faça um algoritmo que calcule a média de salários de uma empresa, pedindo ao
 * usuário a quantidade de funcionários, o nome e o salário de cada funcionário 
 * e devolvendo a média, o salário mais alto e o mais baixo.
 */
void exercicio_99(){
    int nFunc = 0;
    int lowestIndex = 0;
    int higherIndex = 0;
    float range = 0;
    string *names;
    int *payments;
    
    cout << "Por favor, informe o numero de funcionarios da empresa: " << endl;
    cin >> nFunc;
    
    cout << endl;
    
    names = new string[20];
    payments = new int[nFunc];
    
    cout << endl;
    for(int x=0; x<nFunc; x++){
        cout << "Dados do funcionario " << (x+1) << endl;
        cout << "Nome: " << endl;
        cin >> names[x];
        cout << endl << "Salario: ";
        cin >> payments[x];
        cout << endl << endl;
        
        if (payments[x] > payments[higherIndex]){
            higherIndex = x;
        }
        
        if (payments[x] < payments[lowestIndex]){
            lowestIndex = x;
        }
        
        range += (float)payments[x];
    }
    
    range = range / (float)nFunc;
    
    cout << "A media salarial e de: " << range << endl;
    cout << "O maior salario e de: " << payments[higherIndex] << " e pertence a " << names[higherIndex] << endl;
    cout << "O menor salario e de: " << payments[lowestIndex] << " e pertence a " << names[lowestIndex] << endl;
    
    system("pause");
}

/**
 * Crie um programa que peça 10 números inteiros e apresente:
 * a média;
 * o maior;
 * e o menor número;
 */
void exercicio_100(){
    int num;
    float media;
    int menor = 0;
    int maior = 0;
    
    cout << "Informe 10 valores inteiros:" << endl;
    
    for (int x=0; x<10; x++){
        cout << "Valor " << (x+1) << ": ";
        cin >> num;
        cout << endl;
        media += (float) num;
        if (x < menor){
            menor = x;
        }
        if (x > maior){
            maior = x;
        }
    }
    
    media = media/10;
    
    cout << "O maior valor e: " << maior << endl;
    cout << "O menor valor a: " << menor << endl;
    cout << "A media e: " << media << endl;
    system("pause");
}

/**
 * Escreva um programa que determine o fatorial de um número
 * n! = 1 * 2 * 3 * 4 * ... * N;
 */
void exercicio_101(){
    int n;
    int f = 1;
    
    cout << "Informe um número inteiro para calcular seu fatorial" << endl;
    cin >> n;
    
    for (int x=1; x<=n; x++){
        f = f * x;
    }
    
    cout << "O fatorial de " << n << " e " << f << endl;
    system("pause");
}

/**
 * Um hotel com 30 quartos cobra R$ 50,00 por diária e mais uma taxa de serviços.
 * A taxa de serviços é de:
 * R$ 4,00 por diaria, se o número de diarias for < 15;
 * R$ 3,60 por diária, se o número de diárias for == 15;
 * R$ 3,00 por diária, se o número de diárias for > 15;
 */
void exercicio_102(){
    string *clients = new string[30];
    int *rooms = new int[30];
    int room;
    int k;
    
    system("cls");
    
    cout << "****************************************" << endl;
    cout << "Hotel 102" << endl;
    cout << "Quartos disponíveis: ";
    
    for(int x=0; x<30; x++){
        if (rooms[x] != 0){
            cout << " [" << (x+1) << "] ";
        }
    }
    
    cout << endl;
    cout << "****************************************" << endl << endl;
    
    
    cout << "Por favor, escolha a opção desejada:" << endl;
    cout << "1) Registrar reserva;" << endl;
    cout << "2) Liberar quarto;" << endl;
    cout << "3) Calcular total do quarto" << endl;
    cout << "4) Calcular total do hotel" << endl;
    cout << "5) Sair" << endl;
    
    cin >> k;
    
    system("cls");
    
    switch(k){
        case 1:
            cout << "Informe o numero do quarto: " << endl;
            cin >> room;
            system("cls");
            
            exercicio_102_add_room(rooms, clients);
            system("pause");
            break;
            
        case 2:
            cout << "Informe o numero do quarto: " << endl;
            cin >> room;
            system("cls");
            
            exercicio_102_remove_room(rooms, clients);
            system("pause");
            break;
            
        case 3:
            cout << "Informe o numero do quarto: " << endl;
            cin >> room;
            system("cls");
            
            exercicio_102_calc_client(rooms, clients, room);
            system("pause");
            break;
            
        case 4:
            exercicio_102_calc_total(rooms, clients);
            system("pause");
            break;
            
        case 5:
            break;
            
        default:
            exercicio_102();
    }
    
}

/**
 * Adicionar um novo hóspede
 * 
 * @param rooms
 * @param clients
 * @param room
 */
void exercicio_102_add_room(int *rooms[], int *clients[], int room){
    cout << "****************************************" << endl;
    cout << "Registro de hospedes" << endl;
    cout << "Quarto: " << (room+1) << endl;
    cout << "****************************************" << endl << endl;
    cout << "Informe o nome do hospede: ";
    cin >> clients[room];
    cout << "Informe a quantidade de diarias: ";
    cin >> rooms[room];
}

/**
 * Remover um hóspede e zerar seu quarto
 * 
 * @param rooms
 * @param clients
 */
void exercicio_102_remove_room(int *rooms[], int *clients[], int room){
    rooms[room] = 0;
    clients[room] = 0;
    
    cout << "O quarto " << (room+1) << " foi liberado com sucesso" << endl;
    system("pause");
}

/**
 * Calcular total do cliente
 * 
 * @param rooms
 * @param clients
 * @param room
 */
void exercicio_102_calc_client(int **rooms[], int **clients[], int room){
    
    float total;
    
    if (rooms[room] != 0){
        
        total = exercicio_102_calc_total_by_client((int)rooms[room]);
        
        cout << "****************************************" << endl;
        cout << "Registro de hospedes" << endl;
        cout << "Quarto: " << (room+1) << endl;
        cout << "****************************************" << endl << endl;
        
        cout << "Hospede: " << clients[room] << endl;
        cout << "Diarias: " << rooms[room] << endl;
        
        cout << "Total: " << total;
    } else {
        cout << "Erro: Esque quarto está vazio" << endl;
    }
    
    system("pause");
}
void exercicio_102_calc_total(int *rooms[], int *clients[]);
float exercicio_102_calc_total_by_client(int diarias){
    float total;
    
    total = (50.0 * diarias );
        
    if (diarias > 15){
        total += 3.0;
    } else if (diarias == 15){
        total += 3.6;
    } else {
        total += 4.0;
    }
    
    return total;
}

void exercicio_103(){}
void exercicio_104(){}
void exercicio_105(){}