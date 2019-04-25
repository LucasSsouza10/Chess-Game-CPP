/*
 * Jogo.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: lucca
 */

#include "Jogo.h"

Jogo::Jogo(std::string n1,std::string n2)
{
	estado = 0;
	vez = 0;
	p1= new Peca[16];
	p2= new Peca[16];
	j1= new Jogador(n1,"B", p1);
	j2= new Jogador(n2,"P", p2);
	tab = new Tabuleiro(p1, p2);

	for (int i = 8; i < 16; i++) {
		p1[i] = new Peao(j1->getCor());
		p2[i] = new Peao(j2->getCor());

	}

	//torre a esquerda
	p1[0] = new Torre(j1->getCor());
	p2[0] = new Torre(j2->getCor());

	//cavalo a esquerda
	p1[1]= new Cavalo(j1->getCor());
	p2[1]= new Cavalo(j2->getCor());

	//Bispo da esquerda
	p1[2]= new Bispo(j1->getCor());
	p2[2]= new Bispo(j2->getCor());

	//REI
	p1[3]= new Rei(j1->getCor());
	p2[3]= new Rei(j2->getCor());

	//Rainha
	p1[4]= new Dama(j1->getCor());
	p2[4]= new Dama(j2->getCor());

	//Bispo da direita
	p1[5]= new Bispo(j1->getCor());
	p2[5]= new Bispo(j2->getCor());

	//Cavalo da Direita
	p1[6]= new Cavalo(j1->getCor());
	p2[6]= new Cavalo(j2->getCor());

	//Torre da Direita
	p1[7]= new Torre(j1->getCor());
	p2[7]= new Torre(j2->getCor());






}

Jogo::Jogo()
{
	estado = 0;
	vez = 0;
	p1= new Peca[16];
	p2= new Peca[16];
	j1= new Jogador("Jogador1","B", p1);
	j2= new Jogador("Jogador2","P", p2);
	tab = new Tabuleiro(p1, p2);

	for (int i = 8; i < 16; i++) {
		p1[i] = new Peao(j1->getCor());
		p2[i] = new Peao(j2->getCor());

	}

	//torre a esquerda
	p1[0] = new Torre(j1->getCor());
	p2[0] = new Torre(j2->getCor());

	//cavalo a esquerda
	p1[1]= new Cavalo(j1->getCor());
	p2[1]= new Cavalo(j2->getCor());

	//Bispo da esquerda
	p1[2]= new Bispo(j1->getCor());
	p2[2]= new Bispo(j2->getCor());

	//REI
	p1[3]= new Rei(j1->getCor());
	p2[3]= new Rei(j2->getCor());

	//Rainha
	p1[4]= new Dama(j1->getCor());
	p2[4]= new Dama(j2->getCor());

	//Bispo da direita
	p1[5]= new Bispo(j1->getCor());
	p2[5]= new Bispo(j2->getCor());

	//Cavalo da Direita
	p1[6]= new Cavalo(j1->getCor());
	p2[6]= new Cavalo(j2->getCor());

	//Torre da Direita
	p1[7]= new Torre(j1->getCor());
	p2[7]= new Torre(j2->getCor());

}

Jogo::~Jogo()
{
	delete [] p1;
	delete [] p2;
	delete j1;
	delete j2;


}

void Jogo::setEstado(int est)
{
	estado=est;
}
void Jogo::setVez(int v)
{
	vez=v;
}
