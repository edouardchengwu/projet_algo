#include <stdio.h>
// ■■ Récursif (algorithme d'Euclide) ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
int pgcd_rec(int a, int b) {
if (b == 0) {
return a;
}
return pgcd_rec(b, a % b);
}
// ■■ Itératif (avec while) ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
int pgcd_iter(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}
int main() {
printf("PGCD(48, 18) rec = %d\n", pgcd_rec(48, 18)); // 6
printf("PGCD(100, 75) rec = %d\n", pgcd_rec(100, 75)); // 25
printf("PGCD(48, 18) iter = %d\n", pgcd_iter(48, 18)); // 6
return 0;
}