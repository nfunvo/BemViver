#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include "Catalogo.h"
#include "Treino.h"
#include "Utilizador.h"

// Coordena o programa: guarda os dados (utilizador, catalogo, treinos)
// e liga o menu as restantes classes. Nao faz calculos nem leitura de baixo nivel.
class Sistema {
private:
    Utilizador utilizador;
    Catalogo catalogo;
    std::vector<Treino> treinos;   // a substituir por lista ligada na fase seguinte

    void mostrarMenu() const;
    void registarDados();
    void verDados() const;
    void verActividades() const;
    void registarTreino();
    void verTreinos() const;
    void verEstatisticas() const;

public:
    Sistema();
    void executar();   // ciclo principal do menu
};

#endif
