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
	p1= new Peca[12];
	p2= new Peca[12];
	j1= new Jogador(n1,"B",p1);
	j2= new Jogador(n2,"P",p2);

}

Jogo::Jogo()
{
	estado = 0;
	vez = 0;
	p1= new Peca[12];
	p2= new Peca[12];
	j1= new Jogador("jogador1","B",p1);
	j2= new Jogador("jogador2","P",p2);

}

Jogo::~Jogo()
{
	delete [] p1;
	delete [] p2;
	delete j1;
	delete j2;


}

