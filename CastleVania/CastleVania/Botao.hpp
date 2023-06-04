#pragma once

#include "../../include/Personagem/Ent.hpp"
#include "../../include/Gerenciador/GerenciadorGrafico.hpp"
#include "../../include/stdafx.h"

#define BOTAO_PATH "./imagens/assets/images/botao.png"
#define TEXT_SIZE 24

class Botao : public Ent {
private:
    bool hover;
    GerenciadorGrafico* pGerenciadorGrafico;
    sf::Text texto;
    sf::Font fonte;

public:
    Botao(sf::Vector2f pos);
    Botao();
    virtual ~Botao();

    void inicializaSprite();
    void renderiza();
    void atualiza(float dt) { }

    void setMensagem(const char* m);
    void seleciona(const bool selecionado) { hover = selecionado; }
};


