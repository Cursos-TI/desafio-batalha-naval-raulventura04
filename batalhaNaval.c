#include <stdio.h>  

#define SIZE 10 // Tamanho do tabuleiro  
#define NAVIO 3  // Valor que representa a parte do navio  

// Função para inicializar o tabuleiro  
void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {  
    for (int i = 0; i < SIZE; i++) {  
        for (int j = 0; j < SIZE; j++) {  
            tabuleiro[i][j] = 0; // Inicializa todas as células com 0 (vazias)  
        }  
    }  
}  

// Função para imprimir o tabuleiro  
void imprimirTabuleiro(int tabuleiro[SIZE][SIZE]) {  
    for (int i = 0; i < SIZE; i++) {  
        for (int j = 0; j < SIZE; j++) {  
            printf("%d ", tabuleiro[i][j]); // Exibe o conteúdo da célula  
        }  
        printf("\n"); // Nova linha após cada linha do tabuleiro  
    }  
}  

// Função para posicionar navios  
void posicionarNavios(int tabuleiro[SIZE][SIZE]) {  
    // Posicione um navio horizontal na linha 2, da coluna 2 à coluna 4  
    for (int j = 2; j <= 4; j++) {  
        tabuleiro[2][j] = NAVIO; // Marca a posição do navio  
        printf("Navio Horizontal: (2, %d)\n", j);  
    }  

    // Posicione um navio vertical na coluna 6, da linha 1 à linha 3  
    for (int i = 1; i <= 3; i++) {  
        tabuleiro[i][6] = NAVIO; // Marca a posição do navio  
        printf("Navio Vertical: (%d, 6)\n", i);  
    }  

    // Posicione dois navios diagonais  
    tabuleiro[0][8] = NAVIO; // Posiciona na primeira linha e nona coluna  
    tabuleiro[1][9] = NAVIO; // Posiciona na segunda linha e décima coluna  
    printf("Navio Diagonal: (0, 8)\n");  
    printf("Navio Diagonal: (1, 9)\n");  
}  

// Função para definir habilidades especiais em forma de cone  
void definirHabilidadeCone(int tabuleiro[SIZE][SIZE], int centroX, int centroY) {  
    for (int i = 0; i < SIZE; i++) {  
        for (int j = 0; j < SIZE; j++) {  
            // Verifica se está dentro da área do cone  
            if ((i + j >= centroX + centroY) && (i - centroX + j - centroY <= 2) && (j - centroY <= i - centroX)) {  
                tabuleiro[i][j] = 1; // Define a área atingida pela habilidade  
            }  
        }  
    }  
}  

// Função para definir habilidades especiais em forma de cruz  
void definirHabilidadeCruz(int tabuleiro[SIZE][SIZE], int centroX, int centroY) {  
    for (int i = 0; i < SIZE; i++) {  
        for (int j = 0; j < SIZE; j++) {  
            // Verifica se está na linha ou coluna do centro  
            if (i == centroX || j == centroY) {  
                tabuleiro[i][j] = 1; // Define a área atingida pela habilidade  
            }  
        }  
    }  
}  

// Função para definir habilidades especiais em forma de octaedro  
void definirHabilidadeOctaedro(int tabuleiro[SIZE][SIZE], int centroX, int centroY) {  
    for (int i = 0; i < SIZE; i++) {  
        for (int j = 0; j < SIZE; j++) {  
            // Verifica se a posição está dentro do octaedro  
            if (abs(i - centroX) + abs(j - centroY) <= 2) {  
                tabuleiro[i][j] = 1; // Define a área atingida pela habilidade  
            }  
        }  
    }  
}  

// Função principal  
int main() {  
    int tabuleiro[SIZE][SIZE]; // Declara a matriz para o tabuleiro  
    inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro  

    // Nível Novato - Posicionamento dos Navios  
    printf("Posicionamento dos Navios:\n");  
    posicionarNavios(tabuleiro); // Posiciona os navios  
    printf("\nTabuleiro após posicionamento dos navios:\n");  
    imprimirTabuleiro(tabuleiro); // Imprime o tabuleiro  

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal  
    // O tabuleiro já foi expandido para 10x10, e navios diagonais foram posicionados  

    // Nível Mestre - Habilidades Especiais com Matrizes  
    // Definindo as áreas de habilidades especiais  
    printf("\nHabilidades Especiais:\n");  

    // Resetando o tabuleiro para padrão antes de habilidade  
    inicializarTabuleiro(tabuleiro);   

    definirHabilidadeCone(tabuleiro, 4, 4); // Centralize cone na posição (4, 4)  
    printf("Habilidade Cone:\n");  
    imprimirTabuleiro(tabuleiro); // Imprime o tabuleiro com cone  
    printf("\n");  

    // Resetando o tabuleiro para padrão antes de habilidade  
    inicializarTabuleiro(tabuleiro);  
    
    definirHabilidadeCruz(tabuleiro, 4, 4); // Centralize cruz na posição (4, 4)  
    printf("Habilidade Cruz:\n");  
    imprimirTabuleiro(tabuleiro); // Imprime o tabuleiro com cruz  
    printf("\n");  

    // Resetando o tabuleiro para padrão antes de habilidade  
    inicializarTabuleiro(tabuleiro);  
    
    definirHabilidadeOctaedro(tabuleiro, 4, 4); // Centralize octaedro na posição (4, 4)  
    printf("Habilidade Octaedro:\n");  
    imprimirTabuleiro(tabuleiro); // Imprime o tabuleiro com octaedro  
    printf("\n");  

    return 0;  
}
