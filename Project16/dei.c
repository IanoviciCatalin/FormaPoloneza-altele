#include <stdio.h>
#include <stdlib.h>
int a[20] = {76,12,32,41,22,2324};

int DI(int li, int ls) {
	int x, y;
	if (li < ls) {
		x = DI(li, (li + ls) / 2);
		y = DI((li + ls)/2 + 1, ls);
		if (x < y) return y;
		else return x;
	}
	else
		return a[li];
}

int main() {
	for (int i = 0; i < 20; i++) {
		printf("%d\n", a[i]);
	}
	int n= 20;
	printf("%d", DI(0, 19));
}



//#include <stdio.h>
//#include <stdlib.h>
//
//int DI(int* arr, int li, int ls) {
//    if (li == ls) {
//        return arr[li];
//    }
//    int mijloc = (li + ls) / 2;
//    int x = DI(arr, li, mijloc);
//    int y = DI(arr, mijloc + 1, ls);
//    return (x < y) ? y : x;
//}
//
//int main() {
//    int arr[20];
//    for (int i = 0; i < 20; i++) {
//        arr[i] = rand() % 100; // Inițializăm elementele cu valori aleatorii
//    }
//    for (int i = 0; i < 20; i++) {
//        printf("%d ", arr[i]); // Afișăm array-ul inițial
//    }
//    printf("\nMaximul este: %d\n", DI(arr, 0, 19));
//    return 0;
//}
