#include "ConstrutorNivel.hpp"
ConstrutorNivel::ConstrutorNivel() {
    pJogador1 = NULL;
    pJogador2 = NULL;
}

ConstrutorNivel::~ConstrutorNivel() {
}

void ConstrutorNivel::construirPlataforma(sf::Vector2f pos, int tipo) {
    Plataforma* plat = new Plataforma(pos, tipo);
    nvl->addEntidade(plat);
}

void ConstrutorNivel::setJogador1(sf::Vector2f pos) {
    nvl->getJ1()->mudarPosicao(pos);
}
void ConstrutorNivel::setJogador1(sf::Vector2f pos, sf::Vector2f vel, int vida, int pontos, int olhandoEsquerda) {
    nvl->getJ1()->mudarPosicao(pos);
    nvl->getJ1()->setVelocidade(vel);
    nvl->getJ1()->setVida(vida);
    nvl->getJ1()->setPontos(pontos);
    nvl->getJ1()->setOlhandoEsquerda(olhandoEsquerda);
}

void ConstrutorNivel::setJogador2(sf::Vector2f pos) {
    if (nvl->getJ2())
        nvl->getJ2()->mudarPosicao(pos);
}
void ConstrutorNivel::setJogador2(sf::Vector2f pos, sf::Vector2f vel, int vida, int pontos, int olhandoEsquerda) {
    if (nvl->getJ2()) {
        nvl->getJ2()->mudarPosicao(pos);
        nvl->getJ2()->setVelocidade(vel);
        nvl->getJ2()->setVida(vida);
        nvl->getJ2()->setPontos(pontos);
        nvl->getJ2()->setOlhandoEsquerda(olhandoEsquerda);
    }
}

void ConstrutorNivel::construirMago(sf::Vector2f pos) {
    BolaDeFogo* bf = new BolaDeFogo(pos);
    Mago* mg = new Mago(pos, bf, pJogador1, pJogador2);
    nvl->addEntidade(bf);
    nvl->addEntidade(mg);
}

void ConstrutorNivel::construirMago(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f posProj, sf::Vector2f velProj, int shomgng, int vida, int olhandoEsquerda, int minH, int maxH) {
    BolaDeFogo* bf = new BolaDeFogo(posProj);
    Mago* mg = new Mago(pos, bf, pJogador1, pJogador2, minH, maxH);
    nvl->addEntidade(bf);
    nvl->addEntidade(mg);
    bf->setAparece(shomgng);
    bf->setVelocidade(velProj);
    bf->mudarPosicao(posProj);
    mg->setVelocidade(vel);
    mg->setVida(vida);
    mg->setOlhandoEsquerda(olhandoEsquerda);
}
/*
void ConstrutorNivel::construirMorcego(sf::Vector2f pos) {
    Morcego* mor = new Morcego(pos, ar, pJogador1, pJogador2);
    nvl->addEntidade(mor);
}

void ConstrutorNivel::construirMorcego(sf::Vector2f pos, sf::Vector2f vel, int vida, int olhandoEsquerda) {
    Morcego* mor = new Morcego(pos, ar, pJogador1, pJogador2);
    nvl->addEntidade(mor);
    mor->setVelocidade(vel);
    mor->setVida(vida);
    mor->setOlhandoEsquerda(olhandoEsquerda);
}

void ConstrutorNivel::construirBoss(sf::Vector2f pos) {
    Boss* boss = new Boss(pos, pJogador1, pJogador2);
    nvl->addEntidade(boss);
}
void ConstrutorNivel::construirBoss(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f posProj, sf::Vector2f velProj, int shomgng, int vida, int olhandoEsquerda, int minH, int maxH) {
    Raio* raio = new Raio(posProj);
    Boss* boss = new Boss(pos, bf, pJogador1, pJogador2, minH, maxH);
    nvl->addEntidade(raio);
    raio->setShomgng(shomgng);
    raio->setVelocidade(velProj);
    raio->mudarPosicao(posProj);
    nvl->addEntidade(boss);
    boss->setVelocidade(vel);
    boss->setVida(vida);
    boss->setOlhandoEsquerda(olhandoEsquerda);
}

void ConstrutorNivel::construirParede(sf::Vector2f pos, int type, bool olhaEsquerda) {
    Parede* parede = new Parede(pos, type, olhaEsquerda);
    nvl->addEntidade(parede);
}

void ConstrutorNivel::construirEsmagador(sf::Vector2f pos) {
    Esmagador* esmagador = new Esmagador(pos);
    nvl->addEntidade(esmagador);
}

void ConstrutorNivel::construirEspinho(sf::Vector2f pos) {
    Espinho* espinho = new Espinho(pos);
    nvl->addEntidade(espinho);
}
*/
//PATH_PLANODEFUNDO_PLACEHOLDER "./imagens/assets/environment/columns.png"
//PATH_PLANODEFUNDO_CASTELO "./imagens/assets/environment/background.png"

Nivel* ConstrutorNivel::construirMapa(const char* path, Jogador* j1, Jogador* j2, int numnvl) {
    pJogador1 = j1;
    pJogador2 = j2;

    int y = 30, x = 80;
    char nivel[30][80];
    srand(time(NULL));
    ifstream file;
    if (numnvl <= 1) {
        file.open("./assets/Nivels/PrimeiroNivel.txt");
        nvl = new Nivel(PATH_PLANODEFUNDO_PLACEHOLDER, j1, j2, sf::Vector2u(80 * PLATAFORMA_LARGURA, 40 * PLATAFORMA_ALTURA));
    } else if (numnvl == 2) {
        file.open("./assets/Nivels/SegundoNivel.txt");
        nvl = new Nivel(PATH_PLANODEFUNDO_CASTELO, j1, j2, sf::Vector2u(80 * PLATAFORMA_LARGURA, 40 * PLATAFORMA_ALTURA));
    }
    if (!file) {
        cout << "Erro abrindo mapa no ConstrutorNivel" << endl;
        std::exit(54);
    }

    file >> nivel[0][0];
    while (!file.eof()) {
        file.ignore();
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (i || j)
                    file >> nivel[i][j];
                if (nivel[i][j] == txt::plataforma) {
                    construirPlataforma(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA), numnvl);
                } else if (nivel[i][j] == txt::jogador1) {
                    setJogador1(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } else if (nivel[i][j] == txt::mago) {
                    construirMago(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } else if (nivel[i][j] == txt::jogador2) {
                    setJogador2(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                }/* else if (nivel[i][j] == txt::paredeEsquerda) {
                    construirParede(sf::Vector2f(j * PLATAFORMA_LARGURA + (PLATAFORMA_LARGURA - PAREDE_LARGURA) / 2, i * PAREDE_ALTURA), numnvl, true);
                } else if (nivel[i][j] == txt::paredeDireita) {
                    construirParede(sf::Vector2f(j * PLATAFORMA_LARGURA - (PLATAFORMA_LARGURA - PAREDE_LARGURA) / 2, i * PAREDE_ALTURA), numnvl, false);
                } else if (nivel[i][j] == txt::morher) {
                    construirMorcego(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                }  else if (nivel[i][j] == txt::esmagador) {
                    construirEsmagador(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } else if (nivel[i][j] == txt::espinho) {
                    construirEspinho(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } else if (nivel[i][j] == txt::espinhoRand) {
                    int random = rand() % 10;
                    if (random >= 5)
                        construirMorcego(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } else if (nivel[i][j] == txt::magoRand) {
                    int random = rand() % 10;
                    if (random >= 5)
                        construirMago(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } else if (nivel[i][j] == txt::espinhoRand) {
                    int random = rand() % 10;
                    if (random >= 5)
                        construirEspinho(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } else if (nivel[i][j] == txt::esmagadorRand) {
                    int random = rand() % 10;
                    if (random >= 5)
                        construirEsmagador(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } else if (nivel[i][j] == txt::boss) {
                    construirBoss(sf::Vector2f(j * PLATAFORMA_LARGURA, i * PAREDE_ALTURA));
                } */else if (nivel[i][j] == txt::end) {
                    nvl->setFim(j * PLATAFORMA_LARGURA);
                }
            }
        }
    }
    file.close();
    return nvl;
}

Nivel* ConstrutorNivel::carregarMapa(Jogador* j1, Jogador* j2) {
    pJogador1 = j1;
    pJogador2 = j2;

    char path[100];
    int end;
    ifstream Niveltxt("./Saves/Nivel.txt", ios::in);
    if (!Niveltxt) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }

    Niveltxt >> path >> end;
    Niveltxt.close();

    nvl = new Nivel(path, j1, j2, sf::Vector2u(80 * PLATAFORMA_LARGURA, 26 * PLATAFORMA_ALTURA));

    nvl->setFim(end);
    if (!path) {
        cout << "Nenhum nivel salvo" << endl;
        exit(99);
    }

    sf::Vector2f pos;
    bool olhandoEsquerda;
    bool shomgng;
    sf::Vector2f posProj;
    sf::Vector2f velProj;
    sf::Vector2f vel;
    int vida, pontos;

/* ************************************************************************* */
    ifstream Jogador1(("./Saves/Jogador1.txt"), ios::in);
    if (!Jogador1) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }
    Jogador1 >> pos.x >> pos.y >> vel.x >> vel.y >> vida >> pontos >> olhandoEsquerda;
    setJogador1(sf::Vector2f(pos), sf::Vector2f(vel), vida, pontos, olhandoEsquerda);
    Jogador1.close();

/* ************************************************************************* */

    if (j2 != NULL) {
        ifstream Jogador2(("./Saves/Jogador2.txt"), ios::in);
        if (!Jogador2) {
            cout << "Erro ao abrir texto em CarregarMapa" << endl;
            exit(100);
        }

        Jogador2 >> pos.x >> pos.y >> vel.x >> vel.y >> vida >> pontos >> olhandoEsquerda;
        setJogador2(sf::Vector2f(pos), sf::Vector2f(vel), vida, pontos, olhandoEsquerda);
        Jogador2.close();
    }
/* ************************************************************************* */

    int type;
    ifstream Plataforma(("./Saves/Plataforma.txt"), ios::in);
    if (!Plataforma) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }
    while (Plataforma >> pos.x >> pos.y >> type)
        construirPlataforma(sf::Vector2f(pos.x, pos.y), type);
    Plataforma.close();
/* ************************************************************************* */
/*
    ifstream Parede(("./Saves/Parede.txt"), ios::in);
    if (!Parede) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }

    while (Parede >> pos.x >> pos.y >> olhandoEsquerda >> type) {
        construirParede(sf::Vector2f(pos.x, pos.y), type, olhandoEsquerda);
    }
    Parede.close(); */
/* ************************************************************************* */
/*
    ifstream Esmagador(("./Saves/Esmagador.txt"), ios::in);
    if (!Esmagador) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }
    while (Esmagador >> pos.x >> pos.y)
        construirEsmagador(sf::Vector2f(pos.x, pos.y));
    Esmagador.close(); */
/* ************************************************************************* */
/*
    ifstream Espinho("./Saves/Espinho.txt"), ios::in);
    if (!Espinho) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }
    while (Espinho >> pos.x >> pos.y)
        construirEspinho(sf::Vector2f(pos.x, pos.y));
    Espinho.close(); */
/* ************************************************************************* */
/*
    ifstream Morcego("./Saves/Morcego.txt");
    if (!Morcego) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }
    while (Morcego >> pos.x >> pos.y >> vel.x >> vel.y >> vida >> olhandoEsquerda)
        construirMorcego(pos, vel, vida, olhandoEsquerda);
    Morcego.close(); */
/* ************************************************************************* */

    ifstream Mago("./Saves/Mago.txt");
    if (!Mago) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }
    int minH, maxH;
    while (Mago >> pos.x >> pos.y >> vel.x >> vel.y >> posProj.x >> posProj.y >> velProj.x >> velProj.y >> shomgng >> vida >> olhandoEsquerda >> minH >> maxH)
        construirMago(pos, vel, posProj, velProj, shomgng, vida, olhandoEsquerda, minH, maxH);
    Mago.close();
/* ************************************************************************* */
/*
    ifstream Boss("./Saves/Boss.txt");
    if (!Boss) {
        cout << "Erro ao abrir texto em CarregarMapa" << endl;
        exit(100);
    }

    if (Boss >> pos.x >> pos.y >> vel.x >> vel.y >> posProj.x >> posProj.y >> velProj.x >> velProj.y >> shomgng >> vida >> olhandoEsquerda >> minH >> maxH)
        construirBoss(pos, vel, posProj, velProj, shomgng, vida, olhandoEsquerda, minH, maxH);
    Boss.close(); */
/* ************************************************************************* */

    return nvl;
}