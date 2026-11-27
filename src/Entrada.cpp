#include "Entrada.h"

#include <cstdlib>
#include <iostream>

using namespace std;

// Remove espacos, tabs e '\r' do inicio e do fim.
static string aparar(const string& s) {
    size_t inicio = s.find_first_not_of(" \t\r");
    if (inicio == string::npos) {
        return "";
    }
    size_t fim = s.find_last_not_of(" \t\r");
    return s.substr(inicio, fim - inicio + 1);
}

// Le sempre uma LINHA INTEIRA (getline) e nunca usa "cin >>".
// Assim nao sobram '\n' no buffer e o cin nunca entra em estado de erro.
string lerTexto(const string& mensagem) {
    string linha;

    while (true) {
        cout << mensagem;

        if (!getline(cin, linha)) {          // fim da entrada (Ctrl+Z / Ctrl+D)
            cout << "\nEntrada terminada.\n";
            exit(1);
        }

        linha = aparar(linha);
        if (!linha.empty()) {
            return linha;
        }
        cout << "O campo nao pode estar vazio.\n";
    }
}

int lerInteiro(const string& mensagem, int minimo, int maximo) {
    while (true) {
        string texto = lerTexto(mensagem);

        try {
            size_t usados = 0;
            int valor = stoi(texto, &usados);

            // "usados" garante que o texto inteiro era um numero ("12abc" e rejeitado)
            if (usados == texto.size() && valor >= minimo && valor <= maximo) {
                return valor;
            }
        } catch (...) {
            // texto nao numerico: cai na mensagem de erro abaixo
        }

        cout << "Valor invalido. Introduza um inteiro entre "
             << minimo << " e " << maximo << ".\n";
    }
}

double lerDecimal(const string& mensagem, double minimo, double maximo) {
    while (true) {
        string texto = lerTexto(mensagem);

        // aceita tanto 1.75 como 1,75
        for (size_t i = 0; i < texto.size(); i++) {
            if (texto[i] == ',') {
                texto[i] = '.';
            }
        }

        try {
            size_t usados = 0;
            double valor = stod(texto, &usados);

            if (usados == texto.size() && valor >= minimo && valor <= maximo) {
                return valor;
            }
        } catch (...) {
        }

        cout << "Valor invalido. Introduza um numero entre "
             << minimo << " e " << maximo << ".\n";
    }
}

// Verifica formato DD/MM/AAAA e se a data existe (inclui anos bissextos).
static bool dataValida(const string& d) {
    if (d.size() != 10 || d[2] != '/' || d[5] != '/') {
        return false;
    }

    for (size_t i = 0; i < d.size(); i++) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (d[i] < '0' || d[i] > '9') {
            return false;
        }
    }

    int dia = stoi(d.substr(0, 2));
    int mes = stoi(d.substr(3, 2));
    int ano = stoi(d.substr(6, 4));

    if (ano < 2000 || ano > 2100 || mes < 1 || mes > 12) {
        return false;
    }

    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    if (bissexto) {
        diasNoMes[1] = 29;
    }

    return dia >= 1 && dia <= diasNoMes[mes - 1];
}

string lerData(const string& mensagem) {
    while (true) {
        string data = lerTexto(mensagem);

        if (dataValida(data)) {
            return data;
        }
        cout << "Data invalida. Use o formato DD/MM/AAAA (ex.: 15/11/2026).\n";
    }
}
