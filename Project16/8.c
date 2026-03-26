#include <stdio.h>

int main() {
    int numar = 3;

    // Declara un array suficient de mare pentru a stoca reprezentarea binară
    int binaryNum[32];
    int i = 0;

    // Verificăm dacă numărul este diferit de zero
    if (numar != 0) {
        // Continuăm conversia în baza 2 până când numărul devine zero
        while (numar > 0) {
            binaryNum[i] = numar % 2;
            numar = numar / 2;
            i++;
        }
    }
    else {
        // Dacă numărul este 0, reprezentarea binară va fi doar 0
        binaryNum[i] = 0;
        i++;
    }

    // Afisează reprezentarea binară
    printf("Reprezentarea binara este: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
    printf("\n");

    return 0;
}
