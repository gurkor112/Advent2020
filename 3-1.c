#include <stdio.h>

int main()
{
	FILE* f = fopen("input3", "r");

	char s[31];

	int count3 = 0;
	int pos3 = 0;
	int pos1 = 0;
	int count1 = 0;
	int count5 = 0;
	int pos5 = 0;
	int count7 = 0;
	int pos7 = 0;
	int count12 = 0;
	int pos12 = 0;

	for (int i = 0; i < 323; ++i)
	{
		fscanf(f, "%s", s);
		if (s[pos3] == '#') count3++;
		pos3 = (pos3 + 3) % 31;

		if (s[pos1] == '#') count1++;
		pos1 = (pos1 + 1 )%31;
		if (s[pos7] == '#') count7++;
		pos7 = (pos7 + 7) % 31;

		if (i%2 == 0)
		{
			if (s[pos12] == '#') count12++;
			pos12 = (pos12 + 1) % 31;
		} 
		if (s[pos5] == '#') count5++;
		pos5 = (pos5 + 5)%31;
	}
	printf("%d\n%d\n%d\n%d\nn%d\nn%d\n", count1, count12, count3, count5, count7);

}