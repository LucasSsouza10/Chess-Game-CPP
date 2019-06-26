/*
 * Dama.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#include "Dama.h"
#include <math.h>

Dama::Dama(char c) :
		Peca(c) {

}

bool Dama::checaMovimento(Posicao origem, Posicao destino) {
	if (destino.getColuna() == origem.getColuna()) // movimento na linha
		return true;

	else if (destino.getLinha() == origem.getLinha()) //movimento na coluna

		return true;

	else if (abs(destino.getColuna() - origem.getColuna())
			== abs(destino.getLinha() - origem.getLinha())) //movimento diagonal
		return true;

	else
		return false;
}

char Dama::desenha() {
	if (cor == 'B')
		return 'D';
	else
		return 'd';
}

//construtor de copia
Dama::Dama(const Dama &p) : Peca(p.cor) {

}

