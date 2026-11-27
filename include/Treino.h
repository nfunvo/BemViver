#ifndef TREINO_H
#define TREINO_H

#include <string>
#include "Catalogo.h"

class Treino {
private:
    static int proximoId;      // atributo estatico: partilhado por todos os treinos

    int id;
    int idActividade;
    std::string nomeActividade;
    int duracao;               // em minutos
    std::string data;          // DD/MM/AAAA

public:
    Treino();

    // Pede os dados ao utilizador. Devolve true se o treino foi registado,
    // false se foi cancelado ou a actividade nao existe (nesse caso o objecto fica intacto).
    bool registar(const Catalogo& catalogo);

    void mostrar() const;

    int getId() const;
    int getDuracao() const;
    std::string getNomeActividade() const;
    std::string getData() const;
};

#endif
