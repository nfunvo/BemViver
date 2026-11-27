#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include "Actividade.h"

// Guarda e gere a colecao de actividades disponiveis.
class Catalogo {
private:
    std::vector<Actividade> actividades;   // a substituir por estrutura propria na fase seguinte

public:
    void carregarPredefinidas();
    void adicionar(const Actividade& actividade);
    void listar() const;
    int total() const;

    // Devolve um ponteiro para a actividade, ou nullptr se o ID nao existir.
    // Atencao: o ponteiro deixa de ser valido se o catalogo crescer.
    const Actividade* procurarPorId(int id) const;
};

#endif
