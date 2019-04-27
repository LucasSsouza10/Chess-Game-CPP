/*
 * Torre.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#include "Torre.h"
using namespace std;

Torre::Torre(char c) : Peca(c)
{

}

bool Torre::checaMovimento(Posicao origem, Posicao destino)
{

	if(origem.getColuna() == destino.getColuna()) //movimento nas linhas
		return true;

	else if(origem.getLinha() == destino.getLinha())//movimento nas colunas;
		return true;
	else
		return false;

}

char Torre::desenha()
{
	if(cor == 'B')
		return 'T';
	else
		return 't';
}
