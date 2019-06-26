#ifndef CAVALO_H_
#define CAVALO_H_

#include <iostream>
#include "Peca.h"
#include "Posicao.h"

class Cavalo: public Peca {

public:
	Cavalo(char);
	Cavalo(Cavalo const&);
	Cavalo * clone() const;
	bool checaMovimento(Posicao origem, Posicao destino);
	char desenha();
};

#endif /* CAVALO_H_ */
