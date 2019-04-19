/*
 * Peao.h
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#ifndef PEAO_H_
#define PEAO_H_

#include <iostream>
#include "Peca.h"

class Peao : virtual public Peca
{
public:
	Peao(char);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* PEAO_H_ */
