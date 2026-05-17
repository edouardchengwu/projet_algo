#include <stdio.h>
void echanger(int *a, int *b) {
int temp = *a; *a = *b; *b = temp;
}
void afficher(int tab[], int n) {
printf("[");
for (int i = 0; i < n; i++) {
printf("%d", tab[i]);
if (i < n-1) printf(", ");
}
printf("]\n");
}
// debut = position actuelle qu'on est en train de fixer
void permutations(int tab[], int debut, int n) {
if (debut == n - 1) {
afficher(tab, n); // Cas de base : tout est fixé, afficher
return;
}
for (int i = debut; i < n; i++) {
echanger(&tab[debut], &tab[i]); // Fixer tab[i] à la position debut
permutations(tab, debut + 1, n); // Permuter le reste
echanger(&tab[debut], &tab[i]); // Backtrack : remettre en place
}
}
int main() {
int t[] = {1, 2, 3};
printf("Permutations de [1,2,3] :\n");
permutations(t, 0, 3); // 6 permutations
return 0;
}