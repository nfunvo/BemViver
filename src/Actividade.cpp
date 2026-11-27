#include "Actividade.h"

#include <iostream>

using namespace std;

Actividade::Actividade()
    : id(0), nome(""), descricao(""), intensidade("") {}

Actividade::Actividade(int novoId, const string& novoNome,
                       const string& novaDescricao,
                       const string& novaIntensidade)
    : id(novoId), nome(novoNome), descricao(novaDescricao),
      intensidade(novaIntensidade) {}

int Actividade::getId() const { return id; }
string Actividade::getNome() const { return nome; }
string Actividade::getDescricao() const { return descricao; }
string Actividade::getIntensidade() const { return intensidade; }

void Actividade::mostrar() const {
    cout << "ID: " << id << " | " << nome
         << " | Intensidade: " << intensidade << endl;
    cout << "    " << descricao << endl;
}
