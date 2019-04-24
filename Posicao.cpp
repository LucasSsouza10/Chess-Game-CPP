#include "Posicao.h"
#include "Peao.h"
#include "Torre.h"

Posicao::Posicao(char col, int lin, char c){
	coluna = col;
	linha = lin;
	cor = c;
	if(lin == 2 || lin == 7)
		pca = new Peao(c);
	else if((lin == 1 && col == 'A') || (lin = 8 && col == 'H'))
		pca = new Torre(c);
}

char Posicao::getLinha(){
	return linha;
}

int Posicao::getColuna(){
	return coluna;
}

bool Posicao::isOcupada() {
	if (pca)
		return true;
	else
		return false;
}

char Posicao::getCor()
{
	return cor;
}


