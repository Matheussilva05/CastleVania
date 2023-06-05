#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;


#include <fstream>



/* =================================================== */
/*                      DEFINE                         */
/* =================================================== */
/*              JANELA E COISAS GRAFICAS               */
/* =================================================== */

#define FRAME_RATE 100
#define WIDTH 1280
#define HEIGHT 720

/* =================================================== */
/*                     INIMIGOS                        */
/* =================================================== */

#define VIDA_INIMIGO 2000
#define DANO_INIMIGO 25
#define VELOCIDADE_INIMIGO_X 300
#define VELOCIDADE_INIMIGO_X_MAX 500
#define VELOCIDADE_INIMIGO_X_MIN 200

/* =================================================== */
/*                       MAGO                          */
/* =================================================== */
#define MAGO_LARGURA 11
#define MAGO_ALTURA 37
/* =================================================== */
/*                      MORCEGO                        */
/* =================================================== */
#define MORCEGO_LARGURA 13
#define MORCEGO_ALTURA 41

/* =================================================== */
/*                      MAPA                           */
/* =================================================== */

#define GRAVIDADE 3000.f
#define DIV0 0.0000001f //garante que a divisao nao e por 0

/* =================================================== */
/*                    PLATAFORMA                       */
/* =================================================== */

#define PLATAFORMA_LARGURA 225
#define PLATAFORMA_ALTURA 45

/* =================================================== */
/*                      PAREDE                         */
/* =================================================== */

#define PAREDE_LARGURA 45
#define PAREDE_ALTURA 45

/* =================================================== */
/*                    BOLA DE FOGO                     */
/* =================================================== */

#define BOLA_DE_FOGO_LARGURA 40
#define BOLA_DE_FOGO_ALTURA 24
#define BOLA_DE_FOGO_VELOCIDADE 400
#define BOLA_DE_FOGO_ALTURAMAX 200

/* =================================================== */
/*                      PROJETIL                       */
/* =================================================== */

#define DANO_PROJETIL 50

/* =================================================== */
/*                      ESPINHO                        */
/* =================================================== */

#define DANO_ESPINHO 5
#define ESPINHO_LARGURA 225
#define ESPINHO_ALTURA 45

/* =================================================== */
/*                      RAIO                           */
/* =================================================== */
#define VELOCIDADE_RAIO 500
#define RAIO_ALTURAMAX 300
/* =================================================== */
/*                     ESMAGADOR                       */
/* =================================================== */

#define ESMAGADOR_LARGURA 220
#define ESMAGADOR_ALTURA 45


