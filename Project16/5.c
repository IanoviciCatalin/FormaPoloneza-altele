char st[100];
int vf = -1;


void formaPoloneza(char* exp, char* rez) {
	int prioritate;
	char arr[100];
	int count = 0;
	for (int i = 0; i != "\0"; i++)
	{
		switch (exp[i])
		{
		case 0:exp[i] == '(' || exp[i] == ')';
		case 1:exp[i] == '*' || exp[i] == '/';
		case 2:exp[i] == '+' || exp[i] == '-';

		}
	}
}

void test1() {
	char test1[] = ("a+b");
}

//pt operanzi
char fp[100];
int count = 0;

//pt operatori
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
    return st[vf];
}

//testele noastre, definite mai jos sub main
int test3(void);
int test2(void);
int test1(void);


int prioritate(char c)
{
    int retVal = -1; //daca ii operand ii zicem -1, si putem refolosi functia
    if ((c == '(') || (c == ')'))
    {
        retVal = 0;
    }
    else if ((c == '*') || (c == '/'))
    {
        retVal = 1;
    }
    else if ((c == '+') || (c == '-'))
    {
        retVal = 2;
    }

    return retVal;
}

int forma_poloneza(char* expresie, char* rezultat)
{
    int ii;
    int prio = -1;

    for (ii = 0; expresie[ii] != '\0'; ii++)
    {
        prio = prioritate(expresie[ii]);

        if (expresie[ii] == 0x20) //spatiu ii ignorat
        {
            continue;
        }
        //pas redundant
        if (prio == -1)
        {
            //ii operand
            fp[count++] = expresie[ii];
        }
        else
        {
            //ii operator
            push(expresie[ii]);
        }


        //procesare stiva

        if (prio == 2)
        {
            char vechiul_top = pop();

            while (prioritate(top()) == 1)
            {
                fp[count++] = pop();
            }

            push(vechiul_top);
        }

        if (top() == ')')
        {
            pop(); //scoatem )
            while (top() != '(')
            {
                fp[count++] = pop();
            }
            pop(); // scoatem (

        }
    }

    //stiva poate sa contina chestii: de ce ?
    if (vf != -1)
    {
        fp[count++] = pop();
    }

    for (int kk = 0; kk < count; kk++)
    {
        //copiem in rezultat
        rezultat[kk] = fp[kk];
    }

    //reset stiva si array
    count = 0;
    vf = -1;


    return 0;
}



int main()
{

    //testele noastre, daca err ii 1, avem o eroare
    int err = 0;
    err |= test3();
    err |= test2();
    err |= test1();

    return err;
}



int test1(void)
{
    char* str = "(a * (b - c) + d / (e + f * h) - i)";
    char* asteptat = "abc-*defh*+/i-+";
    char output[100];
    (void)forma_poloneza(&str[0], &output[0]);

    //testam ca am primit ce ne dorim
    for (int ii = 0; asteptat[ii] != '\0'; ii++)
    {
        if (asteptat[ii] != output[ii])
        {
            return 1;
        }
    }

    return 0;

}

int test2(void)
{
    char* str = "(a+b)";
    char* asteptat = "ab+";
    char output[100];
    (void)forma_poloneza(&str[0], &output[0]);

    //testam ca am primit ce ne dorim
    for (int ii = 0; asteptat[ii] != '\0'; ii++)
    {
        if (asteptat[ii] != output[ii])
        {
            return 1;
        }
    }
    return 0;
}

//test cu greseala in el, nu trebuie sa returneze 0
int test3(void)
{
    char* str = "(a + b)* (c - d)";
    char* asteptat = "ab+";
    char output[100];
    (void)forma_poloneza(&str[0], &output[0]);

    //testam ca am primit ce ne dorim
    for (int ii = 0; asteptat[ii] != '\0'; ii++)
    {
        if (asteptat[ii] != output[ii])
        {
            return 1;
        }
    }
    return 0;
}