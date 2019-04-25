/*
 * Torre.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#include "Torre.h"

Torre::Torre(char c) : Peca(c)
{

}

bool Torre::checaMovimento(Posicao origem, Posicao destino)
{
	if(origem.getColuna() == destino.getColuna()) //movimento nas linhas
		if(destino.isOcupada() && destino.getCor() != cor)
			return true;
		else
			return false;

	else if(origem.getLinha == destino.getLinha())//movimento nas colunas;
		if(destino.isOcupada() && destino.getCor() != cor)
			return true;
		else
			return false;
	else
		return false;

}

char Torre::desenha()
{
	if(cor == "B")
		return "T";
	else
		return "t";
}
