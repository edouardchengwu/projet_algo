#include <stdio.h>
// ■■ Récursif ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
int somme_rec(int tab[], int n) {
if (n == 0) {
return 0; // Tableau vide : somme = 0
}
return tab[0] + somme_rec(tab + 1, n - 1);
}
// ■■ Itératif (avec while comme demandé) ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
int somme_iter(int tab[], int n) {
int somme = 0;
int i = 0;
while (i < n) {
somme = somme + tab[i];
i++;
}
return somme;
}
int main() {
int t[] = {1, 2, 3, 4, 5};
printf("Somme rec = %d\n", somme_rec(t, 5)); // 15
printf("Somme iter = %d\n", somme_iter(t, 5)); // 15
return 0;
}