
%option noyywrap
%option noinput


%%

\n\n {
	fprintf(yyout, "\n-\n");
}

. {
	fprintf(yyout, "%s", yytext);
}

%%

void zero(int* a, int lenght)
{
	for (int i = 0; i < lenght; ++i) a[i] = 0; 
}

int main()
{
	FILE* in = fopen("input6", "r");
	FILE* out = fopen("output6", "w");
	yyin = in;
	yyout = out;
	yylex();
	fclose(out);
	fclose(in);

	in = fopen("output6", "r");

	int count = 0;
	char input[26];
	int answers[26];
	int toPrint = 0;
	zero(answers, 26);
	while (1)
	{
		int ret = fscanf(in, "%s", input);

		if (ret == EOF)
		{
			for (int i = 0; i < 26; ++i)
			{
				if (answers[i] == count)
				{
					++toPrint;
				} 
			}
			break;
		}
		else if (input[0] == '-')
		{
			for (int i = 0; i < 26; ++i)
			{
				if (answers[i] == count)
				{
					++toPrint;
					printf("%c\n", i + 'a');
				} 
			}
			count = 0;
			zero(answers, 26);
			continue;
		}

		int i = 0;
		while(input[i] != 0)
		{
			answers[input[i] - 'a']++;
			++i;
		}
		count++;

	}


	printf("%d\n", toPrint);
}
