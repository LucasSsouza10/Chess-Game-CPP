#ifndef TORRE_H_
#define TORRE_H_

#include <iostream>
#include "Peca.h"
#include "Posicao.h"

class Torre : virtual public Peca
{
public:
	Torre(char);
	bool checaMovimento(Posicao origem, Posicao destino);
	char desenha();
};

#endif /* TORRE_H_ */
