#include "Catalogo.h"

#include <iostream>

using namespace std;

void Catalogo::carregarPredefinidas() {
    const int TOTAL = 8;

    string nomes[TOTAL] = {
        "Caminhada", "Corrida", "Ciclismo", "Musculacao",
        "Natacao", "Yoga", "Danca", "Alongamento"
    };

    string descricoes[TOTAL] = {
        "Caminhar ao ar livre",
        "Corrida continua",
        "Passeio de bicicleta",
        "Exercicios com pesos",
        "Exercicios na agua",
        "Exercicios de flexibilidade",
        "Actividade com movimentos ritmicos",
        "Exercicios de flexibilidade muscular"
    };

    string intensidades[TOTAL] = {
        "Baixa", "Alta", "Media", "Alta",
        "Media", "Baixa", "Media", "Baixa"
    };

    actividades.clear();   // evita duplicados se for chamado duas vezes

    for (int i = 0; i < TOTAL; i++) {
        adicionar(Actividade(i + 1, nomes[i], descricoes[i], intensidades[i]));
    }
}

void Catalogo::adicionar(const Actividade& actividade) {
    actividades.push_back(actividade);
}

void Catalogo::listar() const {
    if (actividades.empty()) {
        cout << "O catalogo esta vazio.\n";
        return;
    }

    for (size_t i = 0; i < actividades.size(); i++) {
        actividades[i].mostrar();
    }
}

int Catalogo::total() const {
    return static_cast<int>(actividades.size());
}

const Actividade* Catalogo::procurarPorId(int id) const {
    for (size_t i = 0; i < actividades.size(); i++) {
        if (actividades[i].getId() == id) {
            return &actividades[i];
        }
    }
    return nullptr;
}
