/*
 * Cavalo.h
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#ifndef CAVALO_H_
#define CAVALO_H_
#include <iostream>
#include "Peca.h"

class Cavalo : virtual public Peca
{
public:
	Cavalo(char);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* CAVALO_H_ */
