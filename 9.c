#include <stdio.h>


int inside(int pos, int s,int*list)
{
	int end = pos + 25;
	for (int i = pos; i < end; ++i)
	{
		for (int u = i + 1; u < end; ++u)
		{
			if (list[i] + list[u] == s) return 1;
		}
	}	
	return 0;
}

int main()
{
	FILE *f = fopen("input9", "r");

	int a[1000];
	int pos = 0;
	int temp;
	while(1)
	{
		int ret = fscanf(f, "%d", &temp);
		if (ret == EOF) break;
		a[pos] = temp;
		pos++;
	}
	pos = 0;
	while(1)
	{
		if (!inside(pos, a[pos +25], a)) break;
		pos++;
	}
	printf("%d\n", a[pos + 25]);
	fclose(f);

}
