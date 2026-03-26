#include <stdlib.h>
#include <stdio.h>

int cardinal(int n) {
	int k[10], m,o,i;
	/*for (int i = 0; i < 4; i++)
	{
		k[i] = n % 10;
		n = n / 10;
		m = k[i]+n;
		printf("%d\n", m);
		//printf("%d", o);
		printf("%d\n", n);
		return m;
	}*/
	while (n != 0) {
		for (i = 0; i < n; i++) {
			k[i] = n % 10;
			n = n / 10;
			m = k[i] + n;
			return m;
		}
	}
}

int main() {

	int n;
	printf("Introduceti numarul pentru care va doriti cardinalul: ");
	scanf("%d", &n);
	printf("%d\n", cardinal(n));
	system("pause");
	return 0;
}