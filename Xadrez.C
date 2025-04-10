#include <stdio.h>

// Estrutura da carta
struct Carta {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    // Declaração das cartas
    struct Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 830000.00, 15};
    struct Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6748000, 1182.30, 407000.00, 12};

    // Cálculo da densidade e PIB per capita
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;

    float pibPerCapita1 = carta1.pib / carta1.populacao;
    float pibPerCapita2 = carta2.pib / carta2.populacao;

    // Exibição
    printf("== Comparação de Cartas (PIB per capita) ==\n\n");
    printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.nomeCidade, carta1.estado, pibPerCapita1);
    printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.nomeCidade, carta2.estado, pibPerCapita2);

    // Comparação
    if (pibPerCapita1 > pibPerCapita2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (pibPerCapita2 > pibPerCapita1) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
