
#ifndef REI_H_
#define REI_H_

#include <iostream>
#include "Peca.h"

class Rei : vitual public Peca
{
public:
	Rei(char);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* REI_H_ */
