
#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <iostream>

#include "Peca.h"

class Jogador {
	private:
		std::string nome;
		char cor;
		Peca **pecas;
	public:
		Jogador(std::string nome, char cor, Peca **p);
		char getCor();
};

#endif /* JOGADOR_H_ */
