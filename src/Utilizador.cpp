
#include <iostream>
#include "Utilizador.h"

using namespace std;

void Utilizador::inserirDados() {
    cout << "\n--- REGISTO DE UTILIZADOR ---\n";

    cout << "Nome: ";
    getline(cin, nome);

    cout << "Idade: ";
    cin >> idade;

    cout << "Peso (kg): ";
    cin >> peso;

    cout << "Altura (metros): ";
    cin >> altura;
}

void Utilizador::mostrarDados() {
    cout << "\n--- DADOS DO UTILIZADOR ---\n";

    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "Altura: " << altura << " m" << endl;
}

float Utilizador::calcularIMC() {
    if (altura <= 0) {
        return 0;
    }

    return peso / (altura * altura);
}
