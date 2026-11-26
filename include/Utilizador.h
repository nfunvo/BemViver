
#ifndef UTILIZADOR_H
#define UTILIZADOR_H

#include <string>
using namespace std;

class Utilizador {
private:
    string nome;
    int idade;
    float peso;
    float altura;

public:
    void inserirDados();
    void mostrarDados();
    float calcularIMC();
};

#endif
