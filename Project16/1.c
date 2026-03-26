//#include <stdio.h>
//
//int main()
//{
//	char a;
//	int* p = (&a + 1);
//	printf("%d", (char*)p - (char*)(&a));
//	return 0;
//}

#define my_sizeof(tip) ((tip*)0+1)
#include <stdio.h>
int main()
{
	printf("%d\n", my_sizeof(int));
	printf("%d\n", my_sizeof(float));
	printf("%d\n", my_sizeof(char));
	printf("%d\n", my_sizeof(long));
}