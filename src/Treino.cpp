#include "Treino.h"

#include <iostream>
#include "Entrada.h"

using namespace std;

// Definicao do atributo estatico (obrigatoria fora da classe)
int Treino::proximoId = 1;

Treino::Treino()
    : id(0), idActividade(0), nomeActividade(""), duracao(0), data("") {}

bool Treino::registar(const Catalogo& catalogo) {
    cout << "\n===== REGISTO DE TREINO =====\n\n";

    if (catalogo.total() == 0) {
        cout << "Nao existem actividades no catalogo.\n";
        return false;
    }

    catalogo.listar();

    int codigo = lerInteiro("\nEscolha o ID da actividade (0 para cancelar): ", 0, 9999);
    if (codigo == 0) {
        cout << "Registo cancelado.\n";
        return false;
    }

    const Actividade* escolhida = catalogo.procurarPorId(codigo);
    if (escolhida == nullptr) {
        cout << "\nActividade nao encontrada!\n";
        return false;
    }

    // Os dados ficam em variaveis locais ate estarem todos validos.
    // So no fim e que o objecto e alterado.
    int novaDuracao = lerInteiro("Duracao do treino (minutos): ", 1, 1440);
    string novaData = lerData("Data do treino (DD/MM/AAAA): ");

    id = proximoId++;
    idActividade = escolhida->getId();
    nomeActividade = escolhida->getNome();
    duracao = novaDuracao;
    data = novaData;

    return true;
}

void Treino::mostrar() const {
    cout << "Treino #" << id << " | " << nomeActividade
         << " | " << duracao << " min | " << data << endl;
}

int Treino::getId() const { return id; }
int Treino::getDuracao() const { return duracao; }
string Treino::getNomeActividade() const { return nomeActividade; }
string Treino::getData() const { return data; }
