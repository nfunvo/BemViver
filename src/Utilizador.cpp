#include "Utilizador.h"

#include <iostream>
#include "Entrada.h"

using namespace std;

Utilizador::Utilizador()
    : nome(""), idade(0), peso(0.0), altura(0.0), preenchido(false) {}

void Utilizador::inserirDados() {
    cout << "\n--- REGISTO DE UTILIZADOR ---\n";

    nome    = lerTexto("Nome: ");
    idade   = lerInteiro("Idade: ", 1, 120);
    peso    = lerDecimal("Peso (kg): ", 1, 500);
    altura  = lerDecimal("Altura (metros): ", 0.5, 2.8);

    preenchido = true;
}

void Utilizador::mostrarDados() const {
    cout << "\n--- DADOS DO UTILIZADOR ---\n";

    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "Altura: " << altura << " m" << endl;
}

double Utilizador::calcularIMC() const {
    if (altura <= 0) {
        return 0;
    }
    return peso / (altura * altura);
}

bool Utilizador::temDados() const {
    return preenchido;
}
