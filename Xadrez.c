#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar as cartas dos países
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
    return area > 0 ? populacao / area : 0;
}

// Função para exibir as informações de uma carta
void exibirCarta(struct Carta carta) {
    printf("País: %s\n", carta.nomePais);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões R$\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidadeDemografica);
}

// Função para comparar os atributos selecionados
void compararAtributos(int atributo1, int atributo2, struct Carta carta1, struct Carta carta2) {
    float valor1Atributo1, valor1Atributo2, valor2Atributo1, valor2Atributo2;
    float somaCarta1 = 0, somaCarta2 = 0;

    // Comparando o primeiro atributo
    switch (atributo1) {
        case 1: // População
            valor1Atributo1 = carta1.populacao;
            valor2Atributo1 = carta2.populacao;
            break;
        case 2: // Área
            valor1Atributo1 = carta1.area;
            valor2Atributo1 = carta2.area;
            break;
        case 3: // PIB
            valor1Atributo1 = carta1.pib;
            valor2Atributo1 = carta2.pib;
            break;
        case 4: // Pontos Turísticos
            valor1Atributo1 = carta1.pontosTuristicos;
            valor2Atributo1 = carta2.pontosTuristicos;
            break;
        case 5: // Densidade Demográfica
            valor1Atributo1 = carta1.densidadeDemografica;
            valor2Atributo1 = carta2.densidadeDemografica;
            break;
        default:
            printf("Opção inválida para o primeiro atributo.\n");
            return;
    }

    // Comparando o segundo atributo
    switch (atributo2) {
        case 1: // População
            valor1Atributo2 = carta1.populacao;
            valor2Atributo2 = carta2.populacao;
            break;
        case 2: // Área
            valor1Atributo2 = carta1.area;
            valor2Atributo2 = carta2.area;
            break;
        case 3: // PIB
            valor1Atributo2 = carta1.pib;
            valor2Atributo2 = carta2.pib;
            break;
        case 4: // Pontos Turísticos
            valor1Atributo2 = carta1.pontosTuristicos;
            valor2Atributo2 = carta2.pontosTuristicos;
            break;
        case 5: // Densidade Demográfica
            valor1Atributo2 = carta1.densidadeDemografica;
            valor2Atributo2 = carta2.densidadeDemografica;
            break;
        default:
            printf("Opção inválida para o segundo atributo.\n");
            return;
    }

    // Regra de comparação: Se for densidade demográfica, o menor valor vence
    if (atributo1 == 5) {
        somaCarta1 += (valor1Atributo1 < valor2Atributo1) ? valor1Atributo1 : valor2Atributo1;
    } else {
        somaCarta1 += (valor1Atributo1 > valor2Atributo1) ? valor1Atributo1 : valor2Atributo1;
    }

    if (atributo2 == 5) {
        somaCarta2 += (valor2Atributo2 < valor1Atributo2) ? valor2Atributo2 : valor1Atributo2;
    } else {
        somaCarta2 += (valor2Atributo2 > valor1Atributo2) ? valor2Atributo2 : valor1Atributo2;
    }

    // Exibindo os resultados das comparações
    printf("\nComparando os Atributos:\n");
    printf("Carta 1 - %s | Atributo 1: %.2f | Atributo 2: %.2f\n", carta1.nomePais, valor1Atributo1, valor1Atributo2);
    printf("Carta 2 - %s | Atributo 1: %.2f | Atributo 2: %.2f\n", carta2.nomePais, valor2Atributo1, valor2Atributo2);

    // Comparando as somas dos atributos
    printf("\nSoma dos Atributos para cada carta:\n");
    printf("Soma Carta 1: %.2f\n", somaCarta1);
    printf("Soma Carta 2: %.2f\n", somaCarta2);

    // Determinando o vencedor
    if (somaCarta1 > somaCarta2) {
        printf("\nVencedor: %s\n", carta1.nomePais);
    } else if (somaCarta2 > somaCarta1) {
        printf("\nVencedor: %s\n", carta2.nomePais);
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
    // Cartas pré-cadastradas
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 18300.0, 50, 0};
    struct Carta carta2 = {"Argentina", 45376763, 2780400.0, 4870.0, 30, 0};

    // Calcular densidade demográfica para ambas as cartas
    carta1.densidadeDemografica = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidadeDemografica = calcularDensidade(carta2.populacao, carta2.area);

    // Exibir as cartas
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("\nCarta 2:\n");
    exibirCarta(carta2);

    // Escolhas de atributos do jogador
    int atributo1, atributo2;

    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &atributo1);

    // Garantir que o jogador não escolha o mesmo atributo duas vezes
    do {
        printf("\nEscolha o segundo atributo para comparação (não pode ser o mesmo do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
        printf("Digite a opção: ");
        scanf("%d", &atributo2);
    } while (atributo1 == atributo2);

    // Chama a função para comparar os atributos
    compararAtributos(atributo1, atributo2, carta1, carta2);

    return 0;
}