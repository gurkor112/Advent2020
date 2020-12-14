#include <stdio.h>

typedef struct seat{
	int now;
	int last;
	char c;
} seat_t;


int same(seat_t m[90][91])
{
	int toReturn = 1;
	for (int i = 0; i < 90; ++i)
	{
		for (int u = 0; u < 91; ++u)
		{
			if (m[i][u].last != m[i][u].now)
			{
				toReturn = 0;
			}
			m[i][u].last = m[i][u].now;
		}
	}
	printf("AAA\n");
	return toReturn;
}

int main()
{
	seat_t m[90][91];

	FILE *f = fopen("input11", "r");

	for (int i = 0; i < 90; ++i)
	{
		for (int u = 0; u < 91; ++u)
		{
			m[i][u].now = 0;
			m[i][u].last = 0;
		}
	}

	m[1][0].last = 1;

	int pos = 0;
	char list[91];
	while (1)
	{
		int res = fscanf(f, "%s", list);

		if (res == EOF) break;

		for (int i = 0; i < 91; ++i)
		{
			m[pos][i].c = list[i];
		}
		++pos;
	}

	while(!same(m))
	{
		for (int i = 0; i < 90; ++i)
		{
			for (int u = 0; u < 91; ++u)
			{
				if (m[i][u].c != 'L') continue;
				int count = 0;
				
				for (int x = -1; x < 2; ++x)
				{
					for (int y = -1; y < 2; ++y)
					{
						if (!y && !x) continue;
						int difx = x;
						int dify = y;
						int loop = 1;
						while(loop)
						{
							if (difx + u < 91 && difx + u >= 0 && dify + i < 90 && dify + i >= 0)
							{
								if (m[dify + i][difx +u].last == 1) count++;
								if (m[dify + i][difx +u].c == 'L') loop = 0;
							}
							else loop = 0;
							dify += y;
							difx += x;
						}
					}
				}


				if (m[i][u].last == 1 && count >= 5)
				{
					printf("what\n");
					m[i][u].now = 0;	
				} 
				else if(!count)
				{	
					m[i][u].now = 1;
				}
				else
				{
					m[i][u].now = m[i][u].last;
				}
				
			}
		}
	}

	int toPrint = 0;
	for (int i = 0; i < 90; ++i)
	{
		for (int u = 0; u < 91; ++u)
		{
			toPrint += m[i][u].last;
		}
	}

	printf("%d\n", toPrint);
	fclose(f);


}
