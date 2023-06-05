#pragma once

#include "Menu.hpp"
#include "Estado.hpp"

class GerenciadorInput;

#define BACKGROUND_PATH "CastleVania/imagens/assets/environment/background.png"

namespace GE {

class Jogo;

class MenuPausaState : public Menu, public Estado {
private:
    Jogo* pJogo;

public:
    MenuPausaState(GerenciadorInput* GI = NULL, Jogo* pJ = NULL);
    ~MenuPausaState();

    void atualiza(float dt);
    void renderiza();
    void exec();
    void resetEstado();
};

}
