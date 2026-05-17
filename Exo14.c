#include <stdio.h>
#include <stdlib.h>
// ■■ Version récursive ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
void hanoi_rec(int n, char source, char dest, char auxiliaire) {
if (n == 0) return;
hanoi_rec(n-1, source, auxiliaire, dest);
printf("Disque %d : %c -> %c\n", n, source, dest);
hanoi_rec(n-1, auxiliaire, dest, source);
}
// ■■ Version itérative avec pile ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
typedef struct { int n; char src, dst, aux; } Etat;
void hanoi_iter(int n, char A, char C, char B) {
Etat pile[10000];
int top = 0;
pile[top++] = (Etat){n, A, C, B};
while (top > 0) {
Etat e = pile[--top];
if (e.n == 0) continue;
pile[top++] = (Etat){e.n-1, e.aux, e.dst, e.src};
printf("Disque %d : %c -> %c\n", e.n, e.src, e.dst);
pile[top++] = (Etat){e.n-1, e.src, e.aux, e.dst};
}
}
int main() {
printf("=== Recursif (n=3) ===\n");
hanoi_rec(3, 'A', 'C', 'B'); // 7 mouvements
printf("\n=== Iteratif (n=3) ===\n");
hanoi_iter(3, 'A', 'C', 'B'); // meme resultat
return 0;
}