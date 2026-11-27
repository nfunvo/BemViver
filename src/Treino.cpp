
#include <iostream>
#include <limits>
#include "Treino.h"

using namespace std;

void Treino::registarTreino(Actividade& catalogo) {

    int codigo;

    cout << "\n===== REGISTO DE TREINO =====\n";

    cout << "\nID do treino: ";
    cin >> id;

    cout << "\n";
    catalogo.listarActividades();

    cout << "\nEscolha o ID da actividade: ";
    cin >> codigo;

    if (!catalogo.selecionarActividade(codigo)) {
        cout << "\nActividade nao encontrada!\n";
        return;
    }

    actividade = catalogo.getNome();

    cout << "Duracao do treino (minutos): ";
    cin >> duracao;

    while (duracao <= 0) {
        cout << "Duracao invalida. Introduza novamente: ";
        cin >> duracao;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Data do treino (DD/MM/AAAA): ";
    getline(cin, data);

    cout << "\nTreino registado com sucesso!\n";
}

void Treino::mostrarTreino() {

    cout << "\n===== DADOS DO TREINO =====\n";

    cout << "ID: " << id << endl;
    cout << "Actividade: " << actividade << endl;
    cout << "Duracao: " << duracao << " minutos" << endl;
    cout << "Data: " << data << endl;
}

int Treino::getDuracao() {
    return duracao;
}

string Treino::getActividade() {
    return actividade;
}
