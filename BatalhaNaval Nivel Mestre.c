#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char colunaLetra [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
      
    int tabuleiro[10][10];
    int matrizCone[5][5];
    int matrizCruz[5][5];
    int matrizOctaedro[5][5];
     
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrizCone[i][j] = 0;
            matrizCruz[i][j] = 0;
            matrizOctaedro[i][j] = 0;
        }
    }

    // --- CONE ---
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            matrizCone[2 + i][2 + j] = 6;
        }
    }

    // --- CRUZ ---
    for (int i = 0; i < 5; i++) {
        matrizCruz[2][i] = 5;
        matrizCruz[i][2] = 5;
    }

    // --- OCTAEDRO ---
    int centro = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - centro) + abs(j - centro) <= 2) {
                matrizOctaedro[i][j] = 7;
            }
        }
    }

    

    int coneLinha = 6 - 1;     
    int coneCol   = 'C' - 'A';  

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCone[i][j] != 0) {
                int L = coneLinha + (i - 2);
                int C = coneCol   + (j - 2);
                if (L >= 0 && L < 10 && C >= 0 && C < 10)
                    tabuleiro[L][C] = matrizCone[i][j];
            }
        }
    }

   
    int cruzLinha = 3 - 1;      
    int cruzCol   = 'C' - 'A'; 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCruz[i][j] != 0) {
                int L = cruzLinha + (i - 2);
                int C = cruzCol   + (j - 2);
                if (L >= 0 && L < 10 && C >= 0 && C < 10)
                    tabuleiro[L][C] = matrizCruz[i][j];
            }
        }
    }

   
    int octLinha = 7 - 1;      
    int octCol   = 'H' - 'A';  

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizOctaedro[i][j] != 0) {
                int L = octLinha + (i - 2);
                int C = octCol   + (j - 2);
                if (L >= 0 && L < 10 && C >= 0 && C < 10)
                    tabuleiro[L][C] = matrizOctaedro[i][j];
            }
        }
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

        printf("\n=== Habilidade em CONE ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%d ", matrizCone[i][j]);
        printf("\n");
    }

    printf("\n=== Habilidade em CRUZ ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%d ", matrizCruz[i][j]);
        printf("\n");
    }

    printf("\n=== Habilidade em OCTAEDRO ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%d ", matrizOctaedro[i][j]);
        printf("\n");
    }



    return 0;
}