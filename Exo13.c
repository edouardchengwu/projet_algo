#include <stdio.h>
// ■■ Récursif ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
long long arrangement_rec(int n, int k) {
if (k == 0) return 1;
return n * arrangement_rec(n - 1, k - 1);
}
// ■■ Itératif ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
long long arrangement_iter(int n, int k) {
long long resultat = 1;
for (int i = 0; i < k; i++) {
resultat *= (n - i); // n * (n-1) * ... * (n-k+1)
}
return resultat;
}
int main() {
printf("A(5,3) rec = %lld\n", arrangement_rec(5, 3)); // 60
printf("A(10,2) iter = %lld\n", arrangement_iter(10, 2)); // 90
return 0;
}