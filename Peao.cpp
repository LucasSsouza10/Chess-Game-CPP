#include "Peao.h"
using namespace std;

Peao::Peao(char c) : Peca(c){

}

bool Peao::checaMovimento(Posicao origem, Posicao destino){
	if((cor == 'B' && origem.getLinha() > destino.getLinha()) ||
		(cor == 'P' && origem.getLinha() < destino.getLinha()))
	{
		return false;  // peao não pode movimentar para tras
	}

	if( origem.getColuna() != destino.getColuna() )
	{
	// peao não pode movimentar horizontalmente
	//  a menos que ira capturar uma peca inimiga
		if( origem.getColuna() == destino.getColuna() + 1 || origem.getColuna() == destino.getColuna() + 1)
		{
		// para capturar a peca inimiga presisa estar lá
			if(destino.isOcupada() && destino.getPca()->getCor() != cor)
				return true;
			else
				return false;
		}
	}

	//peao pode movimentar apenas uma casa por vez
	if(origem.getLinha() - destino.getLinha() != 1  && origem.getLinha()  - destino.getLinha() != -1){
		//a não ser que seja seu primeiro movimento
		if((origem.getLinha() == 2 && cor == 'B') || (origem.getLinha() == 7 && cor == 'P'))
			return true;
		else
			return false;
	}

	return true;
}

char Peao::desenha()
{
		if(cor == 'B')
			return 'P';
		else
			return 'p';

}
