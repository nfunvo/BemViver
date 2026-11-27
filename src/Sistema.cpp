#include "Sistema.h"

#include <cstdio>
#include <iostream>
#include "Entrada.h"
#include "Estatisticas.h"

using namespace std;

Sistema::Sistema() {
    catalogo.carregarPredefinidas();
}

void Sistema::mostrarMenu() const {
    cout << "\n=============================\n";
    cout << "          BEMVIVER\n";
    cout << "   Sistema de Bem-Estar\n";
    cout << "=============================\n";
    cout << "1. Registar / actualizar os meus dados\n";
    cout << "2. Ver os meus dados e IMC\n";
    cout << "3. Ver actividades disponiveis\n";
    cout << "4. Registar treino\n";
    cout << "5. Ver treinos registados\n";
    cout << "6. Ver estatisticas\n";
    cout << "0. Sair\n";
}

void Sistema::registarDados() {
    utilizador.inserirDados();
}

void Sistema::verDados() const {
    if (!utilizador.temDados()) {
        cout << "\nAinda nao registou os seus dados (opcao 1).\n";
        return;
    }

    utilizador.mostrarDados();
    printf("IMC: %.1f\n", utilizador.calcularIMC());
}

void Sistema::verActividades() const {
    cout << "\n===== ACTIVIDADES DISPONIVEIS =====\n";
    catalogo.listar();
}

void Sistema::registarTreino() {
    Treino novo;

    if (novo.registar(catalogo)) {
        treinos.push_back(novo);
        cout << "\nTreino registado com sucesso!\n";
    }
}

void Sistema::verTreinos() const {
    cout << "\n===== TREINOS REGISTADOS =====\n";

    if (treinos.empty()) {
        cout << "Ainda nao ha treinos registados.\n";
        return;
    }

    for (size_t i = 0; i < treinos.size(); i++) {
        treinos[i].mostrar();
    }
}

void Sistema::verEstatisticas() const {
    Estatisticas::mostrarResumo(treinos);
}

void Sistema::executar() {
    int opcao;

    do {
        mostrarMenu();
        opcao = lerInteiro("Opcao: ", 0, 6);

        switch (opcao) {
            case 1: registarDados();    break;
            case 2: verDados();         break;
            case 3: verActividades();   break;
            case 4: registarTreino();   break;
            case 5: verTreinos();       break;
            case 6: verEstatisticas();  break;
            case 0: cout << "\nAte breve!\n"; break;
        }
    } while (opcao != 0);
}
