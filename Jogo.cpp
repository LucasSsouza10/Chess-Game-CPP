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
	vez = 0;
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

void Jogo::movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino,
		int colunaDestino) {
	tab->movimenta(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
}

void Jogo::desenharTabuleiro() {
	tab->desenharTabuleiro();
}

Jogador Jogo::getJogador1() {
	return *j1;
}

Jogador Jogo::getJogador2() {
	return *j2;
}
