#include <stdio.h>


int main()
{
	FILE *f = fopen("input5", "r");


	int ret;
	int taken[1024] = {0};
	char input[10];
	int pos;
	int max, min;
	int cmax, cmin;
	int toPrint = 0;
	while (1)
	{
		max = 127;
		min = 0;
		cmax = 7;
		cmin = 0;
		ret = fscanf(f,"%s", input);

		if (ret == EOF)
		{
			break;
		}

		for (int i = 0; i < 7; ++i)
		{
			if (input[i] == 'F') max = (max+min)/2;
			else min = (max + min) / 2 + 1;
		}
		for (int i = 7; i < 10; ++i)
		{
			if (input[i] == 'L') cmax = (cmax+cmin)/2;
			else cmin = (cmax + cmin) / 2 + 1;
		}
		taken[min*8 + cmin] = 1;
	}

	int i = 0;
	while (taken[i] != 1) i++;
	while (taken[i] == 1) i++;
	printf("%d\n", i);
}