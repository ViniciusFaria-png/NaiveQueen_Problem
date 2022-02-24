#include <stdbool.h>
#include <stdio.h>

#define N 4

//Funcao para printar a solucao
void printSolu(int tabu[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", tabu[i][j]);
        printf("\n");
    }
}

int checa(int tabu[N][N]) {
    int atq = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tabu[i][j] == 1) {
                //Ataque na linha
                for (int x = i + 1; x < N; x++) {
                    if (tabu[x][j] == 1) {
                        atq = 0;
                    }
                }
                for (int x = i - 1; x > 0; x--) {
                    if (tabu[x][j] == 1) {
                        atq = 0;
                    }
                }
                //Ataque na coluna
                for (int y = j + 1; y < N; y++) {
                    if (tabu[i][y] == 1) {
                        atq = 0;
                    }
                }
                for (int y = j - 1; y > 0; y--) {
                    if (tabu[i][y] == 1) {
                        atq = 0;
                    }
                }
                //Ataque na diagonal direita/baixo
                int y = j;
                for (int x = i + 1; x < N; x++) {
                    if (y + 1 == N) { break; }
                    else { y++; }
                    if (tabu[x][y] == 1) {
                        atq = 0;
                    }
                }
                y = j;
                for (int x = i + 1; x < N; x++) {
                    if (y - 1 == -1) { break; }
                    else { y--; }
                    if (tabu[x][y] == 1) {
                        atq = 0;
                    }
                }
                //Ataque na diagonal esquerda/baixo
                y = j;
                for (int x = i - 1; x > 0; x--) {
                    if (y + 1 == N) { break; }
                    else { y++; }
                    if (tabu[i][y] == 1) {
                        atq = 0;
                    }
                }
                y = j;
                for (int x = i - 1; x > 0; x--) {
                    if (y - 1 == -1) { break; }
                    else { y--; }
                    if (tabu[i][y] == 1) {
                        atq = 0;
                    }
                }
            }
        }
    }
    return atq;
}



int main()
{
    int tabu[N][N];
    int variavel = 0;
    int cont = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabu[i][j] = 0;
        }
    }

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = 0; d < N; d++) {
                    tabu[0][a] = 1;
                    tabu[1][b] = 1;
                    tabu[2][c] = 1;
                    tabu[3][d] = 1;
                    variavel = checa(tabu);
                    if (variavel == 1) {
                        printSolu(tabu);
                        printf("\n");
                    }
                    tabu[0][a] = 0;
                    tabu[1][b] = 0;
                    tabu[2][c] = 0;
                    tabu[3][d] = 0;
                }
            }
        }
    }
}

