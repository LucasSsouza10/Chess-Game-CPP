
#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include "Posicao.h"
#include "Peca.h"

class Tabuleiro {
private:
	Posicao **pos;

public:
	Tabuleiro(Peca **p);	//responsavel pela configuração inicial do tabuleiro
	bool movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); // responsavel pela manutenção e checagem do tabuleiro a cada jogada
	void desenharTabuleiro(); //desenha o tabuleiro na tela
	Posicao getPosicao(int linha, int coluna);

};

#endif /* TABULEIRO_H_ */
