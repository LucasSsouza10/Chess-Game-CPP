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
#include "Posicao.h"

class Bispo : public Peca
{
public:
	Bispo(char);
	Bispo(const Bispo&);
	bool checaMovimento(Posicao origem, Posicao destino);
	char desenha();

};

#endif /* BISPO_H_ */
