
#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include "Posicao.h";
#include "Pe�a.h";

class Tabuleiro {
private:
	Posicao pos[8][8];
	Peca *j1;
	Peca *j2;

public:
	Tabuleiro(Peca *p1, Peca *p2);	//responsavel pela configuração inicial do tabuleiro
	void movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); // responsavel pela manutenção e checagem do tabuleiro a cada jogada
	void desenharTabuleiro(); //desenha o tabuleiro na tela
	static Posicao getPosicao(int linha, int coluna);

};

#endif /* TABULEIRO_H_ */
