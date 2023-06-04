#include "Inimigo.hpp"

#include "Animacao.hpp"
#include "Jogador.hpp"
#include "math.h"

Inimigo::Inimigo(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int vd, int dn, Jogador* pJogador1, Jogador* pJogador2) :
Personagem(id, pos, hit, vd, dn),
jogador1(jogador1),
jogador2(jogador2),
ataqueTempoDeEspera(0.0) {
    tempoTotalAtaque = 0.0f;
}

Inimigo::~Inimigo() {
}

Jogador* Inimigo::getJogadorProximo() {
    int x1, x2;
    if (jogador2) {
        x1 = abs(jogador1->getPosicao().x - posicao.x);
        x2 = abs(jogador2->getPosicao().x - posicao.x);
        if (x1 < x2)
            return jogador1;
        else
            return jogador2;
    }
    else
        return jogador1;
}
/* Atualiza posicao e velocidade do Inimigo
void Inimigo::atualiza(float dt) {
    if (vida <= 0)
        setAparece(false);

    if (taAndando)
        velocidade = Vector2f(velocidade.x, velocidade.y + GRAVIDADE * dt);
    else
        velocidade = Vector2f(velocidade.x * 0.01f, velocidade.y + GRAVIDADE * dt);

    if (velocidade.y > 700)
        velocidade = Vector2f(velocidade.x, 700);

    mudarPosicao(Vector2f(velocidade.x * dt + posicao.x, velocidade.y * dt + posicao.y));

    atualizaSprite(dt);
}
*/
void Inimigo::colisao(Entidade* outro, sf::Vector2f direcao) {
    if (outro->getId() == ID::jogador) {
        if (direcao.x < 0.0f) {
            velocidade.x = 0.0f;
            mudarPosicao(Vector2f(outro->getPosicao().x + outro->getHitbox().x, posicao.y));
        }
        else if (direcao.x > 0.0f) {
            velocidade.x = 0.0f;
            mudarPosicao(Vector2f(outro->getPosicao().x - hitbox.x, posicao.y));
        }
        if (direcao.y < 0.0f) {
            velocidade.y = 0.0f;
            mudarPosicao(Vector2f(posicao.x, outro->getPosicao().y + outro->getHitbox().y));
        }
        else if (direcao.y > 0.0f) {
            velocidade.y = 0.0f;
            mudarPosicao(Vector2f(posicao.x, outro->getPosicao().y - hitbox.y));
        }
    }
}




