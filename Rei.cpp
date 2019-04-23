/*
 * Rei.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: Will
 */

#include "Rei.h"

Rei::Rei()
{
	// TODO Auto-generated constructor stub

}

Rei::~Rei()
{
	// TODO Auto-generated destructor stub
}
bool Rei::checaMovimento(Posicao origem, Posicao destino)
{


	//o rei pode se mover pra qualquer lugar.
if (destino.getColuna()== origem.getColuna() + 1 || destino.getLinha() == origem.getLinha() +1)
	if(destino.getCor() != cor && !(destino.isControlada)) // se a peca for de cor diferente e o local nao estiver ameacado.
		return true;
	else
		return false;

}



