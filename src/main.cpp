/*#include <iostream>
#include "Utilizador.h"

using namespace std;

int main() {

    Utilizador pessoa;

    cout << "===== BEMVIVER =====\n";
    cout << "Sistema de Gestao de Bem-Estar\n";

    pessoa.inserirDados();

    pessoa.mostrarDados();

    cout << "\nIMC: " << pessoa.calcularIMC() << endl;

    return 0;
}
*/

#include <iostream>
#include "Actividade.h"

using namespace std;

int main() {

    Actividade sistema;

    cout << "===== BEMVIVER =====\n";

    sistema.carregarActividades();

    sistema.listarActividades();

    return 0;
}
