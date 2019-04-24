/*
 * Dama.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#include "Dama.h"
#include <math.h>

Dama::Dama(char c) : Peca(c)
{

}


bool Dama::checaMovimento(Posicao origem, Posicao destino)
{
	if(destino.getColuna() == origem.getColuna()) // movimento na linha
		if(destino.isOcupada() && destino.getCor() != cor)
						return true;
					else
						return false;
	else if(destino.getLinha() == origem.getLinha()) //movimento na coluna
		if(destino.isOcupada() && destino.getCor() != cor)
						return true;
					else
						return false;
	else if(abs(destino.getColuna() - origem.getColuna()) == abs(destino.getLinha() - origem.getLinha())) //movimento diagonal
		if(destino.isOcupada() && destino.getPca().getCor() != cor)
						return true;
					else
						return false;
	else
		return false;
}
