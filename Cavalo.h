/*
 * Cavalo.h
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#ifndef CAVALO_H_
#define CAVALO_H_
#include <iostream>

class Cavalo
{
public:
	Cavalo(std::string, int, int);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* CAVALO_H_ */
