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
	bool checaRisco(Posicao*, Posicao*); //Verifica se o rei está em xeque
public:
	Tabuleiro(Peca **p);	//responsavel pela configuração inicial do tabuleiro
	bool movimenta(int, int, int, int, char); //responsável pela movimentação das peças
    int colunaDestino; // responsavel pela manutenção e checagem do tabuleiro a cada jogada
	void desenharTabuleiro(std::string, std::string); //desenha o tabuleiro na tela
	Posicao getPosicao(int linha, int coluna);
	int verificaEstado(char); //Retorna se o rei está em xeque ou xeque-mate
};

#endif /* TABULEIRO_H_ */
