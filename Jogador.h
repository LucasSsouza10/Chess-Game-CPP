
#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <iostream>

#include <Peca.h>

class Jogador {
	private:
		const std::string nome;
		const std::string cor;
		Peca *pecas;
	public:
		Jogador(std::string cor,std::string nome,Peca *p);

};

#endif /* JOGADOR_H_ */
