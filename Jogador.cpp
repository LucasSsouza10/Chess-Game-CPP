#include "Jogador.h"

Jogador::Jogador(char c, std::string n, Peca *p) : cor(c), nome(n)
{
	pecas = p;
}

char Jogador::getCor(){
	return cor;
}
