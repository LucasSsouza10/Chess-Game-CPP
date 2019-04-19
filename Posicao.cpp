
#include "Posicao.h"

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

}

int Posicao::getColuna(){

}
