#ifndef PEAO_H_
#define PEAO_H_

#include <iostream>
#include "Peca.h"
#include "Posicao.h"

class Peao
{
private:
	char cor;
	std::string situacao; //"capturada" ou "em jogo"
public:
	Peao(char);
	bool checaMovimento(Posicao origem, Posicao destino);
	void desenha();
};

#endif /* PEAO_H_ */
