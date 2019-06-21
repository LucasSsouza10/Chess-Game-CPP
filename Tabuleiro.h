#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include "Posicao.h"
#include "Peca.h"
#include "string.h"

class Tabuleiro {
private:
	Posicao **pos;
	bool checaCaminho(int, int, int, int);
	void captura(int, int);

public:
	Tabuleiro(Peca **p);	//responsavel pela configuração inicial do tabuleiro
	bool movimenta(int, int, int, int, char); //responsável pela movimentação das peças
    int colunaDestino; // responsavel pela manutenção e checagem do tabuleiro a cada jogada
	void desenharTabuleiro(); //desenha o tabuleiro na tela
	Posicao getPosicao(int linha, int coluna);

};

#endif /* TABULEIRO_H_ */
