#ifndef REI_H_
#define REI_H_

#include <iostream>
#include "Peca.h"
#include "Posicao.h"

class Rei: public Peca {
public:
	Rei(char);
	Rei(Rei const &);
	Rei* clone() const;
	bool checaMovimento(Posicao origem, Posicao destino);
	char desenha();
};

#endif /* REI_H_ */
