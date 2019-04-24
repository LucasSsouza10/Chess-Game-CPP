#include "Cavalo.h"

Cavalo::Cavalo(char c) : Peca(c)
{

}

bool Cavalo::checaMovimento(Posicao origem, Posicao destino)
{
	if (destino.getColuna() - origem.getColuna() == 2) //Desceu duas linhas
	{
		if (origem.getLinha() + 1 == destino.getLinha && !destino.isOcupada() && destino.getCor()!=cor)
			//Uma coluna � esquerda; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
			return true;
		else if (origem.getLinha() - 1 == destino.getLinha && !destino.isOcupada() && destino.getCor()!=cor)
			//Uma coluna � direita; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
			return true;
	}
	else if (destino.getColuna() - origem.getColuna == -2) ///Subiu duas linhas
	{
		if (origem.getLinha() + 1 == destino.getLinha && !destino.isOcupada() && destino.getCor()!=cor)
			//Uma coluna � esquerda; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
			return true;
		else if (origem.getLinha() - 1 == destino.getLinha && !destino.isOcupada() && destino.getCor()!=cor)
			//Uma coluna � direita; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
			return true;
	}
	return false;
}

void Cavalo::desenha()
{
}


