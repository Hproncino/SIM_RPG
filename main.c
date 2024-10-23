#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolar_dado(int faces)
{
    return (rand() % faces) + 1;
}

typedef struct
{
    char nome[20];
    int hp;
    int ca;
    int iniciativa;
    int bonus_ataque;
    int dano_base;
    int rd;
    int resistencia;

} Personagem;

void ataque(Personagem *atacante, Personagem *defensor)
{
    int rolagem_ataque = rolar_dado(20) + atacante->bonus_ataque;

    printf("%s obteve um %d no ataque\n", atacante->nome, rolagem_ataque);

    if (rolagem_ataque >= defensor->ca)
    {
        int dano = atacante->dano_base - defensor->rd;
        if (dano < 0) dano = 0;

        defensor->hp -= dano;
        printf("O ataque de %s acertou e causou %d de dano\n", atacante->nome, dano);

        if (defensor->hp < 0)
            defensor->hp = 0;
    }
    else
    {
        printf("%s errou o ataque\n", atacante->nome);
    }
}

int esta_vivo(Personagem *personagem)
{
    return personagem->hp > 0;
}

void combate(Personagem *jogador, Personagem *inimigo)
{
    int turno = 1;

    while (esta_vivo(jogador) && esta_vivo(inimigo))
    {
        printf("\n=== Turno %d ===\n", turno);

        if (jogador->iniciativa > inimigo->iniciativa)
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

        turno++;
    }

    if (esta_vivo(jogador))
    {
        printf("%s venceu o combate\n", jogador->nome);
    }
    else
    {
        printf("%s venceu o combate\n\n", inimigo->nome);
    }
}

int main()
{

    srand(time(NULL));

    Personagem jogador = {"Asterius", 50, 20, 10, 10, 20, 5}; // Resp: Pv, CA, Iniciativa, bonus, dano, rd
    Personagem inimigo = {"Teseu", 50, 20, 9, 10, 20, 5};

    clock_t start_time = clock();

    combate(&jogador, &inimigo);

    clock_t end_time = clock();
    double tempo_gasto = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTempo gasto: %f segundos.\n\n", tempo_gasto);

    return 0;
}