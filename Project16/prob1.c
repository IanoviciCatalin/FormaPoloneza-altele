#include <stdio.h>
#include <stdlib.h>

char stack[100];
int vf = -1;

char stack1[100];
int vf1 = -1;

void push(char k) {
    stack[++vf] = k;
}

char pop() {
    return stack[vf--];
}

void push_stack2(char k) {
    stack1[++vf1] = k;
}

char pop_stack2() {
    return stack1[vf1--];
}

int main() {
    char s[100];
    int n;
    int count = 1;
    char count_char;

    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &n);

    printf("Introduceti caracterele: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);
    }

    //printf("rle.in: ");
    for (int i = 0; i < n; i++) {
        push(s[i]);
    }

    for (int i = vf; i >= 0; i--) {
        if (i > 0 && stack[i] == stack[i - 1]) {
            count++;
        }
        else {
            push_stack2(stack[i]);
            count_char = '0' + count;
            push_stack2(count_char);
            count = 1;
        }
    }

    printf("rle.out: ");
    for (int i = vf1; i >= 0; i--) {
        printf("%c", stack1[i]);
    }
    printf("\n");

    return 0;
}


//exercisem c track