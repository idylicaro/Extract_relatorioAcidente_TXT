#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "EntradaArquivo.h"

int main()
{
    int quantidade=0;
    cout << "PROCESSANDO..." <<endl;
    ifstream arquivo("acidentes.txt");
    if(arquivo.is_open()){
       getAtributos();

    }else{
        cout << "ARQUIVO INVALIDO" <<endl;
    }

    return 0;
}
