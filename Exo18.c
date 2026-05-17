#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
const char *expr; // Pointeur global sur la chaine à analyser
double evalExpression();
double evalTerme();
double evalFacteur();
// Niveau 3 : nombres et parenthèses
double evalFacteur() {
double resultat;
if (*expr == '(') {
expr++; // Sauter '('
resultat = evalExpression();
expr++; // Sauter ')'
} else {
resultat = strtod(expr, (char**)&expr); // Lire le nombre
}
return resultat;
}
// Niveau 2 : multiplication et division (priorité haute)
double evalTerme() {
double resultat = evalFacteur();
while (*expr == '*' || *expr == '/') {
char op = *expr++;
double suivant = evalFacteur();
if (op == '*') resultat *= suivant;
else resultat /= suivant;
}
return resultat;
}
// Niveau 1 : addition et soustraction (priorité basse)
double evalExpression() {
double resultat = evalTerme();
while (*expr == '+' || *expr == '-') {
char op = *expr++;
double suivant = evalTerme();
if (op == '+') resultat += suivant;
else resultat -= suivant;
}
return resultat;
}
int main() {
const char *tests[] = {"3+5*2", "(3+5)*2", "10/2+3", "2*(3+4*2)"};
for (int i = 0; i < 4; i++) {
expr = tests[i];
printf("%s = %.2f\n", tests[i], evalExpression());
}
// 3+5*2=13 | (3+5)*2=16 | 10/2+3=8 | 2*(3+4*2)=22
return 0;
}