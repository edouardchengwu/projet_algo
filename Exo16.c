#include <stdio.h>
#include <stdbool.h>

bool absentSurLigne(int k, int g[9][9], int i) {
    for (int j = 0; j < 9; j++)
        if (g[i][j] == k) return false;
    return true;
}

bool absentSurColonne(int k, int g[9][9], int j) {
    for (int i = 0; i < 9; i++)
        if (g[i][j] == k) return false;
    return true;
}

bool absentSurBloc(int k, int g[9][9], int li, int lj) {
    int di = (li/3)*3, dj = (lj/3)*3;
    for (int i = di; i < di+3; i++)
        for (int j = dj; j < dj+3; j++)
            if (g[i][j] == k) return false;
    return true;
}

bool estValide(int grille[9][9], int position) {
    if (position == 9*9) return true; // Toutes les cases remplies !
    int i = position / 9, j = position % 9;
    
    if (grille[i][j] != 0) // Case déjà remplie
        return estValide(grille, position + 1);
        
    for (int k = 1; k <= 9; k++) {
        if (absentSurLigne(k, grille, i) &&
            absentSurColonne(k, grille, j) &&
            absentSurBloc(k, grille, i, j)) {
            
            grille[i][j] = k;
            if (estValide(grille, position + 1)) return true;
            grille[i][j] = 0; // BACKTRACK : bonne place, dans la boucle !
        }
    }
    return false;
}

// Fonction utilitaire pour afficher proprement la grille dans le terminal
void afficherGrille(int g[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) printf("---------------------\n");
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) printf("| ");
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}


int main() {
    // Une grille de Sudoku d'exemple (0 représente les cases vides)
    int grille[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("--- Grille originale ---\n");
    afficherGrille(grille);
    printf("\n");

    // Résolution à partir de la position 0
    if (estValide(grille, 0)) {
        printf("--- Grille resolue ---\n");
        afficherGrille(grille);
    } else {
        printf("Pas de solution possible pour cette grille.\n");
    }

    return 0;
}