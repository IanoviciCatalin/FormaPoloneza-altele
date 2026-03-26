#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char fp[100];
int count = 0;

char st[100];
int vf = -1;

void push(char k)
{
    st[++vf] = k;
}

char pop(void)
{
    return st[vf--];
}

char top(void)
{
    if (vf == -1) return 0;
    return st[vf];
}

int test3(void);
int test2(void);
int test1(void);

int prioritate(char c)
{
    if (c == '(') return 0;
    if (c == ')') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}

int forma_poloneza(char* expresie, char* rezultat)
{
    int i;
    int prio;

    for (i = 0; expresie[i] != '\0'; i++)
    {
        prio = prioritate(expresie[i]);

        if (expresie[i] == ' ')
        {
            continue;
        }
        if (prio == -1)
        {
            fp[count++] = expresie[i];
        }
        else if (expresie[i] == '(')
        {
            push(expresie[i]);
        }
        else if (expresie[i] == ')')
        {
            while (vf != -1 && top() != '(')
            {
                fp[count++] = pop();
            }
            pop();
        }
        else
        {
            while (vf != -1 && prioritate(top()) >= prio)
            {
                fp[count++] = pop();
            }
            push(expresie[i]);
        }
    }

    while (vf != -1)
    {
        fp[count++] = pop();
    }

    fp[count] = '\0';

    strcpy(rezultat, fp);

    printf("Expresia rezultata: %s\n", rezultat);

    count = 0;
    vf = -1;

    return 0;
}

int main()
{
    int err = 0;
    err |= test3();
    err |= test2();
    err |= test1();

    return err;
}

int test1(void)
{
    char* str = "(a * (b - c) + d / (e + f * h) - i) + 5";
    char* asteptat = "abc-*defh*+/+i-";
    char output[100];
    (void)forma_poloneza(str, output);

    printf("Test1 - Output obtinut: %s\n", output);

    if (strcmp(output, asteptat) != 0)
    {
        printf("Test1 Esuat! Obtinut: %s, Asteptat: %s\n", output, asteptat);
        return 1;
    }
    return 0;
}

int test2(void)
{
    char* str = "(1+1)";
    char* asteptat = "11+";
    char output[100];
    (void)forma_poloneza(str, output);

    printf("Test2 - Output obtinut: %s\n", output);

    if (strcmp(output, asteptat) != 0)
    {
        printf("Test2 Esuat! Obtinut: %s, Asteptat: %s\n", output, asteptat);
        return 1;
    }
    return 0;
}

int test3(void)
{
    char* str = "(a + b)* (c - d)";
    char* asteptat = "ab+cd-*";
    char output[100];
    (void)forma_poloneza(str, output);

    printf("Test3 - Output obtinut: %s\n", output);

    if (strcmp(output, asteptat) != 0)
    {
        printf("Test3 Esuat! Obtinut: %s, Asteptat: %s\n", output, asteptat);
        return 1;
    }
    return 0;
}
