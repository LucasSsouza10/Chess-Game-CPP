
#ifndef JOGO_H_
#define JOGO_H_

#include "Tabuleiro.h"
#include "Jogador.h"
#include "Peca.h"

class Jogo {
private:
	Tabuleiro tab;
	Jogador j1, j2;
	Peca p[24];
	int estado; //0 = inicio do jogo; 1 = xeque; 2 = xeque-mate
	int vez; //0 = jogador 1; 1 = jogador 2
public:
	Jogo(); //Construtor padr�o
	~Jogo(); //Destrutor

};

#endif /* JOGO_H_ */
