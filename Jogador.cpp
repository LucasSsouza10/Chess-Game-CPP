#include "Jogador.h"

Jogador::Jogador(std::string n, char c, Peca *p) : cor(c), nome(n)
{
	pecas = p;
}

char Jogador::getCor(){
	return cor;
}
