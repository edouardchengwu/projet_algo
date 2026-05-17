#include <stdio.h>
// ■■ QUESTION 1 : Factorielle récursive ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
long long factoriel_rec(int n) {
if (n == 0) {
return 1;
}
return n * factoriel_rec(n - 1);
}
// ■■ QUESTION 2 : Factorielle itérative ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
long long factoriel_iter(int n) {
long long resultat = 1;
for (int i = 1; i <= n; i++) {
resultat = resultat * i;
}
return resultat;
}
int main() {
printf("0! = %lld\n", factoriel_rec(0)); // 1
printf("5! = %lld\n", factoriel_rec(5)); // 120
printf("10! = %lld\n", factoriel_rec(10)); // 3628800
printf("5! iter = %lld\n", factoriel_iter(5)); // 120
return 0;
}