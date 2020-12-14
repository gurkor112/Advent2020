
%option noyywrap
%option noinput


LETTER [A-Z]

%%
{LETTER}+ {
	fprintf(yyout, "%s ", yytext);
}

%%

int abs(int i)
{
	return i < 0 ? i*-1 : i;
}

int main()
{
	FILE* in = fopen("input12", "r");
	FILE* out = fopen("output12", "w");
	yyin = in;
	yyout = out;
	yylex();
	fclose(out);
	fclose(in);

	in = fopen("output12", "r");


	char c[1];
	int amount;
	int ori = 0;
	int x = 0;
	int y = 0;
	int xpoint = 10;
	int ypoint = -1;
	while (1)
	{
		int ret = fscanf(in, "%s %d", &c, &amount);
		if (ret == EOF) break;

		if (c[0] == 'N') ypoint -= amount;
		else if (c[0] == 'S') ypoint += amount;
		else if (c[0] == 'E') xpoint += amount;
		else if (c[0] == 'W') xpoint -=amount;
		else if (c[0] == 'L')
		{
			amount = amount / 90;
			for (int i = 0; i < amount; ++i)
			{
				printf("L %d %d ", xpoint, ypoint);
				int temp;
				temp = xpoint * -1;
				xpoint = ypoint;
				ypoint = temp;
				ori = (ori + 3) %4;
				printf("%d %d\n", xpoint, ypoint);
			} 
		}
		else if (c[0] == 'R')
		{
			amount = amount/ 90;
			for (int i = 0; i < amount; ++i)
			{
				printf("R %d %d", xpoint, ypoint);
				int temp;
				temp = ypoint * -1;
				ypoint = xpoint;
				xpoint = temp;
				ori = (ori + 1) % 4;
				printf(" %d %d\n", xpoint, ypoint);
			}
		}
		else if (c[0] == 'F')
		{
			x += xpoint * amount;
			y += ypoint * amount;
		}

	}
	x = abs(x);
	y = abs(y);

	printf("%d\n", x +y );
}
