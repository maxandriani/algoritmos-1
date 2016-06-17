/* 
 * File:   main.cpp
 * Author: Maxmiliano
 *
 * Created on 10 de Junho de 2016, 15:43
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// types
typedef struct room {
    int days;
    string name;
} room_t;

// Controller
int calcDecimalSize(int num);

void printAvailableRooms(int days[]);
void printLine();

float calcClientTotal(int days);

// Ui
void uiStart( std::vector<room_t> roomList, int totalRooms );
void uiRegisterRoom( std::vector<room_t> roomList, int totalRooms );
void uiCloseRoom( std::vector<room_t> roomList, int totalRooms );
void uiCalcRoom( std::vector<room_t> roomList, int totalRooms );
void uiCalcTotal( std::vector<room_t> roomList, int totalRooms );
void uiPrintHeader( std::vector<room_t> roomList, int totalRooms );
void uiNav( std::vector<room_t> roomList, int totalRooms );

// Controllers
int calcDecimalSize(int num){
    int size = 1;
    int d = 1;
    
    while(num >= (10*d)){
        d = d * 10;
        size++;
    }
    
    return size;
}

void printAvailableRooms( std::vector<room_t>roomList, int totalRooms){
    int maxDecimalSize = calcDecimalSize(totalRooms);
    int y = 1;
    
    for(int x=0; x<totalRooms; x++){
        cout << "[ ";
        

        for(int y=calcDecimalSize((x+1)); y<maxDecimalSize; y++){
            cout << " ";
        }

        cout << (x+1);
        cout << " ";
        
        if (roomList[x].days == 0){
            cout << "A";
        } else {
            cout << "-";
        }

        cout << " ] ";
        
        if (y == 5){
            y = 1;
            cout << endl;
        } else {
            y++;
        }
    }
    
    cout << endl;
}

void printLine(){
    cout << "==================================================" << endl;
}

/**
 * Um hotel com 30 quartos cobra R$ 50,00 por diária, mais uma taxa de serviços.
 * 
 * A taxa de serviços é de:
 * a) R$ 4,00 por diárias, se o númerode diárias for menor que 15
 * b) R$ 3,60 por diária, se o número de diárias for igual a 15
 * c) R$ 3,00 por diária, se o número de diárias for maior que 15
 * 
 * @param days
 * @return 
 */
float calcClientTotal(int days){
    float total;
    
    total = (float) days * 50.00;
    
    if (days < 15){
        total += 4.00;
    } else if (days > 15){
        total += 3.00;
    } else {
        total += 3.60;
    }
    
    return total;
}

// Views
void uiStart( std::vector<room_t> roomList, int totalRooms ){
    int key;
    
    uiPrintHeader(roomList, totalRooms);
    
    cout << "Por favor, informe a opcao desejada:" << endl;
    cout << "1. Registrar hospede;" << endl;
    cout << "2. Liberar quarto;" << endl;
    cout << "3. Calcular Diaria;" << endl;
    cout << "4. Calcular Total;" << endl;
    cout << "5. Sair" << endl;
    cin.clear();
    cin.sync();
    cin >> key;
    
    switch(key){
        case 1:
            uiRegisterRoom(roomList, totalRooms);
            break;
        case 2:
            uiCloseRoom(roomList, totalRooms);
            break;
        case 3:
            uiCalcRoom(roomList, totalRooms);
            break;
        case 4:
            uiCalcTotal(roomList, totalRooms);
            break;
        case 5:
            break;
        default:
            uiStart(roomList, totalRooms);
    }
    
};

void uiRegisterRoom( std::vector<room_t> roomList, int totalRooms ){
    int room = 0;
    int days = 0;
    string name = "";
    
    uiPrintHeader(roomList, totalRooms);
    
    cout << "Informe o quarto do cliente: " << endl;
    cin >> room;
    
    if (room <= 0 || room > totalRooms){
        cout << "ERRO: O numero do quarto deve ser um valor valido entre 1 e " << totalRooms << endl;
        system("pause");
        room = 0;
        cin.clear();
        cin.sync();
        uiRegisterRoom(roomList, totalRooms);
    }
    
    room--;
    
    cout << "Informe o nome do cliente: " << endl;
    cin.clear();
    cin.sync();
    getline (cin,name);
    roomList[room].name = name;
    
    cout << "Informe a quantidade de diarias: " << endl;
    cin >> days;
    roomList[room].days = days;
    
    
    uiPrintHeader(roomList, totalRooms);
    
    cout << "Cliente " << roomList[room].name << " registrado com sucesso!" << endl;
    printLine();
    
    uiNav( roomList, totalRooms );
    
}

void uiCloseRoom(std::vector<room_t> roomList, int totalRooms){
    int room;
    int key;
    
    uiPrintHeader(roomList, totalRooms);
    
    cout << "Informe o quarto a ser liberado:" << endl;
    cin >> room;
    
    room--;
    
    roomList[room].days = 0;
    roomList[room].name = "";
    
    uiPrintHeader(roomList, totalRooms);
    
    cout << "Quarto " << (++room) << " liberado com sucesso" << endl;
    
    printLine();
    
    uiNav(roomList, totalRooms);
}

void uiCalcRoom( std::vector<room_t> roomList, int totalRooms){
    float total;
    int room;
    
    uiPrintHeader(roomList, totalRooms);
    
    cout << "Informe o numero do quarto para calcular a conta:" << endl;
    cin >> room;
    
    room--;
    
    total = calcClientTotal(roomList[room].days);
    
    uiPrintHeader(roomList, totalRooms);
    
    printLine();
    cout << "Total para o cliente " << roomList[room].name << endl;
    printLine();
    cout << "Diarias: " << roomList[room].days << endl;
    cout << "Total: " << total << endl;
    printLine();
    
    uiNav(roomList, totalRooms);
}
void uiCalcTotal(std::vector<room_t> roomList, int totalRooms){
    float total;
    float clientPartial;
    int nameSize;
    
    uiPrintHeader(roomList, totalRooms);
    
    printLine();
    cout << "Quarto  Cliente               Diarias  Total      " << endl;
    printLine();
    
    for(int x=0; x<totalRooms; x++){
        
        cout << "[ ";
        
        for (int q=calcDecimalSize((x+1)); q<=2; q++){
            cout << " ";
        }
        
        cout << (x+1);
        
        cout << " ] ";
        
        if (roomList[x].days != 0){
            clientPartial = calcClientTotal(roomList[x].days);
            total += clientPartial;
            cout << roomList[x].name;
            
            nameSize = roomList[x].name.length();
            
            for (int n=nameSize; n<20; n++){
                cout << " ";
            }
            
            cout << "  ";
            cout << roomList[x].days;
            
            for (int n=calcDecimalSize(roomList[x].days); n<7; n++){
                cout << " ";
            }
            
            cout << "  ";
            cout << clientPartial;
        } else {
            cout << "Empty                          0";
        }
        
        cout << endl;
    }
    
    printLine();
    cout << "Total                                  " << total << endl;
    printLine();
    
    uiNav(roomList, totalRooms);
    
}

void uiPrintHeader(std::vector<room_t> roomList, int totalRooms){
    system("cls");
    printLine();
    cout << " HOTEL MANAGER " << endl;
    cout << " v. 0.2" << endl;
    printLine();
    
    cout << "Available Rooms: " << endl;
    printAvailableRooms(roomList, totalRooms);
    printLine();
    cout << endl;
}

void uiNav(std::vector<room_t> roomList, int totalRooms){
    int key;
    cin.clear();
    cin.sync();
    cout << "Pressione 1 para voltar ao menu;" << endl;
    cout << "Pressione 2 para sair" << endl;
    cin >> key;
    
    if (key == 1){
        uiStart(roomList, totalRooms);
    }
}

/*
 * Exercício 102
 * 
 * Um hotel com 30 quartos cobra R$ 50,00 por diária, mais uma taxa de serviços.
 * 
 * A taxa de serviços é de:
 * a) R$ 4,00 por diárias, se o númerode diárias for maior que 15
 * b) R$ 3,60 por diária, se o número de diárias for igual a 15
 * c) R$ 3,00 por diária, se o número de diárias for maior que 15
 * 
 * Faça um algoritmo que imprima o nome e o total da conta de cada cliente do hotel.
 * Imprima também o total ganho pelo hotel.
 */
int main(int argc, char** argv) {
    
    int totalRooms = 30;
    std::vector<room_t> roomList;
    
    printLine();
    cout << "Configuracoes: " << endl;
    printLine();
    cout << "Informe o numero de quartos disponiveis: " << endl;
    cin >> totalRooms;
    
    system("cls");
    
    roomList = std::vector<room_t> (totalRooms);
    
    for (int x=0; x<totalRooms; x++){
        room_t r;
        r.days = 0;
        r.name = "";
        roomList[x] = r;
    }
    
    uiStart(roomList, totalRooms);
    
    return 0;
}

