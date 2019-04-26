
#ifndef POSICAO_H_
#define POSICAO_H_

#include "Peca.h"


class Posicao {
private:
	Peca *pca;
	char cor;
	int linha;
	char coluna;
	bool ocupada;
public:
	Posicao();
	char getLinha();
	int getColuna();
	char getCor();
	bool isOcupada();
	Peca getPca();
	void setPca(Peca);
	void setCor(char);
	void setColuna(char);
	void setLinha(int);

};

#endif /* POSICAO_H_ */
