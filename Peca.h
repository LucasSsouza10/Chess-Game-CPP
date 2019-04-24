#ifndef PECA_H_
#define PECA_H_

#include <iostream>

class Peca {
protected:
	char cor;
	std::string situacao;
public:
	Peca(char);
	virtual ~Peca(){	}
	virtual bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	virtual void desenha();
	char getCor();
};

#endif /* PECA_H_ */
