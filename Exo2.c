#include <stdio.h>
// ■■ QUESTION 1 : Puissance linéaire itérative ■■■■■■■■■■■■■■■■■■■■■■■■
long long puissance_lineaire_iter(long long x, int n) {
long long resultat = 1;
for (int i = 0; i < n; i++) {
resultat = resultat * x;
}
return resultat;
}
// ■■ QUESTIONS 2 & 3 : Puissance rapide itérative ■■■■■■■■■■■■■■■■■■■■■
// Utilise les bits de l'exposant (algorithme des doubles et additions)
long long puissance_rapide_iter(long long x, int n) {
long long resultat = 1;
while (n > 0) {
if (n % 2 == 1) {
resultat = resultat * x;
}
x = x * x;
n = n / 2;
}
return resultat;
}
int main() {
printf("2^10 lin iter = %lld\n", puissance_lineaire_iter(2, 10)); // 1024
printf("3^5 lin iter = %lld\n", puissance_lineaire_iter(3, 5)); // 243
printf("2^10 rap iter = %lld\n", puissance_rapide_iter(2, 10)); // 1024
printf("3^5 rap iter = %lld\n", puissance_rapide_iter(3, 5)); // 243
return 0;
}