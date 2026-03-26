#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int* arr, int start, int end) {
    if (start == end) {
        printf("%d%d%d%d\n", arr[0], arr[1], arr[2], arr[3]);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);
        permute(arr, start + 1, end);
        swap(&arr[start], &arr[i]);
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    permute(arr, 0, n - 1);

    return 0;
}

/*
for (int i = 0; i <= vf; i += 2) {
    char character = stack[i];       // Caracterul curent
    int count = stack[i + 1] - '0';  // Numărul de apariții

    // Adăugarea caracterului în stiva de rezultat de `count` ori
    for (int j = 0; j < count; j++) {
        push_stack2(character);
    }
}
*/