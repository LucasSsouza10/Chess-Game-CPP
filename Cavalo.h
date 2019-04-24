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
#include "Posicao.h"

class Cavalo : virtual public Peca
{
private:
	char cor;

public:
	Cavalo(char);
	bool checaMovimento(Posicao origem, Posicao destino);
	void desenha();
};

#endif /* CAVALO_H_ */
