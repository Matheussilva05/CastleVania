#pragma once

#include "../stdafx.h"
#include "../Gerenciador/Observador.hpp"

class Menu;
class GerenciadorInput;

class ControleMenu : public Observador {
private:
    Menu* pMenu;

public:
    ControleMenu(GerenciadorInput* pGI, Menu* pM = NULL);
    ~ControleMenu();

    void notifica();
    void addMenu(Menu* p);
};
