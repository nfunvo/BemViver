
#include <iostream>
#include "Actividade.h"

using namespace std;

//construtuor
Actividade::Actividade() {
    id = 0;
    nome = "";
    descricao = "";
    intensidade = "";
}

// Catalogo de actividades
vector<Actividade> catalogo;

// Carregar actividades pre-estabelecidas
void Actividade::carregarActividades() {

    string nomes[] = {
        "Caminhada",
        "Corrida",
        "Ciclismo",
        "Musculacao",
        "Natacao",
        "Yoga",
        "Danca",
        "Alongamento"
    };

    string descricoes[] = {
        "Caminhar ao ar livre",
        "Corrida continua",
        "Passeio de bicicleta",
        "Exercicios com pesos",
        "Exercicios na agua",
        "Exercicios de flexibilidade",
        "Actividade com movimentos ritmicos",
        "Exercicios de flexibilidade muscular"
    };

    string intensidades[] = {
        "Baixa", "Alta", "Media", "Alta",
        "Media", "Baixa", "Media", "Baixa"
    };

    for (int i = 0; i < 8; i++) {
        Actividade a;

        a.id = i + 1;
        a.nome = nomes[i];
        a.descricao = descricoes[i];
        a.intensidade = intensidades[i];

        catalogo.push_back(a);
    }
}

// Listar actividades
void Actividade::listarActividades() {

    cout << "\n===== ACTIVIDADES DISPONIVEIS =====\n";

    for (int i = 0; i < catalogo.size(); i++) {

        cout << "\nID: " << catalogo[i].id << endl;
        cout << "Nome: " << catalogo[i].nome << endl;
        cout << "Intensidade: "
             << catalogo[i].intensidade << endl;
    }
}

// Registar uma nova actividade
void Actividade::registarActividade() {

    cout << "\n--- NOVA ACTIVIDADE ---\n";

    cout << "ID: ";
    cin >> id;
    cin.ignore();

    cout << "Nome: ";
    getline(cin, nome);

    cout << "Descricao: ";
    getline(cin, descricao);

    cout << "Intensidade: ";
    getline(cin, intensidade);
}

// Mostrar actividade
void Actividade::mostrarActividade() {

    cout << "\n--- DADOS DA ACTIVIDADE ---\n";

    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Descricao: " << descricao << endl;
    cout << "Intensidade: " << intensidade << endl;
}

string Actividade::getNome() {
    return nome;
}
