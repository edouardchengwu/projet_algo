include <stdio.h>
// ■■ QUESTION 1 : Puissance linéaire récursive ■■■■■■■■■■■■■■■■■■■■■■■■
long long puissance_lineaire(long long x, int n) {
if (n == 0) {
return 1;
}
return x * puissance_lineaire(x, n - 1);
}
// ■■ QUESTION 2 : Puissance rapide récursive ■■■■■■■■■■■■■■■■■■■■■■■■■■
long long puissance_rapide(long long x, int n) {
if (n == 0) {
return 1;
}
if (n % 2 == 0) {
long long moitie = puissance_rapide(x, n / 2);
return moitie * moitie;
}
return x * puissance_rapide(x, n - 1);
}
int main() {
// Tests question 1
printf("2^10 lineaire = %lld\n", puissance_lineaire(2, 10)); // 1024
printf("3^5 lineaire = %lld\n", puissance_lineaire(3, 5)); // 243
// Tests question 2
printf("2^10 rapide = %lld\n", puissance_rapide(2, 10)); // 1024
printf("3^5 rapide = %lld\n", puissance_rapides(3, 5)); // 243
return 0;
}