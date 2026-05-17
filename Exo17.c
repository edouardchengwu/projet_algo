#include <stdio.h>
#include <stdbool.h>
// Prototype nécessaire : est_pair utilise est_impair avant sa définition
bool est_impair(int n);
bool est_pair(int n) {
if (n == 0) return true; // 0 est pair
return est_impair(n - 1); // n est pair si n-1 est impair
}
bool est_impair(int n) {
if (n == 0) return false; // 0 n'est pas impair
return est_pair(n - 1); // n est impair si n-1 est pair
}
// ■■ Versions itératives ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
bool est_pair_iter(int n) { return n % 2 == 0; }
bool est_impair_iter(int n) { return n % 2 != 0; }
int main() {
printf("est_pair(4) = %d\n", est_pair(4)); // 1 (vrai)
printf("est_impair(7) = %d\n", est_impair(7)); // 1 (vrai)
printf("est_pair(3) = %d\n", est_pair(3)); // 0 (faux)
return 0;
}