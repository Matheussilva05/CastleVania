#include "parede.hpp"
#include "Animacao.hpp"
#include "GerenciadorGrafico.hpp"
#include <string.h>

Parede::Parede(sf::Vector2f pos, int paredeTipo) :
	Obstaculo(pos, sf::Vector2f(PAREDE_LARGURA, PAREDE_ALTURA), 0, ID::parede),
	paredeTipo(paredeTipo) {
	inicializaSprite();
}

Parede::~Parede() { }

void Parede::atualiza(float dt) {
	sprite->atualiza(0, dt, false, posicao);
}

void Parede::inicializaSprite() {
	if (paredeTipo == 1)
		sprite->inicializarTextura(PAREDE_PATH_TP1, sf::Vector2u(1, 1));
	else if (paredeTipo == 2)
		sprite->inicializarTextura(PAREDE_PATH_TP2, sf::Vector2u(1, 1));
	else
		sprite->inicializarTextura(PAREDE_PATH_TP3, sf::Vector2u(1, 1));
}

void Parede::save() {
	if (getAparece()) {
		ofstream file;
		file.open("./Saves/Parede.txt", ios::app);
		if (!file) {
			cout << "Error abrindo save parede" << endl;
			abort();
		}
		file << getPosicao().x << ' ' << getPosicao().y << " " << paredeTipo << endl;
		file.close();
	}
}