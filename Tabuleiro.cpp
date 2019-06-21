#include "Tabuleiro.h"
#include "math.h"

using namespace std;

//Construtor que recebe vetor de peças
Tabuleiro::Tabuleiro(Peca **p) // @suppress("Class members should be properly initialized")
		{
	//construindo matriz de posicao
	pos = new Posicao*[8];

	for (int i = 0; i < 8; ++i) {
		pos[i] = new Posicao[8];
	}

	//setando Pecas nas posicoes do tabuleiro
	for (int i = 0; i < 16; ++i) {
		if (i < 8) {
			pos[0][i].setPca(p[i]);
			pos[7][i].setPca(p[i + 16]);
		} else {
			pos[1][i - 8].setPca(p[i]);
			pos[6][i - 8].setPca(p[i + 16]);
		}
	}

	//Setando linha, coluna e cor da posicao
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			pos[i][j].setLinha(i + 1);
			pos[i][j].setColuna(j + 1);
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
				pos[i][j].setCor('B');
			else
				pos[i][j].setCor('P');
		}
	}
}

//Desenha o tabuleiro na tela
void Tabuleiro::desenharTabuleiro() {
	cout << "     A     B     C     D     E     F     G     H   " << endl;
	for (int i = 7; i >= 0; --i) {
		cout << "   #################################################" << endl;
		cout << "   #     #     #     #     #     #     #     #     #" << endl;

		cout << " " << i + 1 << " ";
		for (int j = 0; j < 8; ++j) {
			if (pos[i][j].isOcupada()) {
				cout << "#  " << (pos[i][j].getPca())->desenha() << "  ";
			} else {
				cout << "#     ";
			}
		}
		cout << "#" << endl;
		cout << "   #     #     #     #     #     #     #     #     #" << endl;
	}
	cout << "   #################################################" << endl;
}

//Faz o movimento da peça
bool Tabuleiro::movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, char cor) {
    if (pos[linhaOrigem][colunaOrigem].getPca()->getCor() != cor) //Peça não pertence ao jogador
        return false;
	bool mov = pos[linhaOrigem][colunaOrigem].getPca()->checaMovimento(pos[linhaOrigem][colunaOrigem], pos[linhaDestino][colunaDestino]); //Verifica se o movimento é valido
	cout << mov << endl;
	if (mov) { //movimento valido
		cout << "Checou o movimento" << endl;
		if (!(pos[linhaDestino][colunaDestino].isOcupada()))

		{ // se o lugar nao estiver ocupado
			if (checaCaminho(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) { // checa as casas do movimento
				pos[linhaDestino][colunaDestino].setPca(pos[linhaOrigem][colunaOrigem].getPca()); //Coloca a peça no lugar de destino
				pos[linhaOrigem][colunaOrigem].setPca(NULL); //Seta a posição origem como vaga
				return true;
			} else
				return false;
		}
		else { //Lugar ocupado
			if ((pos[linhaDestino][colunaDestino].getPca())->getCor() == (pos[linhaOrigem][colunaOrigem].getPca())->getCor()) // esta ocupado com peca de mesma cor;
				return false;
			else if (checaCaminho(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)){//está ocupado com peça de outra cor
                captura(linhaDestino, colunaDestino, linhaOrigem, colunaOrigem);
				return true;
			}
		}
	} else {
        return false;
	}

}

//Verifica se existe alguma peça nas posições entre a origem e o destino
bool Tabuleiro::checaCaminho(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
	int aux = 0;

	char tipoPeca = pos[linhaOrigem][colunaOrigem].getPca()->desenha();

    //REI
	if (tipoPeca == 'R' || tipoPeca == 'r' || tipoPeca == 'C' || tipoPeca == 'c') { //Pe�as que nao precisam de verificacao pois ou so pulam uma casa ou podem passar por cima de outras pecas
		cout << "entro em chegaCasa Rei ou Cavalo" << endl;
		return true;
	} else {
		//PEAO
		if (tipoPeca == 'P' || tipoPeca == 'p') {
			if ((linhaDestino - linhaOrigem) > 0) // Movendo Peao do Jogador 1
            {
				//cout << "entro em checa casa Peao > 0" << endl;
				//cout << "condicao : "
				//		<< pos[linhaOrigem + 1][colunaOrigem].isOcupada()
				//		<< endl;
				//cout << "linha e linha " << pDestino.getLinha() << " " << pOrigem.getLinha() << " " << endl;

				if ((pos[linhaOrigem + 1][colunaOrigem].isOcupada())) {
                    return false;
				}
				else {
					return true;
				}

			} else // movendo Peao do jogador 2
			{
				if (pos[linhaOrigem - 1][colunaOrigem].isOcupada()) {
                    return false;
				}
				else {
					return true;
				}
			}
		}
		//TORRE
		else if (tipoPeca == 'T' || tipoPeca == 't') {
			if (linhaOrigem == linhaDestino)
				if (colunaDestino > colunaOrigem) { //movendo-se para a direita
					aux = 1;
					while (colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
						//cout << "False, Coluna 1" << endl;
					}
					return true;
				} else { //movendo-se para a esquerda
					aux=1;
					while (colunaOrigem - (aux) != colunaDestino) {
						if (pos[linhaOrigem][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
						//cout << "False, Coluna 2" << endl;
					}
					return true;
				}
			else if (linhaDestino > linhaOrigem) { //movendo-se de baixo para cima
				aux = 1;
				while (linhaOrigem + aux != linhaDestino) {
					if (pos[linhaOrigem + aux][colunaOrigem].isOcupada())
						return false;
					aux++;
				}
				return true;
			} else { //movendo-se de baixo para cima
				aux=1;
				while (linhaOrigem - aux != linhaDestino) {
					if (pos[linhaOrigem - aux][colunaOrigem].isOcupada())
						return false;
					aux++;
				}
				return true;

			}

		}
		//Bispo
		else if (tipoPeca == 'B' || tipoPeca == 'b') {
			if (linhaDestino > linhaOrigem) {
				if (colunaDestino > colunaOrigem) {
					aux = 1;
					while (linhaOrigem + aux != linhaDestino && colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem + aux][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
					}
					return true;

				} else {
					aux = 1;
					while (linhaOrigem + aux != linhaDestino && colunaOrigem - aux != colunaDestino) {
						if (pos[linhaOrigem + aux][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
					}
					return true;

				}

			} else {
				if (colunaDestino > colunaOrigem) {
					aux = 1;
					while (linhaOrigem - aux != linhaDestino && colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem - aux][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
					}
					return true;

				} else {
					aux = 1;
					while (linhaOrigem - aux != linhaDestino
							&& colunaOrigem - aux != colunaDestino) {
						if (pos[linhaOrigem - aux][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
					}
					return true;

				}

			}

		} //fim bispo

        //DAMA
		else if (tipoPeca == 'D' || tipoPeca == 'd') {
			if (linhaOrigem == linhaDestino) {
				if (colunaDestino > colunaOrigem) { //movendo-se para a direita
					aux = 1;
					while (colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
						//cout << "False, Coluna 1" << endl;
					} //fim while
					return true;

				} else { //movendo-se para a esquerda
					aux=1;
					while (colunaOrigem - (aux) != colunaDestino) {
						if (pos[linhaOrigem][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
						//cout << "False, Coluna 2" << endl;
					} //fim while
					return true;
				}
			} //fim movimento na horizontal
			if (colunaDestino == colunaOrigem) { // Movimento Vertical
				if (linhaDestino > linhaOrigem) { //movendo-se de baixo para cima
					aux = 1;
					while (linhaOrigem + aux != linhaDestino) {
						if (pos[linhaOrigem + aux][colunaOrigem].isOcupada())
							return false;
						aux++;
					} //fim while
					return true;
				} else { //movendo-se de baixo para cima
					aux=1;
					while (linhaOrigem - aux != linhaDestino) {
						if (pos[linhaOrigem - aux][colunaOrigem].isOcupada())
							return false;
						aux++;
					} //fim while
					return true;

				}

			} //fim movimento na vertical
			if (linhaDestino > linhaOrigem) { // movimento Diagonal SUperior
				if (colunaDestino > colunaOrigem) { // Diagonal Superior Direita
					aux = 1;
					while (linhaOrigem + aux != linhaDestino
							&& colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem + aux][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
					} // fim while
					return true;

				} else { // Diagonal Superior esquerda
					aux = 1;
					while (linhaOrigem + aux != linhaDestino
							&& colunaOrigem - aux != colunaDestino) {
						if (pos[linhaOrigem + aux][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
					} //fim while
					return true;

				}

			} //Fim movimento diagonal Superior
			else { //inicio movimento diagonal Inferior
				if (colunaDestino > colunaOrigem) { // Diagonal inferior Direita
					aux = 1;
					while (linhaOrigem - aux != linhaDestino
							&& colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem - aux][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
					} //fim while
					return true;

				} else { // Diagonal inferior esquerda
					aux = 1;
					while (linhaOrigem - aux != linhaDestino
							&& colunaOrigem - aux != colunaDestino) {
						if (pos[linhaOrigem - aux][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
					} //fim while
					return true;

				} //fim else Diagonal Inferior esquerda
			} //fim else Diagonal Inferior Direita

		} // Fim do do Else da Dama
	} //fim do else entre Rei e Cavalo
return false;
} // fim da funçao

bool Tabuleiro::captura(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    Peca *capturada = pos[linhaDestino][colunaDestino].getPca();
    //strcpy(capturada->situacao, "capturada"); //situacao é protected!
    pos[linhaDestino][colunaDestino].setPca(pos[linhaOrigem][colunaOrigem].getPca()); //Coloca a peça no lugar de destino
	pos[linhaOrigem][colunaOrigem].setPca(NULL); //Seta a posição origem como vaga

    return true;
}
