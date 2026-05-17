#include <stdio.h>
// ■■ Récursif (simple mais lent pour grands n) ■■■■■■■■■■■■■■■■■■■■■■■■■
long long fib_rec(int n) {
if (n == 0) return 0;
if (n == 1) return 1;
return fib_rec(n - 1) + fib_rec(n - 2);
}
// ■■ Itératif (rapide, recommandé) ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
long long fib_iter(int n) {
    if (n == 0) return 0;
long long a = 0, b = 1;
for (int i = 2; i <= n; i++) {
long long temp = a + b;
a = b;
b = temp;
}
return b;
}
int main() {
for (int i = 0; i <= 10; i++) {
printf("fib(%2d) = %lld\n", i, fib_rec(i));
}
// 0 1 1 2 3 5 8 13 21 34 55
printf("fib(50) iter = %lld\n", fib_iter(50)); // 12586269025
return 0;
}