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
#include "Posicao.h"

class Dama : public Peca
{
public:
	Dama(char);
	bool checaMovimento(Posicao origem, Posicao destino);
	char desenha();
};

#endif /* DAMA_H_ */
