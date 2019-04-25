
#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <iostream>

#include <Peca.h>

class Jogador {
	private:
		const std::string nome;
		const char cor;
		Peca *pecas;
	public:
		Jogador(char cor, std::string nome, Peca *p);
		char getCor();
};

#endif /* JOGADOR_H_ */
