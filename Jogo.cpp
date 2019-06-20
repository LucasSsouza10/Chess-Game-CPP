/*
 * Jogo.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: lucca
 */

#include "Jogo.h"

using namespace std;

Jogo::Jogo(string n1, string n2) {
	estado = 0;
	vez = 2; //2 para quando iniciar o jogo comecar pelo jogador 1
	j1 = new Jogador(n1, 'B');
	j2 = new Jogador(n2, 'P');

	//criando pecas
	criarPecas();
	//setando pecas para os jogadores
	for (int i = 0; i < 16; ++i) {
		j1->addPecas(p[i]);
		j2->addPecas(p[i + 16]);
	}

	//criando tabuleiro e setando pecas
	tab = new Tabuleiro(p);

}

Jogo::Jogo() {
	estado = 0;
	vez = 0;

	j1 = new Jogador("Jogador1", 'B');
	j2 = new Jogador("Jogador2", 'P');
	//criando pecas
	criarPecas();
	//setando pecas para os jogadores
	for (int i = 0; i < 16; ++i) {
		j1->addPecas(p[i]);
		j2->addPecas(p[i + 16]);
	}

	//criando tabuleiro e setando pecas
	tab = new Tabuleiro(p);
}

Jogo::~Jogo() {
	for (int i = 0; i < 32; ++i) {
		delete p[i];
	}
	delete j1;
	delete j2;

}

void Jogo::criarPecas() {
	//Criando peaos
	for (int i = 8; i < 16; i++) {
		p[i] = new Peao(j1->getCor());
		p[i + 16] = new Peao(j2->getCor());
	}

	//torre a esquerda
	p[0] = new Torre(j1->getCor());
	p[16] = new Torre(j2->getCor());

	//cavalo a esquerda
	p[1] = new Cavalo(j1->getCor());
	p[17] = new Cavalo(j2->getCor());

	//Bispo da esquerda
	p[2] = new Bispo(j1->getCor());
	p[18] = new Bispo(j2->getCor());

	//REI
	p[3] = new Rei(j1->getCor());
	p[19] = new Rei(j2->getCor());

	//Rainha
	p[4] = new Dama(j1->getCor());
	p[20] = new Dama(j2->getCor());

	//Bispo da direita
	p[5] = new Bispo(j1->getCor());
	p[21] = new Bispo(j2->getCor());

	//Cavalo da Direita
	p[6] = new Cavalo(j1->getCor());
	p[22] = new Cavalo(j2->getCor());

	//Torre da Direita
	p[7] = new Torre(j1->getCor());
	p[23] = new Torre(j2->getCor());

}

void Jogo::setEstado(int est) {
	estado = est;
}
void Jogo::setVez(int v) {
	vez = v;
}

void Jogo::playGame() {
	string move;

	while (true) {

		//depois de cada movimento trocamos a vez de jogar
		if (vez == 1)
			vez = 2;
		else
			vez = 1;

		//Mostra o tabuleiro
		tab->desenharTabuleiro();

		//Pedido de entrada de movimento
		cout << "Jogador " << vez << " por favor entre com seu movimento: ";
		getline(cin, move);

		while (validarFormato(move) == false) {
			cout << "Formato invalido. Tente novamente: ";
			getline(cin, move);
		}

		while (mover(move) == false) {

			cout << "Movimento invalido. Tente novamente: ";
			getline(cin, move);

			while (validarFormato(move) == false) {
				cout << "Formato invalido. Tente novamente: ";
				getline(cin, move);
			}
		}
	}
}

bool Jogo::validarFormato(string m) {

	//Um movimento valido tem 8 caracteres
	if (m.length() != 8) {
		return false;
	}

	//verifica se a linha da entrada eh valido com o tamanho do tabuleiro para origem
	if (toupper(m[0]) <= 'A' && toupper(m[0]) >= 'H') {
		return false;
	}

	//verifica se a coluna é valida para origem
	if (m[1] <= '1' && m[1] >= '8') {
		return false;
	}

	if (m[3] != '-' || m[4] != '>') {
		return false;
	}

	//verifica se eh uma linha valida para destino
	if (toupper(m[6]) <= 'A' && toupper(m[6]) >= 'H') {
		return false;
	}

	//verifica se eh uma coluna valida para destino
	if (m[7] <= '1' && m[7] >= '8') {
		return false;
	}

	else
		return true;
}

bool Jogo::mover(string m) {
	int origemLinha, origemColuna, destinoLinha, destinoColuna;
	origemLinha = m[1] - '1'; //para transformar o caractere em um int correspondente
	origemColuna = toupper(m[0]) - 'A';
	destinoLinha = m[7] - '1';
	destinoColuna = toupper(m[6]) - 'A';
	cout<< "OrigemLinha: " << origemLinha << " OrigemColuna: " << origemColuna << endl;
	cout<< "DestinoLinhas: " << destinoLinha << " DestinoColuna: " << destinoColuna << endl;
	bool mov = tab->movimenta(origemLinha, origemColuna, destinoLinha,destinoColuna);
	cout<< mov << endl;
	return mov;
}
