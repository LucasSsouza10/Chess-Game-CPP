#include "Jogador.h"

using namespace std;

Jogador::Jogador(std::string n, char c) : cor(c), nome(n)
{
}

char Jogador::getCor(){
	return cor;
}

string Jogador::getNome(){
	return nome;
}

void Jogador::setPecas(Peca** p){
	pecas = p;
}
