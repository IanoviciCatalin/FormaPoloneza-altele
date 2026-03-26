#include <stdio.h>
#include <stdlib.h>
char stack[100];
int vf = -1;
char stack1[100];
int vf1 = -1;

void push(char k)
{
    stack[++vf] = k;
}
char pop()
{
    return stack[vf--];
}

void push_stack2(int k)
{
    stack1[++vf1] = k;
}

char pop_stack2()
{
    return stack1[vf1--];
}



int main() {
    char s[100];
    int n;
    int count = 1;
    printf("introduceti dimensiunea vectorului: ");
        scanf("%d", &n);
    printf("introduceti elemente: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", &s[i]);
        push(s[i]);
    }
    for (int i = vf; i >= -1; i--)
    {
        if (stack[i] == stack[i - 1])
        {
            count++;
        }
        else {
            push_stack2(stack[i]);
            push_stack2(count);
            count = 1;
        }

    }
    for (int i = vf1; i > -1; i -= 2) 
    {
        printf("%d", stack1[i]);
        printf("%c", stack1[i - 1]);
    }
    printf("\n");

    for (int i = vf1; i > -1; i -= 2)
    {
        for (int j = stack1[i]; j > 0; j--)
        {
            printf("%c", stack1[i - 1]);
        }
    }
    return 0;
}