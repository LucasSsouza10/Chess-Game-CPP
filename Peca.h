#ifndef PECA_H_
#define PECA_H_

#include <iostream>
#include "Posicao.h"
class Posicao;

class Peca {
protected:
	char cor;
	int situacao; // 1 Em jogo ou 0 capturada
public:
	Peca(char);
	virtual ~Peca();
	virtual bool checaMovimento(Posicao origem, Posicao destino);
	virtual char desenha();
	char getCor();
	void setSituacao(); //Troca situção para capturada
};

#endif /* PECA_H_ */
