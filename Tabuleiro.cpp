#include "Tabuleiro.h"

using namespace std;

Tabuleiro::Tabuleiro(Peca **p1, Peca **p2) // @suppress("Class members should be properly initialized")
{
	//construindo matriz de posicao
	pos = new Posicao*[8];

	for (int i = 0; i < 8; ++i) {
		pos[i] = new Posicao[8];
	}

	//setando Pecas nas posicoes do tabuleiro
	for (int i = 0; i < 16; ++i) {
		if(i < 8){
			pos[0][i].setPca(p1[i]);
			pos[7][i].setPca(p2[i]);
		}else{
			pos[1][i - 8].setPca(p1[i]);
			pos[6][i - 8].setPca(p2[i]);
		}
	}

	char conversor[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

	//Setando linha coluna e cor da posicao
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			pos[i][j].setLinha(i+1);
			pos[i][j].setColuna(conversor[j]);
			if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
				pos[i][j].setCor('B');
			else
				pos[i][j].setCor('P');
		}
	}
}

void Tabuleiro::desenharTabuleiro()
{
	cout<<"     A     B     C     D     E     F     G     H   "<<endl;
	for (int i = 7; i >= 0 ; --i) {
		cout<<"   #################################################"<<endl;
		cout<<"   #     #     #     #     #     #     #     #     #"<<endl;

		cout<<" " << i+1 << " ";
		for (int j = 0; j < 8; ++j) {
			if(pos[i][j].isOcupada()){
				cout<<"#  " << (pos[i][j].getPca())->desenha() << "  ";
			}else
				cout<<"#     ";
		}
		cout<<"#"<<endl;
		cout<<"   #     #     #     #     #     #     #     #     #"<<endl;
	}
	cout<<"   #################################################"<<endl;
}

bool Tabuleiro::movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
	if((pos[linhaOrigem][colunaOrigem].getPca())->checaMovimento(pos[linhaOrigem][colunaOrigem], pos[linhaDestino][colunaDestino])){ //movimento valido
		cout<< "Checou o movimento"<<endl;
		if(!(pos[linhaDestino][colunaDestino].isOcupada())){ // se o lugar nao estiver ocupado
			pos[linhaDestino][colunaDestino].setPca(pos[linhaOrigem][colunaOrigem].getPca());
			pos[linhaOrigem][colunaOrigem].setPca(NULL);
			return true;
		}
		else{
			if((pos[linhaDestino][colunaDestino].getPca())->getCor()==(pos[linhaOrigem][colunaOrigem].getPca())->getCor()) // esta ocupado com peca de mesma cor;
				return false;
			else
				return true;
		}
	} else
		return false;



}
