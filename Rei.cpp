#include "Rei.h"

Rei::Rei(char c) : Peca(c)
{

}

bool Rei::checaMovimento(Posicao origem, Posicao destino)
{


	//o rei pode se mover pra qualquer direcao somente uma posicao.
if (destino.getColuna()== origem.getColuna() + 1 || destino.getLinha() == origem.getLinha() +1)
	if(destino.getCor() != cor /*&& !(destino.isControlada)*/) // se a peca for de cor diferente e o local nao estiver ameacado.
		return true;
	else
		return false;
else
	return false;
}

char Rei::desenha()
{
	if(cor == 'B')
		return 'R';
	else
		return 'r';
}

