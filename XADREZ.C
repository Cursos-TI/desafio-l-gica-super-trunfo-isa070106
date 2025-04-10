#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular a densidade demográfica
float calcularDensidade(int populacao, float area) {
    if (area > 0) {
        return populacao / area;
    } else {
        return 0;
    }
}

// Função para exibir as informações da carta
void exibirCarta(struct Carta carta) {
    printf("País: %s\n", carta.nomePais);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões R$\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidadeDemografica);
}

int main() {
    // Cartas cadastradas
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 18300.0, 50, 0};
    struct Carta carta2 = {"Argentina", 45376763, 2780400.0, 4870.0, 30, 0};

    // Calcular densidade
    carta1.densidadeDemografica = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidadeDemografica = calcularDensidade(carta2.populacao, carta2.area);

    int opcao;

    printf("=== SUPER TRUNFO - COMPARAÇÃO DE CARTAS ===\n\n");

    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("\nCarta 2:\n");
    exibirCarta(carta2);

    // Menu para o jogador
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção (1 a 5): ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d\n", carta2.nomePais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.nomePais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedor: %s\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.nomePais);
            } else if (carta2.area > carta1.area) {
                printf("Vencedor: %s\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f bilhões\n", carta1.nomePais, carta1.pib);
            printf("%s: R$ %.2f bilhões\n", carta2.nomePais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.nomePais);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedor: %s\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomePais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta1.nomePais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Vencedor: %s\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5:
            printf("Atributo: Densidade Demográfica (menor vence)\n");
            printf("%s: %.2f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Vencedor: %s (menor densidade)\n", carta1.nomePais);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Vencedor: %s (menor densidade)\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Opção inválida. Por favor, escolha um número de 1 a 5.\n");
            break;
    }

    return 0;
}

