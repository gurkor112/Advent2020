#include <stdio.h>
#define SEARCH 776203571
#include <limits.h>

int sought(int pos, int *list)
{
	int first = pos;
	int curr = 0;
	while(1)
	{
		curr += list[pos];
		if (curr > SEARCH) return 0;
		else if (curr == SEARCH)
		{
			int smallest = INT_MAX;
			int largest = INT_MIN;
			for (int i = first; i <= pos; ++i)
			{
				if (list[i] < smallest) smallest = list[i];
				if (list[i] > largest) largest = list[i];
			}
			return smallest + largest;
		}
	       pos++;	
	}


}

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
		int result = sought(pos, a);
		if (result)
		{
			printf("%d\n", result);
			break;
		}
		pos++;

	}
	fclose(f);

}
