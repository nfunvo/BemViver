
#ifndef TREINO_H
#define TREINO_H

#include <string>
#include "Actividade.h"

using namespace std;

class Treino {
private:
    int id;
    string actividade;
    int duracao;
    string data;

public:
    void registarTreino(Actividade& catalogo);
    void mostrarTreino();

    int getDuracao();
    string getActividade();
};

#endif
