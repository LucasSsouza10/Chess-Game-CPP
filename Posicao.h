
#ifndef POSICAO_H_
#define POSICAO_H_

#include "Peca.h"

class Peca;

class Posicao {
private:
	Peca *pca;
	char cor;
	int linha;
	int coluna;
	bool ocupada;
public:
	Posicao();
	Posicao(Posicao const &p); //Construtor de c�pia
	int getLinha();
	int getColuna();
	char getCor();
	bool isOcupada();
	Peca * getPca();
	void setPca(Peca*);
	void setCor(char);
	void setColuna(int);
	void setLinha(int);

};

#endif /* POSICAO_H_ */
