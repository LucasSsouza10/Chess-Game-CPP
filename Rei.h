
#ifndef REI_H_
#define REI_H_

#include <iostream>

class Rei{
private:
public:
	Rei(std::string, int, int);
	bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
	void desenha();
};

#endif /* REI_H_ */
