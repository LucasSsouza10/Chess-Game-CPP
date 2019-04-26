
#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include "Posicao.h";
#include "Peca.h";

class Tabuleiro {
private:
	Posicao **pos;

public:
	Tabuleiro(Peca *p1, Peca *p2);	//responsavel pela configuração inicial do tabuleiro
	bool movimenta(Posicao origem, Posicao destino); // responsavel pela manutenção e checagem do tabuleiro a cada jogada
	void desenharTabuleiro(); //desenha o tabuleiro na tela
	Posicao getPosicao(int linha, int coluna);

};

#endif /* TABULEIRO_H_ */
