#include <iostream>
#include <stdio.h>

int main() {
	char arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = 0; 
	for(int i = 0 ; i < 10; i++)
		if (arr[i] > max)
		{
			max = arr[i];
		}
	printf("%d", max)
		return 0;
}