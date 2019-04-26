#include <iostream>
#include "Jogo.h"

using namespace std;

int main(){
	//Teste 1 Criação de jogo e seus componetes(tabuleiro, peca, posicao) com construtor padrão
	cout<< "Inicio teste 1"<<endl;
	Jogo jogo;
	cout<< "Terminou construção" <<endl;
	jogo.desenharTabuleiro();
	cout<< "Fim da teste 1"<<endl;
	//Fim do teste 1

	//Teste 2 Criação de jogo e seus componetes(tabuleiro, peca, posicao) com construtor com parametros
	cout<< "Inicio teste 2"<<endl;
	Jogo jogo1("Rafael", "Andre");
	cout<< "Terminou construção do Jogo com nomes" <<endl;
	jogo1.desenharTabuleiro();
	cout<<"Nome Jogador1: "<<jogo1.getJogador1().getNome() << endl;
	cout<<"Nome Jogador2: "<<jogo1.getJogador2().getNome() << endl;
	cout<< "Fim da teste 2"<<endl;
	//Fim do teste 2


	//Teste 3 Movimento no tabuleiro
	cout<< "Inicio teste 2"<<endl;
	jogo.desenharTabuleiro();
	jogo.movimenta(1, 0, 2, 0);
	jogo.desenharTabuleiro();
	cout<< "Fim da teste 2"<<endl;
	//Fim do teste 3
}

