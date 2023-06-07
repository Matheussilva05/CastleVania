#pragma once
#include "Projetil.hpp"

class Animacao;

#define PATH_BOLADEFOGO_TEXTURA "./imagens/SPRITES/Efeitos/Boladefogo/boladefogospritesheet.png"

#define BOLADEFOGO_LARGURA 40
#define BOLADEFOGO_ALTURA 24
#define BOLADEFOGO_VELOCIDADEX 500
#define BOLADEFOGO_HMAX 200
#define BOLADEFOGO_DANO 100

class BolaDeFogo : public Projetil {
public:
    BolaDeFogo(sf::Vector2f pos);
    ~BolaDeFogo();
    void atualiza(float dt);
    void inicializaSprite();
    void save() { }
};

