#include "Peca.h"

//Construtor com cor definida
Peca::Peca(char c){
	cor = c;
	situacao = "Em jogo";
}

//Destrutor
Peca::~Peca()
{

}

//Retorna a cor da peça
char Peca::getCor(){
	return cor;
}


//Checa o movimento de cada peça (implementada nas subclasses)
bool Peca::checaMovimento(Posicao origem, Posicao destino){

}

//Desenha cada peça no tabuleiro
char Peca::desenha(){

}

