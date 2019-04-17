/*
 * Dama.h
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#ifndef DAMA_H_
#define DAMA_H_

#include <iostream>

class Dama
{
public:
	Dama(std::string, int, int);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* DAMA_H_ */
