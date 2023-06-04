#pragma once

#include "../Personagem/Inimigo/Mago.hpp"
//#include "Raio.h"
#include "PlanoDeFundo.hpp"
//#include "Boss.h"
#include "../Personagem/Inimigo/BolaDeFogo.hpp"
//#include "Esmagador.h"
#include "../Personagem/Plataforma.hpp"
//#include "Espinho.h"
//#include "Parede.h"
//#include "Morcego.h"
#include "../Gerenciador/GerenciadorColisao.hpp"
#include "../Personagem/Entidade.hpp"
#include "../Listas/EntidadeLista.hpp"
#include "../Gerenciador/GerenciadorEvento.hpp"
#include "../Gerenciador/GerenciadorGrafico.hpp"
#include "../Gerenciador/GerenciadorInput.hpp"
#include "Nivel.hpp"
#include "../Personagem/Jogador/Jogador.hpp"
#include "../Gerenciador/ControleJogador.hpp"
#include "../stdafx.h"

class ConstrutorNivel {
    enum txt {
        jogador1 = '1',
        jogador2 = '2',
        morcego = 'g',
        morcegoRand = 's',
        mago = 'z',
        magoRand = 'c',
        boss = 'b',
        espinho = 'e',
        espinhoRand = 'q',
        esmagador = 'v',
        esmagadorRand = 'n',
        plataforma = 'p',
        paredeEsquerda = 'E',
        paredeDireita = 'D',
        end = 'e' //Finaliza o nivel
    };

private:
    Nivel* nvl;
    Jogador* pJogador1;
    Jogador* pJogador2;

    void construirPlataforma(sf::Vector2f pos, int tipo);
    void setJogador1(sf::Vector2f pos, sf::Vector2f vel, int vida, int pontos, int olhandoEsquerda);
    void setJogador1(sf::Vector2f pos);
    void setJogador2(sf::Vector2f pos);
    void setJogador2(sf::Vector2f pos, sf::Vector2f vel, int vida, int pontos, int olhandoEsquerda);
    void construirMago(sf::Vector2f pos);
    void construirMago(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f posProj, sf::Vector2f velProj, int aparece, int vida, int  olhandoEsquerda, int minH, int maxH);
    void construirMorcego(sf::Vector2f pos);
    void construirMorcego(sf::Vector2f pos, sf::Vector2f vel, int vida, int  olhandoEsquerda);
    void construirParede(sf::Vector2f pos, int tipo, bool olhaEsquerda);
    void construirEsmagador(sf::Vector2f pos);
    void construirEspinho(sf::Vector2f pos);
    void construirBoss(sf::Vector2f pos);
    void construirBoss(sf::Vector2f pos, sf::Vector2f vel, int  vida, int olhandoEsquerda);

public:
    ConstrutorNivel();
    ~ConstrutorNivel();
    Nivel* construirMapa(const char* path, Jogador* j1, Jogador* j2, int numnvl);
    Nivel* carregarMapa(Jogador* j1, Jogador* j2);
};
