#include "Tabuleiro.h"
#include "math.h"

using namespace std;

//Construtor que recebe vetor de peças
//Entrada: matriz de pecas p
Tabuleiro::Tabuleiro(Peca **p) { // @suppress("Class members should be properly initialized")
	//construindo matriz de posicao
	try {
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
	} catch (bad_alloc err) {
		cout << "Erro: " << err.what() << endl;

	}
}

//Desenha o tabuleiro na tela
//Entrada: nomes dos jogadores
void Tabuleiro::desenharTabuleiro(string detalhes1, string detalhes2) {
	cout << endl;
	cout
	        << "     A     B     C     D     E     F     G     H                        Peças Mortas"
	        << endl;
	for (int i = 7; i >= 0; --i) {
		if (i == 7) {
			cout
			        << "   #################################################                    "
			        << detalhes1 << endl;
			cout
			        << "   #     #     #     #     #     #     #     #     #                    "
			        << detalhes2 << endl;
		} else {
			cout << "   #################################################"
			     << endl;
			cout << "   #     #     #     #     #     #     #     #     #"
			     << endl;

		}

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
//Entrada: linhas de origem e destino, colunas de origem e destino e a cor do jogador
//Saida: true (movimento valido) ou false (movimento invalido)
bool Tabuleiro::movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino,
                          int colunaDestino, char cor) {

	if (!(pos[linhaOrigem][colunaOrigem].isOcupada()))
		throw 99;
	if (pos[linhaOrigem][colunaOrigem].getPca()->getCor() != cor) //Peça não pertence ao jogador
		return false;

	bool mov = pos[linhaOrigem][colunaOrigem].getPca()->checaMovimento(pos[linhaOrigem][colunaOrigem], pos[linhaDestino][colunaDestino]); //Verifica se o movimento é valido
	if (mov) { //movimento valido
		if (!(pos[linhaDestino][colunaDestino].isOcupada())) {
			// se o lugar nao estiver ocupado
			if (checaCaminho(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) { // checa as casas do movimento
				pos[linhaDestino][colunaDestino].setPca(pos[linhaOrigem][colunaOrigem].getPca()); //Coloca a peça no lugar de destino
				pos[linhaOrigem][colunaOrigem].setPca(NULL); //Seta a posição origem como vaga
				return true;
			} else
				return false;
		} else { //Lugar ocupado
			if ((pos[linhaDestino][colunaDestino].getPca())->getCor() == (pos[linhaOrigem][colunaOrigem].getPca())->getCor()) // esta ocupado com peca de mesma cor;
				return false;
			else if (checaCaminho(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) { //está ocupado com peça de outra cor
				captura(linhaDestino, colunaDestino);
				pos[linhaDestino][colunaDestino].setPca(pos[linhaOrigem][colunaOrigem].getPca());
				pos[linhaOrigem][colunaOrigem].setPca(NULL);
				return true;
			}
		}
	} else {
		return false;
	}
	return false;
}

//Verifica se existe alguma peça nas posições entre a origem e o destino
//Entrada: linhas de origem e destino, colunas de origem e destino
//Saida: true (caminho livre) ou false (existe peça no caminho)
bool Tabuleiro::checaCaminho(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
	int aux = 0;

	char tipoPeca = pos[linhaOrigem][colunaOrigem].getPca()->desenha();

	//REI
	if (tipoPeca == 'R' || tipoPeca == 'r' || tipoPeca == 'C' || tipoPeca == 'c') { //Pe�as que nao precisam de verificacao pois ou so pulam uma casa ou podem passar por cima de outras pecas
		return true;
	} else {
		//PEAO
		if (tipoPeca == 'P' || tipoPeca == 'p') {
			if (colunaOrigem != colunaDestino)
				return true;
			else if ((linhaDestino - linhaOrigem) > 0) { // Movendo Peao do Jogador 1

				if ((pos[linhaOrigem + 1][colunaOrigem].isOcupada())) {
					return false;
				} else {
					return true;
				}

			} else { // movendo Peao do jogador 2
				if (pos[linhaOrigem - 1][colunaOrigem].isOcupada()) {
					return false;
				} else {
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
					}
					return true;
				} else { //movendo-se para a esquerda
					aux = 1;
					while (colunaOrigem - (aux) != colunaDestino) {
						if (pos[linhaOrigem][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
					}
					return true;
				} else if (linhaDestino > linhaOrigem) { //movendo-se de baixo para cima
				aux = 1;
				while (linhaOrigem + aux != linhaDestino) {
					if (pos[linhaOrigem + aux][colunaOrigem].isOcupada())
						return false;
					aux++;
				}
				return true;
			} else { //movendo-se de baixo para cima
				aux = 1;
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
					while (linhaOrigem - aux != linhaDestino && colunaOrigem - aux != colunaDestino) {
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
					} //fim while
					return true;

				} else { //movendo-se para a esquerda
					aux = 1;
					while (colunaOrigem - (aux) != colunaDestino) {
						if (pos[linhaOrigem][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
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
					aux = 1;
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
					while (linhaOrigem + aux != linhaDestino && colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem + aux][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
					} // fim while
					return true;

				} else { // Diagonal Superior esquerda
					aux = 1;
					while (linhaOrigem + aux != linhaDestino && colunaOrigem - aux != colunaDestino) {
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
					while (linhaOrigem - aux != linhaDestino && colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem - aux][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
					} //fim while
					return true;

				} else { // Diagonal inferior esquerda
					aux = 1;
					while (linhaOrigem - aux != linhaDestino && colunaOrigem - aux != colunaDestino) {
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

//Altera o estado da peça quando ela é capturada
//Entrada: linha e coluna da peça capturada
void Tabuleiro::captura(int linha, int coluna) {
	Peca *capturada = pos[linha][coluna].getPca();
	capturada->setSituacao();
}

//Retorna se o rei está em xeque
//Entrada: posicao rei
//Saida: 0 = sem risco; 1 = xeque;
int Tabuleiro::verificaEstado(Posicao pos_rei) {
	int linha = pos_rei.getLinha() - 1;
	int coluna = pos_rei.getColuna() - 1;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (pos[i][j].isOcupada())
				if (checaRisco(pos_rei, pos[i][j])) { //se o rei estiver em risco ele esta em cheque
					return 1;
				}
		}
	}
	return 0;
}

//Busca pela posição do rei no tabuleiro
//Entrada: 'R' (jogador 1) ou 'r' (jogador 2)
//Saida: posicao onde o rei se encontra
Posicao* Tabuleiro::procuraRei(char r) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			Peca *p = (pos[i][j].getPca());
			if (p && (p->desenha()) == r)
				return &pos[i][j];
		}
	return NULL;
}

//Verifica o estado do jogo para o rei passado
int Tabuleiro::checaRei(char r) {
	Posicao *pos_rei = procuraRei(r);
	return verificaEstado(*pos_rei);
}

//Verifica se o rei está em xeque
//Entrada: pos_rei = posicao da peca rei; pos_adv: posicao do adversario
//Saída: true se o rei pode ser capturado, false se não
bool Tabuleiro::checaRisco(Posicao pos_rei, Posicao pos_adv) {

	try {
		Peca *adv = pos_adv.getPca();
		Peca *r = pos_rei.getPca();
//Verifica se existe adversario
		if (adv && adv->getCor() != r->getCor()) {
			//Verifica se a peça inimiga pode capturar o rei
			if (adv->checaMovimento(pos_adv, pos_rei) && checaCaminho(pos_adv.getLinha() - 1,
			        pos_adv.getColuna() - 1, pos_rei.getLinha() - 1,
			        pos_rei.getColuna() - 1)) { //Verifica se o movimento é permitido e válido
				return true; //A peça pode capturar o rei
			} else
				return false;
		} else
			return false;
	} catch (...) {
		cout << "Erro: acesso indevido!" << endl;
	}
	return false;
}

//verifica se movimento deixa jogo em cheque
//Entrada: linhas e colunas de origem e destino
//Saída: true se o movimento é permitido e false caso contrário
bool Tabuleiro::verificaMovimento(int origemLinha, int origemColuna, int destinoLinha, int destinoColuna) {
	bool v = true;
	Peca *destino = pos[destinoLinha][destinoColuna].getPca();

	Peca *origem = pos[origemLinha][origemColuna].getPca();

	pos[destinoLinha][destinoColuna].setPca(origem);

	pos[origemLinha][origemColuna].setPca(NULL);

	char rei;
	if (origem == NULL)
		throw 99;
	if (origem->getCor() == 'B')

		rei = 'B';

	else
		rei = 'r';

	if (checaRei(rei) == 0) {
		v = false;
	}

	pos[destinoLinha][destinoColuna].setPca(destino);
	pos[origemLinha][origemColuna].setPca(origem);
	return v;

}
