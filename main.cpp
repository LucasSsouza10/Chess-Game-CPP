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

	//Teste exaustivo do cavalo
	//primeiro IF -- Descer Duas linhas
	Cavalo c2('B');
	// Virando a esquerda
	cout << "primeiro IF -- Descer Duas linhas -- Virando a esquerda" << endl;
	origem.setLinha(4);
	origem.setColuna(4);
	destino.setLinha(2);
	destino.setColuna(3);
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	destino.setColuna(2);
	cout << "primeiro IF -- Descer Duas linhas -- Virando a esquerda duas casas  " << endl;
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	cout << "primeiro IF -- Descer Duas linhas -- Virando a direita  " << endl;
	destino.setColuna(5);
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	cout << "primeiro IF -- Descer Duas linhas -- Virando a duas casas direita  " << endl;
	destino.setColuna(6);
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	destino.setLinha(6);
	destino.setColuna(3);
	cout << "subir 2 linhas e virar a esquerda" << endl;
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	destino.setColuna(5);
	cout << "subir 2 linhas e virar a direita" << endl;
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	destino.setLinha(5);
	destino.setColuna(2);
	cout << "andar duas casas a esquerda e subir uma casa" << endl;
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	destino.setColuna(6);
	cout << "andar duas casas a direita e subir uma casa" << endl;
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	destino.setLinha(3);
	destino.setColuna(2);
	cout << "andar duas casas a direita e descer uma casa" << endl;
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;
	destino.setColuna(6);
	cout << "andar duas casas a esquerda e descer uma casa" << endl;
	cout << "movimento valido? " << c2.checaMovimento(origem, destino) << endl;

	Dama d2('P');
	origem.setLinha(4);
	origem.setColuna(4);
	destino.setLinha(6);
	destino.setColuna(4);
	cout << "Dama movendo-se na vertical" << endl;
	cout << "movimento valido? " << d2.checaMovimento(origem, destino) << endl;
	destino.setColuna(6);
	cout << "Dama movendo-se na diagonal" << endl;
	cout << "movimento valido? " << d2.checaMovimento(origem, destino) << endl;
	destino.setLinha(4);
	cout << "Dama movendo-se na Horizontal" << endl;
	cout << "movimento valido? " << d2.checaMovimento(origem, destino) << endl;

	Rei r2('B');
	origem.setLinha(4);
	origem.setColuna(4);
	destino.setLinha(4);
	destino.setColuna(5);
	cout << "Rei movendo-se na Horizontal" << endl;
	cout << "movimento valido? " << r2.checaMovimento(origem, destino) << endl;

	Torre t2('P');
	origem.setLinha(4);
	origem.setColuna(4);
	destino.setLinha(4);
	destino.setColuna(8);
	cout << "Torre movendo-se na Horizontal" << endl;
	cout << "movimento valido? " << t2.checaMovimento(origem, destino) << endl;
	destino.setLinha(4);
	cout << "Torre movendo-se na Vertical" << endl;
	cout << "movimento valido? " << t2.checaMovimento(origem, destino) << endl;

	Peao p2('P');
	origem.setLinha(7);
	origem.setColuna(2);
	destino.setLinha(5);
	destino.setColuna(2);
	cout <<"Peao preto na posicao inicial movendo-se  duas linhas" << endl;
	cout << "movimento valido? " << p2.checaMovimento(origem, destino) << endl;
	destino.setLinha(6);
	cout <<"Peao preto na posicao inicial movendo-se  uma linha" << endl;
	cout << "movimento valido? " << p2.checaMovimento(origem, destino) << endl;
	cout <<"Peao preto tentando mover-se para tras" << endl;
	destino.setLinha(8);
	cout << "movimento valido? " << p2.checaMovimento(origem, destino) << endl;

	Peao p3('B');
	origem.setLinha(2);
	origem.setColuna(2);
	destino.setLinha(4);
	destino.setColuna(2);
	cout << "Peao branco na posicao inicial movendo-se  duas linhas" << endl;
	cout << "movimento valido? " << p3.checaMovimento(origem, destino) << endl;
	destino.setLinha(3);
	cout << "movimento valido? " << p3.checaMovimento(origem, destino) << endl;
	cout << "Peao branco na posicao inicial movendo-se  uma linha" << endl;
	cout << "movimento valido? " << p3.checaMovimento(origem, destino) << endl;
	cout <<"Peao branco tentando mover-se para tras" << endl;
	destino.setLinha(1);
	cout << "movimento valido? " << p2.checaMovimento(origem, destino) << endl;


}

