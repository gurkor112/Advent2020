#include <stdio.h>
#include <stdlib.h>
#define SIZE 106

int comp(const void * left, const void* right)
{
	int *r = (int*)right;
	int *l = (int*)left;
	return *l - *r;
}

int main()
{
	FILE *f = fopen("input10", "r");


	int list[SIZE + 2];
	int pos = 1;
	while(1)
	{
		int temp;
		int res = fscanf(f, "%d", &temp);
		if (res == EOF) break;
		list[pos] = temp;
		++pos;
	}
	fclos(f);
	qsort(list + 1, SIZE, sizeof(int), comp);
	list[0] = 0;
	list[SIZE + 1] = list[SIZE] + 3;

	
	unsigned long ex[SIZE +2];

	for (int i = SIZE +1; i >= 0; --i)
	{
		ex[i] = 0;
		for (int u = i + 1; u < SIZE +2; ++u)
		{
			if (list[u] <= list[i] + 3)
			{
				ex[i] += ex[u];
			}
		}
		if (ex[i] == 0) ex[i] = 1;
	}
	printf("%lu \n", ex[0]);


}


/* 1 2 3 4 5 6 7
	1
	2
	4

 */

