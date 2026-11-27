#include "Estatisticas.h"

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int Estatisticas::totalTreinos(const vector<Treino>& treinos) {
    return static_cast<int>(treinos.size());
}

int Estatisticas::totalMinutos(const vector<Treino>& treinos) {
    int total = 0;

    for (size_t i = 0; i < treinos.size(); i++) {
        total += treinos[i].getDuracao();
    }
    return total;
}

double Estatisticas::mediaDuracao(const vector<Treino>& treinos) {
    if (treinos.empty()) {
        return 0.0;   // evita dividir por zero
    }
    return static_cast<double>(totalMinutos(treinos)) / treinos.size();
}

string Estatisticas::actividadeMaisFrequente(const vector<Treino>& treinos) {
    map<string, int> contagens;   // nome da actividade -> numero de treinos

    for (size_t i = 0; i < treinos.size(); i++) {
        contagens[treinos[i].getNomeActividade()]++;
    }

    string melhor = "";
    int maior = 0;

    for (map<string, int>::const_iterator it = contagens.begin();
         it != contagens.end(); ++it) {
        if (it->second > maior) {
            maior = it->second;
            melhor = it->first;
        }
    }
    return melhor;
}

void Estatisticas::mostrarMinutosPorMes(const vector<Treino>& treinos) {
    // A chave e "AAAA/MM" (e nao "MM/AAAA") para o map ordenar cronologicamente.
    map<string, int> minutos;

    for (size_t i = 0; i < treinos.size(); i++) {
        string data = treinos[i].getData();                  // DD/MM/AAAA
        string chave = data.substr(6, 4) + "/" + data.substr(3, 2);
        minutos[chave] += treinos[i].getDuracao();
    }

    cout << "\nMinutos por mes:\n";

    for (map<string, int>::const_iterator it = minutos.begin();
         it != minutos.end(); ++it) {
        string mes = it->first.substr(5, 2);
        string ano = it->first.substr(0, 4);
        cout << "  " << mes << "/" << ano << ": " << it->second << " min\n";
    }
}

void Estatisticas::mostrarResumo(const vector<Treino>& treinos) {
    cout << "\n===== ESTATISTICAS =====\n";

    if (treinos.empty()) {
        cout << "Ainda nao ha treinos registados.\n";
        return;
    }

    cout << "Total de treinos: " << totalTreinos(treinos) << endl;
    cout << "Tempo total: " << totalMinutos(treinos) << " minutos\n";
    printf("Duracao media: %.1f minutos\n", mediaDuracao(treinos));
    cout << "Actividade mais frequente: " << actividadeMaisFrequente(treinos) << endl;

    mostrarMinutosPorMes(treinos);
}
