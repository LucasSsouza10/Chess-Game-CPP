/*
 * Peao.h
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#ifndef PEAO_H_
#define PEAO_H_

#include <iostream>

class Peao
{
public:
	Peao(std::string, int, int);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* PEAO_H_ */
