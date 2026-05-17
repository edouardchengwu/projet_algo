#include <stdio.h>
// ■■ Récursif : affiche le binaire de n ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
void binaire_rec(int n) {
if (n < 2) {
printf("%d", n);
return;
}
binaire_rec(n / 2); // Afficher d'abord les bits de gauche
printf("%d", n % 2); // Puis le bit actuel (le moins significatif)
}
// ■■ Itératif (avec while) ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
void binaire_iter(int n) {
if (n == 0) { printf("0"); return; }
char bits[64];
int i = 0;
while (n > 0) {
bits[i++] = '0' + (n % 2); // Stocker '0' ou '1'
n = n / 2;
}
for (int j = i - 1; j >= 0; j--) {
printf("%c", bits[j]); // Afficher en ordre inverse
}
}
int main() {
printf("13 en binaire rec : "); binaire_rec(13); printf("\n"); // 1101
printf("13 en binaire iter : "); binaire_iter(13); printf("\n"); // 1101
printf("255 en binaire : "); binaire_rec(255); printf("\n"); // 11111111
return 0;
}