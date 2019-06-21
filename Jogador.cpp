#include "Jogador.h"

using namespace std;

//Construtor de jogador; recebe nome e cor
Jogador::Jogador(std::string n, char c){
	cor = c;
	nome = n;
	quantPecas = 0;
}

//Retorna a cor do joador
char Jogador::getCor(){
	return cor;
}

//Retorna nome do jogador
string Jogador::getNome(){
	return nome;
}

//Atribui o conjunto de pe�as ao jogador
void Jogador::addPecas(Peca *p){
	pecas[quantPecas] = p;
	quantPecas++;
}

string Jogador::getMortas(){
	string str = "";
	for (int i = 0; i < 16; ++i) {
		if(pecas[i]->getSituacao() == 0){
			str += pecas[i]->desenha();
			str += " ";
		}
	}
	return str;
}
