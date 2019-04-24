#include "Peca.h"


Peca::Peca(char c){
	cor = c;
	situacao = "Em jogo";
}

char Peca::getCor(){
	return cor;
}
