
#ifndef REI_H_
#define REI_H_

#include <iostream>
#include "Peca.h"
#include "Posicao.h"

class Rei : vitual public Peca
{
public:
	Rei(char);
	bool checaMovimento(Posicao origem, Posicao destino);
	void desenha();
};

#endif /* REI_H_ */
