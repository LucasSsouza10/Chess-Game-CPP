#include "Peca.h"

Peca::Peca(){
	cor = 'N';
	situacao = "Em jogo";
}

Peca::Peca(char c){
	cor = c;
	situacao = "Em jogo";
}

char Peca::getCor(){
	return cor;
}
