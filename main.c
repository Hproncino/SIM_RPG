#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int rolar_dado(int faces)
{
    return (rand() % faces) + 1; // Simula a rolagem de um dado com um número específico de faces.
}                                // Retorna um numero entre 1 e o número de faces.

typedef struct
{
    char nome[20];
    int hp; // Pontos de Vida
    int ca; // Classe de Armadura
    int iniciativa;
    int bonus_ataque;
    int dano_base;
    int rd; // Resistência ao Dano
    // int distancia;
    // int x, y;

} Personagem;

void ataque(Personagem *atacante, Personagem *defensor)
{
    int rolagem_ataque = rolar_dado(20) + atacante->bonus_ataque; // Soma o resultado da rolagem com o bonus de ataque.

    printf("%s obteve um %d no ataque\n", atacante->nome, rolagem_ataque);

    if (rolagem_ataque - atacante->bonus_ataque == 1) // Checa por um 1 natural(ou falha crítica).
    {
        int dano = (atacante->dano_base - atacante->rd); // Dano causado ao próprio atacante.
        if (dano < 0)
            dano = 0;
        atacante->hp -= dano;
        printf("%s tirou 1 no dado e sofreu uma falha crítica, recebendo %d de dano em sí mesmo!\n", atacante->nome, dano);
    }
    else if (rolagem_ataque - atacante->bonus_ataque == 20) // Checa por um 20 natural(ou acerto crítico).
    {
        int dano = (atacante->dano_base - defensor->rd) * 2; // Dobra o dano.
        if (dano < 0)
            dano = 0;
        defensor->hp -= dano;
        printf("%s tirou um 20 no dado e causou %d de dano critico em %s!\n", atacante->nome, dano, defensor->nome);
    }
    else if (rolagem_ataque >= defensor->ca)
    {
        int dano = atacante->dano_base - defensor->rd;
        if (dano < 0)
            dano = 0;
        defensor->hp -= dano;
        printf("O ataque de %s acertou e causou %d de dano\n", atacante->nome, dano);
    }
    else
    {
        printf("%s errou o ataque\n\n", atacante->nome);
    }
}

int esta_vivo(Personagem *personagem) // Checa se o personagem está vivo.
{
    return personagem->hp > 0;
}

void combate(Personagem *jogador, Personagem *inimigo)
{
    int turno = 1; // Inicializa o turno.

    while (esta_vivo(jogador) && esta_vivo(inimigo)) // Enquanto ambos os personagens estiverem vivos, o combate continua.
    {
        printf("\n=== Turno %d ===\n", turno);

        if (jogador->iniciativa > inimigo->iniciativa) // Checa quem tem a maior iniciativa.
        {
            ataque(jogador, inimigo);
            if (esta_vivo(inimigo))
            {
                ataque(inimigo, jogador);
            }
        }
        else
        {
            ataque(inimigo, jogador);
            if (esta_vivo(jogador))
            {
                ataque(jogador, inimigo);
            }
        }

        printf("%s tem %d PV restantes\n", jogador->nome, jogador->hp);
        printf("%s tem %d PV restantes\n", inimigo->nome, inimigo->hp);

        turno++; // Incrementa o turno.
    }

    if (esta_vivo(jogador))
    {
        printf("\n%s venceu o combate\n", jogador->nome);
    }
    else
    {
        printf("\n%s venceu o combate\n", inimigo->nome);
    }
}

int main()
{

    srand(time(NULL));

    // Criação dos personagens e seus atributos.
    Personagem jogador = {"Asterius", 20, 20, 10, 0, 10, 0}; // Resp: Pv, CA, Iniciativa, bonus, dano, rd
    Personagem inimigo = {"Teseu", 20, 20, 9, 0, 10, 0};

    clock_t start_time = clock();

    combate(&jogador, &inimigo); // Inicia o combate.

    clock_t end_time = clock();
    double tempo_gasto = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTempo gasto: %f segundos.\n\n", tempo_gasto);

    return 0;
}