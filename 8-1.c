#include <stdio.h>
#include <ctype.h>

typedef struct in{
	int value;
	char opcode;
	int first;
} in_t;


int try(in_t *ins, int i)
{
	int toReturn = 0;
	while (i < 636)
	{
		if (ins[i].first)
		{
			for (int i = 0; i < 636; ++i) ins[i].first = 0;
			return 0;
		}
		else ins[i].first = 1;

		if (ins[i].opcode == 'j')
		{
			if (i == 630) i++;
			else i += ins[i].value;
		}
		else if (ins[i].opcode == 'a')
		{
			toReturn += ins[i].value;
			++i;
		} 
		else
		{
			i++;
		}
	}
	return toReturn;
}

int main()
{
	FILE *f = fopen("input8", "r");

	in_t ins[636];
	int value;
	char input[4];
	int i = 0;
	while (1)
	{
		int ret = fscanf(f, "%s %d", input, &value);
		if (ret == EOF) break;

		ins[i].opcode = input[0];
		ins[i].value = value;
		ins[i].first= 0;
		i++;
	}
	int toPrint = 0;
	i = 0;
	while (i < 636)
	{
		/*
		if (ins[i].first) break;
		else ins[i].first = 1;
		*/

		if (ins[i].opcode == 'j')
		{
			int test = try(ins, i + 1);
			printf("%d \n", test);
			if (test) 
			{
				toPrint += test;
				break;
			}
			else i += ins[i].value;
		}
		else if (ins[i].opcode == 'a')
		{
			toPrint += ins[i].value;
			++i;
		} 
		else
		{
			if (i + ins[i].value >= 631) i += ins[i].value;
			else i++;
		}
	}
	printf("%d\n", toPrint);
	fclose(f);

}