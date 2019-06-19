#include "Jogador.h"

using namespace std;

Jogador::Jogador(std::string n, char c){
	cor = c;
	nome = n;
	quantPecas = 0;
}

char Jogador::getCor(){
	return cor;
}

string Jogador::getNome(){
	return nome;
}

void Jogador::addPecas(Peca *p){
	pecas[quantPecas] = p;
	quantPecas++;
}
