#ifndef PECA_H_
#define PECA_H_

#include <iostream>
#include "Posicao.h"
class Posicao;

class Peca {
protected:
	char cor;
	std::string situacao;
public:
	Peca(char);
	virtual ~Peca();
	virtual bool checaMovimento(Posicao origem, Posicao destino);
	virtual char desenha();
	char getCor();
};

#endif /* PECA_H_ */
