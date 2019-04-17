#ifndef PECA_H_
#define PECA_H_

#include <iostream>

class Peca {
private:
	std::string cor;
	int linha;
	int coluna;
public:
	Peca(std::string, int, int);
	std::string getCor();
	int getLinha();
	int getColuna();
};

#endif /* PECA_H_ */
