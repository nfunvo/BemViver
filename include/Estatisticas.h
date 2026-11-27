#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <string>
#include <vector>
#include "Treino.h"

// Calcula resumos a partir dos treinos registados.
// Nao guarda dados nem tem estado: todos os metodos sao estaticos
// e recebem os treinos como parametro.
class Estatisticas {
public:
    static int totalTreinos(const std::vector<Treino>& treinos);
    static int totalMinutos(const std::vector<Treino>& treinos);
    static double mediaDuracao(const std::vector<Treino>& treinos);

    // Nome da actividade mais praticada ("" se nao houver treinos).
    // Em caso de empate, fica a primeira por ordem alfabetica.
    static std::string actividadeMaisFrequente(const std::vector<Treino>& treinos);

    // Minutos treinados em cada mes, por ordem cronologica.
    static void mostrarMinutosPorMes(const std::vector<Treino>& treinos);

    static void mostrarResumo(const std::vector<Treino>& treinos);
};

#endif
