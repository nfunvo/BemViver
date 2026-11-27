
#ifndef ACTIVIDADE_H
#define ACTIVIDADE_H

#include <string>
#include <vector>

using namespace std;

class Actividade {
private:
    int id;
    string nome;
    string descricao;
    string intensidade;

public:
    Actividade();

    void carregarActividades();
    void listarActividades();
    void registarActividade();
    void mostrarActividade();

    bool selecionarActividade(int codigo);

    string getNome();
};

#endif
