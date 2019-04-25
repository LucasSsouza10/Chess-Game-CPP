#include "Bispo.h"


Bispo::Bispo(char c) : Peca(c)
{

}

bool Bispo::checaMovimento(Posicao origem, Posicao destino)
{
	if (destino.getLinha - origem.getLinha == destino.getColuna - origem.getColuna)
		return true;
	else
		return false;
}

char Bispo::desenha()
{
	if(cor == "B")
		return "B";
	else
		return "b";
}





