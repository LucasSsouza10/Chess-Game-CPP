/*
 * Bispo.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#include "Bispo.h"
#include "Posicao.h"

Bispo::Bispo(char)
{

}

Bispo::~Bispo()
{

}

bool Bispo::checaMovimento(Posicao origem, Posicao destino)
{
	if (destino.getLinha - origem.getLinha == destino.getColuna - origem.getColuna)
		return true;
	else
		return false;
}





