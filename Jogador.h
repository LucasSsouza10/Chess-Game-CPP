
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
		Jogador(std::string nome, char cor);
		void setPecas(Peca**);
		char getCor();
		std::string getNome();
};

#endif /* JOGADOR_H_ */
