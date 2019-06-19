#include "Posicao.h"
#include "Peao.h"
#include "Torre.h"

using namespace std;

Posicao::Posicao(){
	pca = NULL;
	ocupada = false;
}

int Posicao::getLinha(){
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

Peca *Posicao::getPca(){
	return pca;
}

void Posicao::setPca(Peca *p){
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
void Posicao::setColuna(int c){
	if(c <= 8 && c >= 1)
		coluna = c;
}
void Posicao::setLinha(int l){
	if(l <= 8 && l >= 1)
		linha = l;

}

