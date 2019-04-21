
#ifndef POSICAO_H_
#define POSICAO_H_

#include "Peca.h"


class Posicao {
private:
	Peca pca;
	char cor;
	char linha;
	int coluna;
public:
	Posicao(char, int, char);
	char getLinha();
	int getColuna();
	char getCor();
	bool isOcupada();

};

#endif /* POSICAO_H_ */
