#pragma once

#include "Obstaculo.hpp"

#define PLATAFORMA_PATH_SUBIDA "CastleVania/imagens/MAPA/tileset.png"
#define PLATAFORMA_PATH_DESCIDA "CastleVania/imagens/MAPA/tileset.png"
#define PLATAFORMA_PATH_RETO "CastleVania/imagens/MAPA/tileset.png"

#define PLATAFORMA_LARGURA 225
#define PLATAFORMA_ALTURA 45

class GerenciadorGrafico;

class Plataforma : public Obstaculo {
private:
    int platTipo;

public:
    Plataforma(sf::Vector2f pos, int platTipo = 1);
    ~Plataforma();
    void atualiza(float dt);
    void inicializaSprite();
    void save();
};

