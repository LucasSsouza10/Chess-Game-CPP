/*
 * Bispo.h
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#ifndef BISPO_H_
#define BISPO_H_

#include <iostream>
#include "Peca.h"

class Bispo : virtual public Peca
{
public:
	Bispo(char);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* BISPO_H_ */
