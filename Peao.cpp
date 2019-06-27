#include "Peao.h"
#include <math.h>
using namespace std;

//Construtor com cor pré-definida
Peao::Peao(char c) : Peca(c){

}

//Verifica o movimento de cada peça
bool Peao::checaMovimento(Posicao origem, Posicao destino){
	if((cor == 'B' && origem.getLinha() > destino.getLinha()) ||
		(cor == 'P' && origem.getLinha() < destino.getLinha()))
	{
		return false;  // peao não pode movimentar para tras
	}
	// peao não pode movimentar horizontalmente
	//  a menos que ira capturar uma peca inimiga
	if( origem.getColuna() != destino.getColuna() )
	{
		if(((origem.getLinha() == destino.getLinha() + 1 && cor == 'P') || (origem.getLinha() == destino.getLinha() - 1 && cor == 'B')) && (origem.getColuna() == destino.getColuna() + 1 || origem.getColuna() == destino.getColuna() - 1))
		{
		// para capturar a peca inimiga presisa estar lá
			if(destino.isOcupada() && destino.getPca()->getCor() != cor) {
				return true;
			}
			else
				return false;
		}
	}

	//peao pode movimentar apenas uma casa por vez
	if(origem.getLinha() - destino.getLinha() != 1  && origem.getLinha()  - destino.getLinha() != -1){
		//a não ser que seja seu primeiro movimento
		if((origem.getLinha() == 2 && cor == 'B') || (origem.getLinha() == 7 && cor == 'P'))
            //no primeiro movimento, pode mover até duas casas
            if(abs(origem.getLinha() - destino.getLinha()) <= 2 && origem.getColuna() == destino.getColuna() && !destino.isOcupada())
                return true;
            else
                return false;
		else
			return false;
	}else{
		if(origem.getColuna() == destino.getColuna() && !destino.isOcupada())
			return true;
	}
	return false;
}

//Retorna a inicial da peça a ser desenhada no tabuleiro
char Peao::desenha()
{
		if(cor == 'B')
			return 'P';
		else
			return 'p';

}
//construtor de copia
Peao::Peao(Peao const &p) : Peca(p) {

}

Peao* Peao::clone() const {
	return new Peao(*this);
}

