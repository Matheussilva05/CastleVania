#include "../../include/Personagem/Personagem.hpp"
#include "../../include/Animacao/Animacao.hpp"


        Personagem::Personagem(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int vd, int auxdano):
            Entidade(id, pos, hit), vida(vd), dano(auxdano)
        {
            taAtacando = false;
        }

        Personagem::~Personagem(){
            // Nothing to do here
        }

        int Personagem::ataque(){
            return dano;
        }

        void Personagem::tomaDano(int auxdano) {
         vida -= auxdano;
         }

        int Personagem::getVida() const {
        return vida;
        }


