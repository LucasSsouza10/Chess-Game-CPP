/*
 * Dama.h
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#ifndef DAMA_H_
#define DAMA_H_

#include <iostream>
#include "Peca.h"

class Dama : virtual public Peca
{
public:
	Dama(char);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* DAMA_H_ */
