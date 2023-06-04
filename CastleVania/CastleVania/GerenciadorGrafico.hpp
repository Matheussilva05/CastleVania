#pragma once

#include "EntidadeLista.hpp"
#include "Jogador.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "stdafx.h"

//#define FONT_PATH "./COLOCA PATH PARA FONTE"



        class GerenciadorGrafico{
        private:
            sf::RenderWindow* window;
            sf::View view;

            //a construtor privada faz parte do padrao de projeto singleton
            static GerenciadorGrafico* pGrafico;
            GerenciadorGrafico();
            std::map<const char*, sf::Texture*> mapaTextura;
        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getGerenciadorGrafico();
            sf::RenderWindow* getWindow();
            void clear();
            void desenhaElemento(sf::RectangleShape* corpo);
            void desenhaElemento(sf::Text* texto);
            void mostraElemento();
            sf::Texture* carregarTextura(const char* caminho);
            void fecharJanela();
            void centerView(sf::Vector2f pos);
            sf::Vector2u getWindowSize() const;
            const bool verificaJanelaAberta();
            void redefinirTamanhoJanela();

        };


