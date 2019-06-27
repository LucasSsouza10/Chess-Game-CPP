#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include "Posicao.h"
#include "Peca.h"
#include "string.h"

class Tabuleiro {
private:
	Posicao **pos;
	bool checaCaminho(int, int, int, int);
	void captura(int, int); //Altera o estado da peça quando ela é capturada
	Posicao* procuraRei(char); //Busca pela posição do rei no tabuleiro
	bool checaRisco(Posicao, Posicao); //Verifica se o rei está em xeque
	int verificaEstado(Posicao); //verifica se a peça na posicao passada está em xeque ou xeque-mate
public:
	Tabuleiro(Peca **p);	//responsavel pela configuração inicial do tabuleiro
	bool movimenta(int, int, int, int, char); //responsável pela movimentação das peças
	void desenharTabuleiro(std::string, std::string); //desenha o tabuleiro na tela
	Posicao getPosicao(int linha, int coluna);
	int checaRei(char r); //Retorna se o rei está em xeque ou xeque-mate
	bool verificaMovimento(int, int, int, int); //verifica se movimento deixa jogo em cheque
};

#endif /* TABULEIRO_H_ */
