
#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <iostream>

#include <Peca.h>

class Jogador {
	private:
		std::string nome;
		std::string cor;
		Peca *pecas;
	public:
		Jogador(std::string cor);
};

#endif /* JOGADOR_H_ */
