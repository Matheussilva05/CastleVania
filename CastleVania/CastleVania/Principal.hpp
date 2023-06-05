#pragma once

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "EntidadeLista.hpp"
#include "GerenciadorEvento.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorInput.hpp"
//#include "EstadoPontuação.h"
//#include "EstadoSave.h"
//#include "EstadoMenu.h"
//#include "MenuControle.h"
//#include "EstadoNovoJogo.h"
//#include "EstadoPauseMenu.h"
//#include "EstadoJogando.h"
#include "GerenciadorEstado.hpp"

#include <SFML/Graphics.hpp>

namespace GE {

    class Principal : public GerenciadorEstado
    {
        private:

            GerenciadorGrafico* pGrafico;
            GerenciadorEvento* pEvento;
            GerenciadorInput* pInput;
            Nivel* pNivel;
            Jogador* jogador1;
            Jogador* jogador2;
            int nivelAtual;
            sf::Clock time;
            bool nvlAcabou;

            public:
            Jogo();
            ~Jogo();

            void iniciarEstados();

            void Executar();
            void save();

            Nivel* getpNivel() const;
            void setLevel(Nivel* pNivel);

            Jogador* getJogador1();
            Jogador* getJogador2();
            bool doisJogadoresAtivos() const;

            int getNivelAtual() const;
            void setNivelAtual(int num);

            void acabarJogo();
            void deleteNivel();
            void resetJogadores();
            bool taJogando() const;
            void setNvlAcabou(bool x);
    };
}
