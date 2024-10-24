# SIMULAÇÃO DE COMBATE DE RPG DE MESA.

- Descrição:

Este algoritmo implementa uma simulação de combate entre dois personagens em um jogo de RPG. Utiliza conceitos de rolagem de dados, ataque, defesa e gerenciamento de pontos de vida (HP). O combate é baseado em turnos, onde cada personagem tem a chance de atacar, ao atacarem é comparado o valor de seus acertos com a defesa do personagem que caso seja maior ou igual a ela o alvo leva o dano especificado.

- Funcionalidades:

**Rolagem de Dados**: A função rolar_dado(int faces) simula a rolagem de um dado com um número específico de faces, retornando um valor entre 1 e o número de faces.

**Estrutura de Personagem**: A estrutura Personagem contém atributos como nome, pontos de vida (HP), classe de armadura (CA), iniciativa, bônus de ataque, dano base, resistência a dano (RD) e resistência.

**Ataque**: A função ataque(Personagem *atacante, Personagem *defensor) calcula se um ataque acerta ou erra, determina o dano causado e atualiza os pontos de vida do defensor.

**Verificação de Vida**: A função esta_vivo(Personagem *personagem) verifica se o personagem ainda tem pontos de vida.

**Combate**: A função combate(Personagem *jogador, Personagem *inimigo) gerencia o fluxo do combate, alternando turnos entre o jogador e o inimigo até que um deles seja derrotado.

**Tempo de Execução**: O tempo total gasto na simulação de combate é calculado e exibido ao final do combate.

- Um breve exemplo de como seria o output:

![image](https://github.com/user-attachments/assets/7f7722c4-83fd-4c0e-978a-73e8eac43366)

Ainda planejo adicionar funcionalidades como resistencia a certos tipos de dano, assim como magias, itens, ETC...

# Algumas Features implementadas:

- **Redução de dano**: Valor de redução de dano ao se acertar um ataque.

- **iniciativa**: Ao se iniciar a batalha aquele que tiver o maior valor de iniciativa começará primeiro com o direito do primeiro ataque. 

- **Dano Crítico**: Dano crítico inflingido ao se tirar um 20 natural na rolagem de dados, com multiplicação do dano por 2x padrão, podendo ser alterado no código.



