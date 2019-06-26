#include "Cavalo.h"

Cavalo::Cavalo(char c) : Peca(c)
{

}

bool Cavalo::checaMovimento(Posicao origem, Posicao destino)
{
	if (destino.getColuna() - origem.getColuna() == 2) //Desceu duas linhas
	{
		if (origem.getLinha() + 1 == destino.getLinha() )
			//Uma coluna � esquerda; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
			return true;
		else if (origem.getLinha() - 1 == destino.getLinha() )
			//Uma coluna � direita; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
			return true;
	}
	else if (destino.getColuna() - origem.getColuna() == -2) ///Subiu duas linhas
	{
		if (origem.getLinha() + 1 == destino.getLinha())
			//Uma coluna � esquerda; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
			return true;
		else if (origem.getLinha() - 1 == destino.getLinha())
			//Uma coluna � direita; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
			return true;
	}

	else if (destino.getLinha() - origem.getLinha() == 2) // andou a direita duas colunas
		{
			if (origem.getColuna() + 1 == destino.getColuna() )
				//Uma coluna � esquerda; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
				return true;
			else if (origem.getColuna() - 1 == destino.getColuna() )
				//Uma coluna � direita; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
				return true;
		}
		else if (destino.getLinha() - origem.getLinha() == -2) // deslocou se a esquerda duas linhas
		{
			if (origem.getColuna() + 1 == destino.getColuna())
				//Uma coluna � esquerda; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
				return true;
			else if (origem.getColuna() - 1 == destino.getColuna())
				//Uma coluna � direita; movimento permitido de posi��o estiver livre ou se houver uma peca inimiga
				return true;
		}


	return false;
}

char Cavalo::desenha()
{

		if(cor == 'B')
			return 'C';
		else
			return 'c';
}

Cavalo::Cavalo(Cavalo const &p) : Peca(p) {

}

Cavalo* Cavalo::clone() const {
	return new Cavalo(*this);
}

