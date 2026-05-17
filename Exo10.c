#include <stdio.h>
// Reprend somme_rec de l'exercice 6
int somme_rec(int tab[], int n) {
if (n == 0) return 0;
return tab[0] + somme_rec(tab + 1, n - 1);
}
// ■■ Récursif ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
double moyenne_rec(int tab[], int n) {
if (n == 0) return 0.0;
return (double)somme_rec(tab, n) / n;
}
// ■■ Itératif ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
double moyenne_iter(int tab[], int n) {
if (n == 0) return 0.0;
double somme = 0;
for (int i = 0; i < n; i++) {
somme += tab[i];
}
return somme / n;
}
int main() {
int t[] = {2, 4, 6, 8, 10};
printf("Moyenne rec = %.2f\n", moyenne_rec(t, 5)); // 6.00
printf("Moyenne iter = %.2f\n", moyenne_iter(t, 5)); // 6.00
return 0;
}