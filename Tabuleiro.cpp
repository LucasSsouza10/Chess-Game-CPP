#include "Tabuleiro.h"
#include "math.h"

using namespace std;

//Construtor que recebe vetor de peças
//Entrada: matriz de pecas p
Tabuleiro::Tabuleiro(Peca **p) { // @suppress("Class members should be properly initialized")
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
//Entrada: nomes dos jogadores
void Tabuleiro::desenharTabuleiro(string detalhes1, string detalhes2) {
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
	if (pos[linhaOrigem][colunaOrigem].getPca()->getCor() != cor) //Peça não pertence ao jogador
		return false;
	bool mov = pos[linhaOrigem][colunaOrigem].getPca()->checaMovimento(
			pos[linhaOrigem][colunaOrigem], pos[linhaDestino][colunaDestino]); //Verifica se o movimento é valido
	if (mov) { //movimento valido
		if (!(pos[linhaDestino][colunaDestino].isOcupada())) {
			// se o lugar nao estiver ocupado
			if (checaCaminho(linhaOrigem, colunaOrigem, linhaDestino,
					colunaDestino)) { // checa as casas do movimento
				pos[linhaDestino][colunaDestino].setPca(
						pos[linhaOrigem][colunaOrigem].getPca()); //Coloca a peça no lugar de destino
				pos[linhaOrigem][colunaOrigem].setPca(NULL); //Seta a posição origem como vaga
				return true;
			} else
				return false;
		} else { //Lugar ocupado
			if ((pos[linhaDestino][colunaDestino].getPca())->getCor()
					== (pos[linhaOrigem][colunaOrigem].getPca())->getCor()) // esta ocupado com peca de mesma cor;
				return false;
			else if (checaCaminho(linhaOrigem, colunaOrigem, linhaDestino,
					colunaDestino)) { //está ocupado com peça de outra cor
				captura(linhaDestino, colunaDestino);
				pos[linhaDestino][colunaDestino].setPca(
						pos[linhaOrigem][colunaOrigem].getPca());
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
bool Tabuleiro::checaCaminho(int linhaOrigem, int colunaOrigem,
		int linhaDestino, int colunaDestino) {
	int aux = 0;

	char tipoPeca = pos[linhaOrigem][colunaOrigem].getPca()->desenha();

	//REI
	if (tipoPeca == 'R' || tipoPeca == 'r' || tipoPeca == 'C'
			|| tipoPeca == 'c') { //Pe�as que nao precisam de verificacao pois ou so pulam uma casa ou podem passar por cima de outras pecas
		cout << "entro em chegaCasa Rei ou Cavalo" << endl;
		return true;
	} else {
		//PEAO
		if (tipoPeca == 'P' || tipoPeca == 'p') {
			if ((linhaDestino - linhaOrigem) > 0) { // Movendo Peao do Jogador 1
				//cout << "entro em checa casa Peao > 0" << endl;
				//cout << "condicao : "
				//		<< pos[linhaOrigem + 1][colunaOrigem].isOcupada()
				//		<< endl;
				//cout << "linha e linha " << pDestino.getLinha() << " " << pOrigem.getLinha() << " " << endl;

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
						//cout << "False, Coluna 1" << endl;
					}
					return true;
				} else { //movendo-se para a esquerda
					aux = 1;
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
					while (linhaOrigem + aux != linhaDestino
							&& colunaOrigem + aux != colunaDestino) {
						if (pos[linhaOrigem + aux][colunaOrigem + aux].isOcupada())
							return false;
						aux++;
					}
					return true;

				} else {
					aux = 1;
					while (linhaOrigem + aux != linhaDestino
							&& colunaOrigem - aux != colunaDestino) {
						if (pos[linhaOrigem + aux][colunaOrigem - aux].isOcupada())
							return false;
						aux++;
					}
					return true;

				}

			} else {
				if (colunaDestino > colunaOrigem) {
					aux = 1;
					while (linhaOrigem - aux != linhaDestino
							&& colunaOrigem + aux != colunaDestino) {
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
					aux = 1;
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

//Altera o estado da peça quando ela é capturada
//Entrada: linha e coluna da peça capturada
void Tabuleiro::captura(int linha, int coluna) {
	Peca *capturada = pos[linha][coluna].getPca();
	capturada->setSituacao();
}

//Retorna se o rei está em xeque ou xeque-mate
//Entrada: 'R' (jogador 1) ou 'r' (jogador 2)
//Saida: 0 = sem risco; 1 = xeque; 2 = xeque-mate
int Tabuleiro::verificaEstado(char r) {
	//Busca pela posicao do rei
	Posicao *pos_rei = procuraRei(r);
	int linha = pos_rei->getLinha() - 1;
	int coluna = pos_rei->getColuna() - 1;
	int cima = 0, baixo = 0, direita = 0, esquerda = 0, supEsq = 0, supDir = 0,
			infEsq = 0, infDir = 0;

	cout << "procurou o rei " << pos_rei->getLinha() << " "
			<< pos_rei->getColuna() << endl;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (pos[i][j].isOcupada() && !(i == linha && j == coluna))
				if (checaRisco(&pos[linha][coluna], &pos[i][j])) { //se o rei estiver em risco ele esta em cheque
					//Agora tem que verificar se é cheque-mate
					cout << "Rei em risco"
					for (int k = 0; k < 8; ++k) {
						for (int l = 0; l < 8; ++l) {
							if (pos[k][l].isOcupada() && !(k == i && l == j)){
								cout << "verificando o adv do rei" << endl;
								if (checaRisco(&pos[i][j], &pos[k][l])) { // verifica se a peça que põe o rei em risco pode ser morta
									return 1; //estado de cheque
								} else {
									cout << "verificando cima" << endl;
									if ((linha + 1 < 8
											&& !pos[linha + 1][coluna].isOcupada())
											|| cima == 1) { // verifica se rei pode se movimentar para cima
										if (checaRisco(&pos[linha + 1][coluna],
												&pos[k][l]))
											cima = 1;
									} else
										cima = 1;

									cout << "verificando baixo" << endl;
									if ((linha - 1 >= 0
											&& !pos[linha - 1][coluna].isOcupada())
											|| baixo == 1) { // verifica se rei pode se movimentar para baixo
										if (checaRisco(&pos[linha - 1][coluna],
												&pos[k][l]))
											baixo = 1;
									} else
										baixo = 1;

									cout << "verificando esquerda" << endl;
									if ((coluna - 1 >= 0
											&& !pos[linha][coluna - 1].isOcupada())
											|| esquerda == 1) { // verifica se rei pode se movimentar para esquerda
										if (checaRisco(&pos[linha][coluna - 1],
												&pos[k][l]))
											esquerda = 1;
									} else
										esquerda = 1;

									cout << "verificando direita" << endl;
									if ((coluna + 1 < 8
											&& !pos[linha][coluna + 1].isOcupada())
											|| direita == 1) { // verifica se rei pode se movimentar para direita
										if (checaRisco(&pos[linha][coluna + 1],
												&pos[k][l]))
											direita = 1;
									} else
										direita = 1;

									cout << "verificando supesq" << endl;
									if ((linha + 1 < 8 && coluna - 1 >= 0
											&& !pos[linha + 1][coluna - 1].isOcupada())
											|| supEsq == 1) { // verifica se rei pode se movimentar para diagonal superior esquerda
										if (checaRisco(
												&pos[linha + 1][coluna - 1],
												&pos[k][l]))
											supEsq = 1;
									} else
										supEsq = 1;

									cout << "verificando supdir" << endl;
									if ((linha + 1 < 8 && coluna + 1 < 8
											&& !pos[linha + 1][coluna + 1].isOcupada())
											|| supDir == 1) { // verifica se rei pode se movimentar para diagonal superior direita
										if (checaRisco(
												&pos[linha + 1][coluna - 1],
												&pos[k][l]))
											supDir = 1;
									} else
										supDir = 1;

									cout << "verificando infesq" << endl;
									if ((linha - 1 >= 0 && coluna - 1 >= 0
											&& !pos[linha - 1][coluna - 1].isOcupada())
											|| infEsq == 1) { // verifica se rei pode se movimentar para diagonal inferior esquerda
										if (checaRisco(
												&pos[linha - 1][coluna - 1],
												&pos[k][l]))
											infEsq = 1;
									} else
										infEsq = 1;

									cout << "verificando infdir" << endl;
									if ((linha - 1 >= 0 && coluna + 1 < 8
											&& !pos[linha - 1][coluna + 1].isOcupada())
											|| infDir) { // verifica se rei pode se movimentar para diagonal inferior direita
										if (checaRisco(
												&pos[linha - 1][coluna + 1],
												&pos[k][l]))
											infDir = 1;
									} else
										infDir = 1;
								}
							}

							if (cima == 1 && baixo == 1 && esquerda == 1
									&& direita == 1 && supEsq == 1
									&& supDir == 1 && infEsq == 1
									&& infDir == 1)
								return 2;
						}
					}
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

//Verifica se o rei está em xeque
//Entrada: pos_rei = posicao da peca rei; pos_adv: posicao do adversario
//Saída: true se o rei pode ser capturado, false se não
bool Tabuleiro::checaRisco(Posicao *pos_rei, Posicao *pos_adv) {

	Peca *adv = pos_adv->getPca();
	Peca *r = pos_rei->getPca();

//Verifica se existe adversario
	if (adv && adv->getCor() != r->getCor()) {
		cout << adv->checaMovimento(*pos_adv, *pos_rei) << endl;
		//Verifica se a peça inimiga pode capturar o rei
		if (adv->checaMovimento(*pos_adv, *pos_rei)
				&& checaCaminho(pos_adv->getLinha() - 1, pos_adv->getColuna() - 1, pos_rei->getLinha() - 1, pos_rei->getColuna() - 1)) //Verifica se o movimento é permitido e válido
								{
			cout << "true" << endl;
			return true; //A peça pode capturar o rei
		} else
			return false;
	} else
		return false;
}
