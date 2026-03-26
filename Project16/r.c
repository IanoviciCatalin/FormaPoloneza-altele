#include<stdio.h>
#include<math.h>
int a[30], count = 0;// vectorul solutiile si contorul ( vectorul reprezinta linia reginei)
// row=index
// column=value i=row a[i]=column
int place(int pos)
{
	int i;
	for (i = 1; i < pos; i++)
	{
		if ((a[i] == a[pos]) || ((abs(a[i] - a[pos]) == abs(i - pos))))
			return 0;
	}
	return 1;
}
void print_sol(int N)
{
	int i, j;
	count++;
	printf("\nSolution #%d: \n", count);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (a[i] == j)
				printf("Q\t");
			else
				printf("*\t");
		}
		printf("\n");
	}
}
void queen(int N)
{
	int k = 1;
	a[k] = 0;
	while (k != 0)
	{
		do
		{
			a[k]++;
		} while ((a[k] <= N) && !place(k));
		if (a[k] <= N)
		{
			if (k == N)
				print_sol(N);
			else
			{
				k++;
				a[k] = 0;
			}
		}
		else
			k--;
	}
}



int main()
{
	int N; // nr de regine
	printf("Numbers of queens: "); scanf("%d", &N);
	queen(N);
	printf("\nTotal solutions=%d", count);





	return 0;
}