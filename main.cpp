#include <iostream>
#include "Jogo.h"
#include "Posicao.h"
#include "Dama.h"
#include "Torre.h"
#include "Rei.h"
#include "Cavalo.h"
#include "Bispo.h"

using namespace std;

int main() {
	Jogo jogo;
	char op;
	cout << "Deseja retornar ao último ponto de parada: S/N: ";
	cin >> op;
	op = toupper(op);
	while (op != 'N' && op != 'S') {
		cout << "Entrada invalida! Digite: S/N: ";
		cin >> op;
		op = toupper(op);
	}

	if (op == 'S')
		jogo.carregar(); //carrega jogo salvo
	else {
		jogo.limparSalvo(); //começa um novo jogo
	}

	cin.ignore();
	jogo.playGame();
	cout << "Jogo finalizado." << endl;
}

