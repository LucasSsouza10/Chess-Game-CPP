#include <fstream>
#include "Jogo.h"

using namespace std;

//Construtor com nomes de cada jogador
Jogo::Jogo(string n1, string n2) {
	estado = 0;
	vez = 2; //2 para quando iniciar o jogo comecar pelo jogador 1
	try {
		j1 = new Jogador(n1, 'B');
		j2 = new Jogador(n2, 'P');

		//criando pecas
		criarPecas();
		//setando pecas para os jogadores
		for (int i = 0; i < 16; ++i) {
			j1->addPecas(p[i]);
			j2->addPecas(p[i + 16]);
		}

		//criando tabuleiro e setando pecas
		tab = new Tabuleiro(p);
	} catch (bad_alloc ex) {
		cout << "Erro de alocação de memoria em jogo: " << ex.what() << endl;

	}

}

//Construtor padrão
Jogo::Jogo() {
	estado = 0;
	vez = 0;
	try {
		j1 = new Jogador("Jogador1", 'B');
		j2 = new Jogador("Jogador2", 'P');
		//criando pecas
		criarPecas();
		//setando pecas para os jogadores
		for (int i = 0; i < 16; ++i) {
			j1->addPecas(p[i]);
			j2->addPecas(p[i + 16]);
		}

		//criando tabuleiro e setando pecas
		tab = new Tabuleiro(p);
	} catch (bad_alloc ex) {
		cout << "Erro de alocação de memoria em jogo: " << ex.what() << endl;

	}
}

//Destrutor
Jogo::~Jogo() {
	for (int i = 0; i < 32; ++i) {
		delete p[i];
	}
	delete j1;
	delete j2;

}

//Cria vetor com 16 peças para cada jogador
void Jogo::criarPecas() {
	//Criando peaos
	for (int i = 8; i < 16; i++) {
		p[i] = new Peao(j1->getCor());
		p[i + 16] = new Peao(j2->getCor());
	}

	//torre a esquerda
	p[0] = new Torre(j1->getCor());
	p[16] = new Torre(j2->getCor());

	//cavalo a esquerda
	p[1] = new Cavalo(j1->getCor());
	p[17] = new Cavalo(j2->getCor());

	//Bispo da esquerda
	p[2] = new Bispo(j1->getCor());
	p[18] = new Bispo(j2->getCor());

	//Dama
	p[3] = new Dama(j1->getCor());
	p[19] = new Dama(j2->getCor());

	//Rei
	p[4] = new Rei(j1->getCor());
	p[20] = new Rei(j2->getCor());

	//Bispo da direita
	p[5] = new Bispo(j1->getCor());
	p[21] = new Bispo(j2->getCor());

	//Cavalo da Direita
	p[6] = new Cavalo(j1->getCor());
	p[22] = new Cavalo(j2->getCor());

	//Torre da Direita
	p[7] = new Torre(j1->getCor());
	p[23] = new Torre(j2->getCor());

}

void Jogo::setEstado(int est) {
	estado = est;
}

void Jogo::setVez(int v) {
	vez = v;
}

//Classe que gerencia a partida
void Jogo::playGame() {
	string move;
	string nome;

	while (estado != 2) {

		//depois de cada movimento trocamos a vez de jogar
		if (vez == 1){
			vez = 2;
			nome = j2->getNome();
		}
		else {
			vez = 1;
			nome = j1->getNome();
		}

		string detalheJ1 = j1->getNome() + ": " + j1->getMortas();
		string detalheJ2 = j2->getNome() + ": " + j2->getMortas();
		//Mostra o tabuleiro
		tab->desenharTabuleiro(detalheJ1, detalheJ2);

		//Notificando Estado do jogo
		cout << estado << endl;

		//Pedido de entrada de movimento
		cout << "Jogador " << nome << ", entre com seu movimento, ou digite 0 para encerrar a partida: ";
		getline(cin, move);

		if (move.compare("0") == 0) { //condição para interromper o jogo
			return;
		}

		while (validarFormato(move) == false) {
			cout << vez << "     " << "Formato invalido. Tente novamente: ";
			getline(cin, move);

			if (move.compare("0") == 0) { //condição para interromper o jogo
				return;
			}
		}

		while (mover(move, vez) == false) {

			cout << "Movimento invalido. Tente novamente: ";
			getline(cin, move);

			if (move.compare("0") == 0) { //condição para interromper o jogo
				return;
			}

			while (validarFormato(move) == false) {
				cout << "Formato invalido. Tente novamente: ";
				getline(cin, move);

				if (move.compare("0") == 0) { //condição para interromper o jogo
					return;
				}
			}
		}
		salvarEstado(move);
	}

	if(vez == 2){
		cout << "Parabéns " << j1->getNome() << " você venceu! " << endl;
	}else
		cout << "Parabéns " << j2->getNome() << " você venceu! " << endl;

}

//Verifica se o usuário digitou o movimento no formato correto ("pos. inicial -> pos. final)
bool Jogo::validarFormato(string m) {

	//Um movimento valido tem 8 caracteres
	if (m.length() != 8) {
		return false;
	}

	//verifica se a linha da entrada eh valido com o tamanho do tabuleiro para origem
	if (toupper(m[0]) <= 'A' && toupper(m[0]) >= 'H') {
		return false;
	}

	//verifica se a coluna é valida para origem
	if (m[1] <= '1' && m[1] >= '8') {
		return false;
	}

	//verifica se a seta (' -> ') foi digitada corretamente
	if (m[3] != '-' || m[4] != '>') {
		return false;
	}

	//verifica se eh uma linha valida para destino
	if (toupper(m[6]) <= 'A' && toupper(m[6]) >= 'H') {
		return false;
	}

	//verifica se eh uma coluna valida para destino
	if (m[7] <= '1' && m[7] >= '8') {
		return false;
	}

	else
		return true;
}

//Move a peça
bool Jogo::mover(string m, int vez) {
	int origemLinha, origemColuna, destinoLinha, destinoColuna;
	origemLinha = m[1] - '1'; //para transformar o caractere em um int correspondente
	origemColuna = toupper(m[0]) - 'A';
	destinoLinha = m[7] - '1';
	destinoColuna = toupper(m[6]) - 'A';

	char cor;
	if (vez == 1)
		cor = j1->getCor();
	else
		cor = j2->getCor();

	cout << "verificaMovimento" << endl;
	if (tab->verificaMovimento(origemLinha, origemColuna, destinoLinha,
			destinoColuna)) {
		cout << "Esse movimento põe o rei em xeque!" << endl;
		return false;
	}
	bool movimenta = tab->movimenta(origemLinha, origemColuna, destinoLinha,
			destinoColuna, cor);
	if (movimenta)
		if (vez == 2) {
			estado = tab->checaRei('R');
		} else
			estado = tab->checaRei('r');
	return movimenta;

}

//Salva o jogo
void Jogo::salvarEstado(string m) {
	try {
		ofstream out("JogoSalvo.txt", ios::app);
		out << m << "\n";
		out.close();
	} catch (int x) {
		cout << "Excessao: Não foi possivel abrir o arquivo" << endl;
	}
}

//Carrega o jogo
void Jogo::carregar() {
	try {
		ifstream read("JogoSalvo.txt");
		string move;

		while (!read.eof()) {
			getline(read, move);
			if (validarFormato(move)) {
				if (vez == 1) // para alterar a vez conforme é feito os movimentos primeiro a jogar 1
					vez = 2;
				else
					vez = 1;

				mover(move, vez);
			}
		}
		read.close();
	} catch (int x) {
		cout << "Excessao: Não foi possivel abrir o arquivo" << endl;
	}
}

//Sobrescreve o arquivo de salvamento com um jogo novo
void Jogo::limparSalvo() {
	ofstream ofs;
	ofs.open("JogoSalvo.txt", ofstream::out | ofstream::trunc);
	ofs.close();
}

