#pragma once

#include "Listas/EntidadeLista.hpp"
#include "Gerenciador/GerenciadorEvento.hpp"
#include "Gerenciador/GerenciadorGrafico.hpp"
#include "Gerenciador/GerenciadorInput.hpp"
//#include "PontuacaoState.h"
#include "Estados/CarregaJogoState.hpp"
//#include "AcabaJogoState.h"
#include "Estados/MenuPrincipalState.hpp"
#include "Estados/ControleMenu.hpp"
#include "Estados/NovoJogoState.hpp"
#include "Estados/MenuPausaState.hpp"
#include "Estados/JogandoJogoState.hpp"
#include "Estados/GerenciadorEstado.hpp"

#include <SFML/Graphics.hpp>

namespace GE {

    class Jogo : public GerenciadorEstado
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
            bool nivelAcabou;

            public:
            Jogo();
            ~Jogo();

            void iniciarEstados();

            void Executar();
            void save();

            Nivel* getpNivel() const;
            void setNivel(Nivel* pNivel);

            Jogador* getJogador1();
            Jogador* getJogador2();
            bool doisJogadoresAtivos() const;

            int getNivelAtual() const;
            void setNivelAtual(int num);

            void acabarJogo();
            void deleteNivel();
            void resetJogadores();
            bool taJogando() const;
            void setNivelAcabou(bool x);
    };
}
