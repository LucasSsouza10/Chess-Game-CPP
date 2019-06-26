#include "Bispo.h"
#include <math.h>

Bispo::Bispo(char c) : Peca(c)
{

}

bool Bispo::checaMovimento(Posicao origem, Posicao destino)
{
	if (abs(destino.getLinha() - origem.getLinha()) == abs(destino.getColuna() - origem.getColuna()))
		return true;
	else
		return false;
}

char Bispo::desenha()
{
	if(cor == 'B')
		return 'B';
	else
		return 'b';
}

//construtor de copia
Bispo::Bispo(const Bispo &p) : Peca(p.cor) {

}




