#include <stdio.h>
// Fonction interne (ne pas appeler directement pour n = 0)
int nb_chiffres_rec(int n) {
if (n < 10) {
return 1;
}
return 1 + nb_chiffres_rec(n / 10);
}
// Fonction publique : corrige le cas n = 0
int nb_chiffres_rec_final(int n) {
if (n == 0) {
return 1;
}
return nb_chiffres_rec(n);
}
// Version itérative
int nb_chiffres_iter(int n) {if (n == 0) return 1;
int count = 0;
while (n > 0) {
count++;
n = n / 10;
}
return count;
}
int main() {
printf("%d chiffre(s)\n", nb_chiffres_rec_final(0)); // 1
printf("%d chiffre(s)\n", nb_chiffres_rec_final(7)); // 1
printf("%d chiffre(s)\n", nb_chiffres_rec_final(1234)); // 4
printf("%d chiffre(s)\n", nb_chiffres_iter(9999)); // 4
return 0;
}