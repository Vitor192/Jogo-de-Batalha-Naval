#include <stdio.h>
#include <stdlib.h>

// Definição de constantes
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se o posicionamento do navio é válido
int posicionamentoValido(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                         int linhaInicial, int colunaInicial, 
                         int horizontal) {
    // Verificar se o navio está dentro dos limites do tabuleiro
    if (horizontal) {
        if (colunaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Inválido: navio sai do tabuleiro horizontalmente
        }
        
        // Verificar se há sobreposição com outro navio
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[linhaInicial][colunaInicial + j] == NAVIO) {
                return 0; // Inválido: sobreposição com outro navio
            }
        }
    } else { // Vertical
        if (linhaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Inválido: navio sai do tabuleiro verticalmente
        }
        
        // Verificar se há sobreposição com outro navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaInicial + i][colunaInicial] == NAVIO) {
                return 0; // Inválido: sobreposição com outro navio
            }
        }
    }
    
    return 1; // Posicionamento válido
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int linhaInicial, int colunaInicial, 
                     int horizontal) {
    if (posicionamentoValido(tabuleiro, linhaInicial, colunaInicial, horizontal)) {
        if (horizontal) {
            for (int j = 0; j < TAMANHO_NAVIO; j++) {
                tabuleiro[linhaInicial][colunaInicial + j] = NAVIO;
            }
        } else { // Vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaInicial + i][colunaInicial] = NAVIO;
            }
        }
        printf("Navio posicionado com sucesso!\n");
    } else {
        printf("Posicionamento inválido! O navio está fora dos limites ou sobrepõe outro navio.\n");
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicialização do tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    
    // Coordenadas para o navio horizontal
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 3;
    
    // Coordenadas para o navio vertical
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;
    
    // Posicionar o navio horizontal
    posicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, 1);
    
    // Posicionar o navio vertical
    posicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, 0);
    
    // Exibir o tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}