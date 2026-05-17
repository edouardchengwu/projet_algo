#include <stdio.h>
// ■■ Récursif (Triangle de Pascal) ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
long long combinaison_rec(int n, int k) {
if (k == 0 || k == n) {
return 1;
}
return combinaison_rec(n-1, k-1) + combinaison_rec(n-1, k);
}
// ■■ Itératif ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
long long combinaison_iter(int n, int k) {
long long resultat = 1;
for (int i = 0; i < k; i++) {
resultat = resultat * (n - i) / (i + 1);
}
return resultat;
}
int main() {
printf("C(4,2) rec = %lld\n", combinaison_rec(4, 2)); // 6
printf("C(5,3) rec = %lld\n", combinaison_rec(5, 3)); // 10
printf("C(10,3) iter = %lld\n", combinaison_iter(10, 3)); // 120
return 0;
}