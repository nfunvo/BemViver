#ifndef ACTIVIDADE_H
#define ACTIVIDADE_H

#include <string>

// Representa UMA actividade fisica (ex.: Corrida).
// A colecao de actividades fica na classe Catalogo.
class Actividade {
private:
    int id;
    std::string nome;
    std::string descricao;
    std::string intensidade;

public:
    Actividade();
    Actividade(int novoId, const std::string& novoNome,
               const std::string& novaDescricao,
               const std::string& novaIntensidade);

    int getId() const;
    std::string getNome() const;
    std::string getDescricao() const;
    std::string getIntensidade() const;

    void mostrar() const;
};

#endif
