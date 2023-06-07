#pragma once

#include "Obstaculo.hpp"

#define PLATAFORMA_PATH_SUBIDA "./imagens/MAPA/tileset.png"
#define PLATAFORMA_PATH_DESCIDA "./imagens/MAPA/tileset.png"
#define PLATAFORMA_PATH_RETO "./imagens/MAPA/tileset.png"



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

