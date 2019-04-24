#ifndef PEAO_H_
#define PEAO_H_

#include <iostream>
#include "Peca.h"
#include "Posicao.h"

class Peao : virtual public Peca
{
public:
	Peao(char);
	bool checaMovimento(Posicao origem, Posicao destino);
	void desenha();
};

#endif /* PEAO_H_ */
