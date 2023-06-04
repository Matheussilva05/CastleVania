#include "..\include\Principal.hpp"




    Principal::Jogo()

    {
        pEvento = GerenciadorEvento::getGerenciadorEvento();
        pGraphicM = GerenciadorGrafico::getGerenciadorGrafico();

        pInput = new GerenciadorInput;
        pEvento->setGerenciadorInput(pInput);

        jogador1 = NULL;
        jogador2 = NULL;
        pNivel = NULL;
        nvlAcabou = false;

        iniciarEstados();
        Executar();
    }

    Principal::~Jogo() {
    if (pNivel != NULL)
        delete (pNivel);
    if (jogador1)
        delete (jogador1);
    if (jogador2)
        delete (jogador2);
    }

    void Principal::Executar() {
       float dt;
       time.restart();



        while (pGrafico->verificaJanelaAberta()) {
         /* Olha se algum evento aconteceu */
        pEvento->pollEventos();
         /* Tempo desde o ultimo loop */
         dt = time.getElapsedTime().asSeconds();
        time.restart();
        if (dt > 0.1)
            dt = 0.1;
        /* Limpa tela e desenha de novo */
        pGrafico->clear();
        /* Chama estado novo e renderiza */
        // execCurrentState(dt);
        /* Mostra tudo desenhado */
        pGrafico->mostraElemento();
    }
}


void Principal::save() {
    if (pNivel != NULL)
        pNivel->saveNvl();
}

Nivel* Principal::getpNivel() const {
    return pNivel;
}

void Principal::setNivel(Nivel* pNivel) {
    this->pNivel = pNivel;
}

Jogador* Principal::getJogador1() {
    if (jogador1 == NULL)
        jogador1 = new Jogador(true, pInput);
    return jogador1;
}

Jogador* Principal::getJogador2() {
    if (jogador2 == NULL)
        jogador2 = new Jogador(false, pInput);
    return jogador2;
}

bool Principal::doisJogadoresAtivos() const {
    return ((jogador1 != NULL) && (jogador2 != NULL));
}

int Principal::getNivelAtual() const {
    return nivelAtual;
}

void Principal::setNivelAtual(int num) {
    nivelAtual = num;
}

void Principal::acabarJogo() {
    pGraphic->closeWindow();
}

void Principal::deleteNivel() {
    if (pNivel != NULL)
        delete (pNivel);
    pNivel = NULL;
}

void Principal::resetJogadores() {
    if (jogador1 != NULL)
        delete jogador1;
    if (jogador2 != NULL)
        delete jogador2;
    jogador1 = NULL;
    jogador2 = NULL;
}

bool Principal::taJogando() const {
    return nivelAcabou;
}

void Principal::setnivelAcabou(bool x) {
    nivelAcabou = x;
}
