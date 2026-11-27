#ifndef ENTRADA_H
#define ENTRADA_H

#include <string>

// Funcoes de leitura segura do teclado.
// Todas repetem a pergunta ate o utilizador dar um valor valido.

std::string lerTexto(const std::string& mensagem);
int         lerInteiro(const std::string& mensagem, int minimo, int maximo);
double      lerDecimal(const std::string& mensagem, double minimo, double maximo);
std::string lerData(const std::string& mensagem);   // formato DD/MM/AAAA

#endif
