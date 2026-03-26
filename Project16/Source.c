#include <stdio.h>

// Funcție pentru a calcula factorialul unui număr
unsigned long long factorial(int num) {
    if (num == 0 || num == 1) // Dacă numărul este 0 sau 1, factorialul este 1
        return 1;
    unsigned long long result = 1; // Inițializăm rezultatul ca 1
    for (int i = 2; i <= num; ++i) // Începem de la 2 și mergem până la num
        result *= i; // Înmulțim rezultatul curent cu i
    return result; // Returnăm rezultatul final
}

// Funcție pentru a calcula combinațiile C(n, k)
unsigned long long combinari(int n, int k) {
    if (k > n) // Dacă k este mai mare decât n, nu putem face combinații
        return 0;
    unsigned long long n_factorial = factorial(n); // Calculăm n!
    unsigned long long k_factorial = factorial(k); // Calculăm k!
    unsigned long long n_k_factorial = factorial(n - k); // Calculăm (n-k)!
    return n_factorial / (k_factorial * n_k_factorial); // Aplicăm formula C(n, k) = n! / (k! * (n-k)!)
}

int main() {
    int n, k; // Declarăm variabilele pentru n și k
    printf("Introduceti valoarea lui n: "); // Cerem utilizatorului să introducă valoarea lui n
    scanf("%d", &n); // Citim valoarea lui n de la utilizator
    printf("Introduceti valoarea lui k: "); // Cerem utilizatorului să introducă valoarea lui k
    scanf("%d", &k); // Citim valoarea lui k de la utilizator

    if (k < 0 || n < 0) { // Verificăm dacă n sau k sunt numere negative
        printf("n si k trebuie sa fie numere pozitive.\n"); // Afișăm un mesaj de eroare
        return 1; // Ieșim din program cu un cod de eroare
    }

    unsigned long long result = combinari(n, k); // Calculăm combinațiile C(n, k)
    printf("C(%d, %d) = %llu\n", n, k, result); // Afișăm rezultatul

    return 0; // Ieșim din program cu codul 0 (succes)
}
