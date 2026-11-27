#ifndef UTILIZADOR_H
#define UTILIZADOR_H

#include <string>

class Utilizador {
private:
    std::string nome;
    int idade;
    double peso;      // kg
    double altura;    // metros
    bool preenchido;

public:
    Utilizador();

    void inserirDados();
    void mostrarDados() const;
    double calcularIMC() const;
    bool temDados() const;
};

#endif
