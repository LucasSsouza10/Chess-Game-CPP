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

//Atribui o conjunto de peças ao jogador
void Jogador::addPecas(Peca *p){
	pecas[quantPecas] = p;
	quantPecas++;
}
