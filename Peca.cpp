#include "Peca.h"


Peca::Peca(char c){
	cor = c;
	situacao = "Em jogo";
}

Peca::~Peca()
{

}
char Peca::getCor(){
	return cor;
}

bool Peca::checaMovimento(Posicao origem, Posicao destino){

}

char Peca::desenha(){

}

