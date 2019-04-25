/*
 * Tabuleiro.cpp
 *
 *  Created on: 15 de abr de 2019
 *      Author: lucca
 */

#include "Tabuleiro.h"
Tabuleiro::Tabuleiro(Peca *p1, Peca *p2)
{
	int aux=0;// auxiliar na hora de preencher as posicoess
//0 a 7 primeira fila
//8 a 15 segunda fila
	for(int i=0;i<2;i++) //linha
	{
		if(i==1)
			aux=7;
		for (int j=0;j<8;j++)
			pos[i][j].setPca(p1[j+aux]) // a intencao aqui e passar o endereco de uma peca vindo do conjunto do jogo;

	}
	for(int i=2;i<6;i++) //linha
		{
			for (int j=0;j<8;j++)
				pos[i][j].setPca(NULL) // a intencao aqui e passar o endereco de uma peca vindo do conjunto do jogo;

		}

	for(int i=6;i<8;i++) //linha
		{
			if(i==7)
				aux=7;
			for (int j=0;j<8;j++)
				pos[i][j].setPca(p2[j+aux]) // a intencao aqui e passar o endereco de uma peca vindo do conjunto do jogo;

		}
}
