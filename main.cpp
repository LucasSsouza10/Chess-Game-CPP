#include <iostream>
#include "Jogo.h"
#include "Posicao.h"
#include "Dama.h"
#include "Torre.h"
#include "Rei.h"
#include "Cavalo.h"
#include "Bispo.h"

using namespace std;

int main() {
	//Teste 1 Criação de jogo e seus componetes(tabuleiro, peca, posicao) com construtor padrão
	cout << "Inicio teste 1" << endl;
	Jogo jogo;
	cout << "Terminou construção" << endl;
	jogo.desenharTabuleiro();
	cout << "Fim da teste 1" << endl;
	//Fim do teste 1

	//Teste 2 Criação de jogo e seus componetes(tabuleiro, peca, posicao) com construtor com parametros
	cout << "Inicio teste 2" << endl;
	Jogo jogo1("Rafael", "Andre");
	cout << "Terminou construção do Jogo com nomes" << endl;
	jogo1.desenharTabuleiro();
	cout << "Nome Jogador1: " << jogo1.getJogador1().getNome() << endl;
	cout << "Nome Jogador2: " << jogo1.getJogador2().getNome() << endl;
	cout << "Fim da teste 2" << endl;
	//Fim do teste 2

	//Teste 3 Movimento no tabuleiro Peao
	cout << "Inicio teste 3" << endl;
	jogo.desenharTabuleiro();
	jogo.movimenta(1, 0, 2, 0);
	jogo.desenharTabuleiro();
	cout << "Fim da teste 3" << endl;
	//Fim do teste 3

	Posicao origem, destino;
	//Teste 4 Checagem Movimento da Torre
	cout << "Inicio teste 4" << endl;

	origem.setLinha(1);
	origem.setColuna(1);
	destino.setLinha(8);
	destino.setColuna(1);
	Torre t1('B');

	cout << "movimento valido? " << t1.checaMovimento(origem, destino) << endl;
	destino.setColuna(2);
	cout << "movimento valido? " << t1.checaMovimento(origem, destino) << endl;

	//Teste 5 Checagem Movimento do Cavalo
	cout << "Inicio teste 5" << endl;

	origem.setLinha(2);
	origem.setColuna(1);
	destino.setLinha(3);
	destino.setColuna(3);
	Cavalo c1('B');

	cout << "movimento valido? " << c1.checaMovimento(origem, destino) << endl;
	destino.setColuna(5);
	cout << "movimento valido? " << c1.checaMovimento(origem, destino) << endl;

	//Teste 6 Checagem Movimento do Bispo
	cout << "Inicio teste 6" << endl;

	origem.setLinha(4);
	origem.setColuna(4);
	destino.setLinha(1);
	destino.setColuna(1);
	Bispo b1('P');
	cout << "movimento valido? " << b1.checaMovimento(origem, destino) << endl;
	destino.setColuna(5);
	cout << "movimento valido? " << b1.checaMovimento(origem, destino) << endl;

	//Teste 7 Checagem Movimento Rainha
	cout << "Inicio teste 7" << endl;

	origem.setLinha(4);
	origem.setColuna(4);
	destino.setLinha(1);
	destino.setColuna(1);
	Dama d1('P');
	cout << "movimento valido? " << d1.checaMovimento(origem, destino) << endl;
	destino.setLinha(3);
	destino.setColuna(2);
	cout << "movimento valido? " << d1.checaMovimento(origem, destino) << endl;

	//Teste 7 Checagem Movimento Rei
	cout << "Inicio teste 8" << endl;

	origem.setLinha(5);
	origem.setColuna(1);
	destino.setLinha(5);
	destino.setColuna(2);
	Dama r1('P');
	cout << "movimento valido? " << r1.checaMovimento(origem, destino) << endl;
	destino.setLinha(3);
	destino.setColuna(2);
	cout << "movimento valido? " << r1.checaMovimento(origem, destino) << endl;

}

