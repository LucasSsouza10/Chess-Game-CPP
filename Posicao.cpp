#include "Posicao.h"
#include "Peao.h"
#include "Torre.h"

Posicao::Posicao(){
	linha = 0;
	coluna = 'N';
	cor = 'N';
	pca = NULL;
	ocupada = false;
}

char Posicao::getLinha(){
	return linha;
}

int Posicao::getColuna(){
	return coluna;
}

bool Posicao::isOcupada() {
	return ocupada;
}

char Posicao::getCor()
{
	return cor;
}

Peca Posicao::getPca(){
	return pca;
}

void Posicao::setPca(Peca p){
	pca = p;

	if(p != NULL)
		ocupada = true;
	else
		ocupada = false;

}

void Posicao::setCor(char c){
	if(c == 'B' || c == 'P')
	cor = c;
}
void Posicao::setColuna(char c){
	if(c <= 'H' && c >= 'A')
		coluna = c;
}
void Posicao::setLinha(int l){
	if(l <= 8 && l >= 1)
		linha = l;

}

