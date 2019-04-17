/*
 * Torre.h
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#ifndef TORRE_H_
#define TORRE_H_

#include <iostream>

class Torre
{
public:
	Torre(std::string, int, int);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* TORRE_H_ */
