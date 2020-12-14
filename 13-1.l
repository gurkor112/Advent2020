
%option noyywrap
%option noinput


LETTER [A-Z]

%%
"," {
	fprintf(yyout, " ");
}

"x" {
	fprintf(yyout, " ");
}

%%


int main()
{
	FILE* in = fopen("input13", "r");
	FILE* out = fopen("output13", "w");
	yyin = in;
	yyout = out;
	yylex();
	fclose(out);
	fclose(in);

	in = fopen("output13", "r");


	int search;
	fscanf(in, "%d", &search);
	int curr = 10000;
	int temp;
	int id;
	while (1)
	{
		int ret = fscanf(in, "%d", &temp);

		if (ret == EOF) break;

		int tempid = temp;
		while (temp < search) temp += tempid;

		if (temp - search < curr)
		{
			curr = temp - search;
			id = tempid;
			printf("%d %d\n", id, curr);
		}

	}
	
	printf("%d\n", curr * id );
}
