#ifndef PEAO_H_
#define PEAO_H_

#include <iostream>
#include "Peca.h"
#include "Posicao.h"

class Peao : public Peca
{
public:
	Peao(char);
	Peao(Peao const &);
	Peao * clone() const;
	bool checaMovimento(Posicao origem, Posicao destino);
	char desenha();

};

#endif /* PEAO_H_ */
