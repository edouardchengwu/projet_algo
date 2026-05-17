#include <stdio.h>
// ■■ Récursif ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
int maximum_rec(int tab[], int n) {
if (n == 1) {
return tab[0]; // Un seul élément : c'est forcément le max
}
int max_reste = maximum_rec(tab + 1, n - 1);
// Condition ternaire : (condition) ? valeur_si_vrai : valeur_si_faux
return (tab[0] > max_reste) ? tab[0] : max_reste;
}
// ■■ Itératif (avec while comme demandé) ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
int maximum_iter(int tab[], int n) {
int max = tab[0];
int i = 1;
while (i < n) {
if (tab[i] > max) {
max = tab[i];
}
i++;
}
return max;
}
int main() {
int t[] = {3, 1, 7, 2, 9, 5};
printf("Max rec = %d\n", maximum_rec(t, 6)); // 9
printf("Max iter = %d\n", maximum_iter(t, 6)); // 9
return 0;
}