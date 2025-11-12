#include <stdio.h>

   int main() {
    
    char colunaLetra [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
      
    int tabuleiro[10][10];
     
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    
    int linhaHorizontal = 1;  
    int colunaHorizontal = 3; 
    int linhaVertical = 4;    
    int colunaVertical = 6;   

    
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    printf("*** COORDENADAS DOS NAVIOS ***\n");
    printf("Navio horizontal:\n");
    for (int i = 0; i < 3; i++) {
        printf("(%c, %d)\n", colunaLetra[colunaHorizontal + i], linhaHorizontal + 1);
    }

    printf("Navio vertical:\n");
    for (int i = 0; i < 3; i++) {
        printf("(%c, %d)\n", colunaLetra[colunaVertical], linhaVertical + i + 1);
    }

    printf("\n*** TABULEIRO BATALHA NAVAL ***\n\n");

    
    printf("    ");
    for (int c = 0; c < 10; c++) {
        printf("%c ", colunaLetra[c]);
    }
    printf("\n");

   
    for (int i = 0; i < 10; i++) {
        printf("%2d: ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("    ");
    for (int c = 0; c < 10; c++) {
        printf("%c ", colunaLetra[c]);
    }
    printf("\n");

    return 0;
}