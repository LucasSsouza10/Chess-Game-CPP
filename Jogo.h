#ifndef JOGO_H_
#define JOGO_H_

#include "Tabuleiro.h"
#include "Jogador.h"
#include "Peca.h"
#include "Peao.h"
#include "Rei.h"
#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Torre.h"




class Jogo {
private:
	Tabuleiro *tab;
	Jogador *j1, *j2;
	Peca *p[32];
	int estado; //0 = inicio do jogo; 1 = xeque; 2 = xeque-mate
	int vez; //0 = jogador 1; 1 = jogador 2
	void criarPecas();
public:
	Jogo(); //Construtor padrão
	Jogo(std::string n1, std::string n2);
	~Jogo(); //Destrutor
	void setEstado(int);
	void setVez(int);
	void playGame();
	bool validarFormato(std::string);
	bool mover(std::string);
	void salvarEstado(std::string);
	void carregar();
	void limparSalvo();
};

#endif /* JOGO_H_ */
