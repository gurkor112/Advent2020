
%option noyywrap
%option noinput


%%

"-" {
	fprintf(yyout," ");
}

":" {
	fprintf(yyout," ");
}

. {
	fprintf(yyout, "%s", yytext);
}

%%
int main()
{
	FILE* in = fopen("input2", "r");
	FILE* out = fopen("output2", "w");
	yyin = in;
	yyout = out;
	yylex();
	fclose(out);
	fclose(in);

	in = fopen("output2", "r");

	int a;
	char s[100];
	int min, max;
	char c;
	int index;
	int count = 0;
	int toReturn = 0;
	while(1)
	{
		count = 0;
		a = fscanf(in, "%d %d %c %s", &min, &max,&c, s);
		
		if (a == EOF) 
		{
			printf("%d\n", toReturn);
			fclose(in);
			return 1;
		}
		if (s[min - 1] == c) count++;
		if (s[max - 1] == c) count++;
		if (count == 1) toReturn++;
	}
}
