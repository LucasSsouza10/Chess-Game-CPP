
#ifndef POSICAO_H_
#define POSICAO_H_

#include "Peca.h"

class Posicao {
private:
	Peca pca;
	char linha;
	int coluna;
public:
	Posicao(char, int);
	char getLinha();
	int getColuna();
};

#endif /* POSICAO_H_ */
