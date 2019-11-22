#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//stoi(string) de string para int
struct Acidente{
    int id;
    string cidade;
    string algumacoisa;
    string data;
    string diaDaSemana;
    string hora;
    string tipoAcidente;
    int x8;  //nao especificado por quem disponibilizou o material
    int x9;  //nao especificado por quem disponibilizou o material
    string description;
};
/*Funções*/
void separaElementos(string linha,Acidente &obj);


void getAtributos(){
    ifstream arquivo("acidentes.txt");
    int tam =0;
    if(!arquivo.is_open()){
        cout<<"Algo de errado com o arquivo"<<endl;
    }else{
        string linha;
        struct Acidente obj;

        while(getline(arquivo,linha)){
        //getline(arquivo,linha);
        separaElementos(linha,obj);
        cout << "PROCESSANDO..." <<endl;
        cout <<"Concluido :"<<tam++<<endl;
        //cout <<obj.id<<endl;  // para teste
        system("cls");
        }
        cout <<"FORAM PROCESSADOS :"<<tam <<endl;

    }
}

void separaElementos(string linha,Acidente &obj){
    int y = 0;  // para diferenciar os atributos
    int z = 0; // rodar atribuições referentes a prencher os atributos da struct;
    string temp;
    for(int i=0;i<linha.size();i++){
        if(linha[i]==';'){
            y++;
            z=0;
            temp.clear();
            continue;
        }

        switch(y){
        case 0:
        temp += linha[i];
        obj.id = stoi(temp);  // essa função so ta disponivel do c++11
            break;
        case 1:
        obj.cidade += linha[i];
            break;
        case 2:
            obj.algumacoisa += linha[i];
            break;
        case 3:
            obj.data += linha[i];
            break;
        case 4:
            obj.diaDaSemana += linha[i];
            break;
        case 5:
            obj.hora += linha[i];
            break;
        case 6:
            obj.tipoAcidente += linha[i];
            break;
        case 7:
            temp += linha[i];
        obj.x8 = stoi(temp);
            break;
        case 8:
            temp += linha[i];
        obj.x9 = stoi(temp);
            break;
        case 9:
            obj.description += linha[i];
            break;
        default:
            cout <<" Parametro errado!"<<endl;
            system("pause");
        }


    }
}

/*
arquivo.open("acidentes.txt");
    if(!arquivo.is_open()){
        cout<<"Algo de errado com o arquivo"<<endl;
    }else{

    }
*/
