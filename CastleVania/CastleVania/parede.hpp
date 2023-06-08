#pragma once

#include "Obstaculo.hpp"

//colocar imagem da textura
#define PAREDE_PATH_TP1 "./imagens/MAPA/exPlataforma.png"
#define PAREDE_PATH_TP2 "./imagens/MAPA/exPlataforma.png"
#define PAREDE_PATH_TP3 "./imagens/MAPA/exPlataforma.png"

class GerenciadorGrafico;

class Parede : public Obstaculo {
private:
	int paredeTipo;
public:
	Parede(sf::Vector2f pos, int paredeTipo = 1);
	~Parede();
	void atualiza(float dt);
	void inicializaSprite();
	void save();

};


