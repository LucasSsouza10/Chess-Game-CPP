
#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include "Posicao.h";

class Tabuleiro {
private:
	Posicao pos[8][8];
public:
	Tabuleiro();	//responsavel pela configuração inicial do tabuleiro
	void movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); // responsavel pela manutenção e checagem do tabuleiro a cada jogada
	void desenharTabuleiro(); //desenha o tabuleiro na tela

};

#endif /* TABULEIRO_H_ */
