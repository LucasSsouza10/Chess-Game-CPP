#include "Peca.h"

using namespace std;
//Construtor com cor definida
Peca::Peca(char c){
	cor = c;
	situacao = 1;
}

//Destrutor
Peca::~Peca()
{

}

//Retorna a cor da pe�a
char Peca::getCor(){
	return cor;
}


//Checa o movimento de cada pe�a (implementada nas subclasses)
bool Peca::checaMovimento(Posicao origem, Posicao destino){
}

//Desenha cada pe�a no tabuleiro
char Peca::desenha(){

}

int Peca::getSituacao(){
	return situacao;
}
//Troca situção para capturada
void Peca::setSituacao(){
	situacao = 0;


}

bool Peca::operator==(Peca &pecas)
{
	if(this->desenha()==pecas.desenha())
		return true;
	else return false;


}



