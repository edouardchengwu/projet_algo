#include <stdio.h>

long long combinaison(int n, int k) {
    if (k == 0 || k == n) return 1;
    return combinaison(n - 1, k - 1) + combinaison(n - 1, k);
}

int main() {
    
    printf("C(4, 2) = %lld\n", combinaison(4, 2)); // Doit afficher 6
    printf("C(5, 3) = %lld\n", combinaison(5, 3)); // Doit afficher 10
    
    return 0;
}