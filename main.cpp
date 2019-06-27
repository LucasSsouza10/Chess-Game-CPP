#include <iostream>
#include "Jogo.h"

using namespace std;

int main() {
	cout << "---------- XADREZ ----------" << endl;
	char n;
	cout << "Deseja inserir nome? S/N" << endl;
	cin >> n;
	n = toupper(n);

	while (n != 'N' && n != 'S') {
		cout << "Entrada invalida! Digite: (S/N)";
		cin >> n;
		n = toupper(n);
	}

	if (n == 'S') {
		string j1, j2;
		cout << "Jogador 1, por favor, digite seu nome: " << endl;
		cin >> j1;
		cout << "Jogador 2, por favor, digite seu nome:" << endl;
		cin >> j2;
		Jogo jogo(j1, j2);

		char op;
		cout << "Deseja retornar ao último ponto de parada? (S/N)";
		cin >> op;
		op = toupper(op);
		while (op != 'N' && op != 'S') {
			cout << "Entrada invalida! Digite: S/N: ";
			cin >> op;
			op = toupper(op);
		}

		if (op == 'S') {
			cout << "Carregando o jogo..." << endl;
			jogo.carregar(); //carrega jogo salvo
		} else {
			jogo.limparSalvo(); //começa um novo jogo
		}

		cin.ignore();
		jogo.playGame();
		cout << "Jogo finalizado." << endl;

	} else {

		Jogo jogo;

		char op;
		cout << "Deseja retornar ao último ponto de parada? (S/N)";
		cin >> op;
		op = toupper(op);
		while (op != 'N' && op != 'S') {
			cout << "Entrada invalida! Digite: S/N: ";
			cin >> op;
			op = toupper(op);
		}

		if (op == 'S') {
			cout << "Carregando o jogo..." << endl;
			jogo.carregar(); //carrega jogo salvo
		} else {
			jogo.limparSalvo(); //começa um novo jogo
		}

		cin.ignore();
		jogo.playGame();
		cout << "Jogo finalizado." << endl;
	}
}

