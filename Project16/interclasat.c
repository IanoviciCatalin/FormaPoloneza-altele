#include <stdio.h>
#include <stdlib.h>

int a[20] = { 76,12,32,41,22,2324 };
int x[] = { 1, 2, 3 };
int y[] = { 4,5,6 };

void merge(int li,  int ls) {
	int i, j, k, m[100], c = 0;
	i = li, k = (li + ls) + 2; j = k + 1;
	while (i <= k && j <= ls) {
		if (a[i] < a[j])
			m[c++] = a[i++];
		else
			m[c++] = a[j++];
	}
	while (i <= k) m[c++] = a[i++];
	while (j <= ls) m[c++] = a[j++];
	for (i = li; i <= ls;i++) {
		a[i] = m[i - li];
	}
}

int main() {
	for (int i = 0; i < 20; i++) {
		printf("%d\n", a[i]);
	}
	int n = 20;
	printf("%d", merge(x, y));
}
