#pragma once

#include "Personagem/Inimigo/Inimigo.hpp"
#include "Personagem/Jogador/Jogador.hpp"
#include "Listas/EntidadeLista.hpp"
//#include "GerenciadorEventos.h"
#include "Gerenciador/GerenciadorGrafico.hpp"
#include "Gerenciador/GerenciadorInput.hpp"
//#include "EstadoPontuação.h"
//#include "EstadoSave.h"
//#include "EstadoMenu.h"
//#include "MenuControle.h"
//#include "EstadoNovoJogo.h"
//#include "EstadoPauseMenu.h"
//#include "EstadoJogando.h"
//#include "GerenciadorEstado.h"

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
