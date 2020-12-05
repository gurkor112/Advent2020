
%option noyywrap
%option noinput
%{
#include <string.h>
#include <ctype.h>
%}
INTEGER [0-9]+
CHAR [a-z]+

%%


":" {
	fprintf(yyout," ");
}

\n\n {
	fprintf(yyout, "\n---\n");
}

. {
	fprintf(yyout, "%s", yytext);
}



%%
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE* in = fopen("input4", "r");
	FILE* out = fopen("output4", "w");
	yyin = in;
	yyout = out;
	yylex();
	fclose(out);
	fclose(in);

	in = fopen("output4", "r");

	int count= 0;
	int toPrint = 0;
	int ret;
	char value[4];
	char trash[100];
	int pos = 0;
	while(1)
	{
		ret = fscanf(in, "%s", value);

		if (ret == EOF)
		{
			break;
		}

		if (value[0] == '-')
		{
			if (count >= 7)
			{
				toPrint++;
				printf("Ok pos: %d, count: %d\n", pos, count);
			} 
			else	printf("not pos: %d, count: %d\n", pos, count);
			pos++;
			count = 0;
			continue;
		}
		else if(value[0] != 'c')
		{

			ret = fscanf(in, "%s", trash);
			if (ret == EOF)
			{
				break;
			}
			int v;
			if (trash[0] != '#') v = atoi(trash);
			if (value[0] == 'b')
			{
				if (v>= 1920 && v <= 2002) count++;
			}
			else if(value[0] == 'i')
			{
				if (v<= 2020 && v>= 2010) count++;
			}
			else if (value[0] == 'e' && value[1] == 'y')
			{
				if (v <= 2030 && v>= 2020) count++;
			}
			else if(value[0] == 'h' && value[1] == 'g')
			{
				char temp[100];
				int i;
				for (i = 0; i < 100; ++i)
				{
					if (isdigit(trash[i])) temp[i] = trash[i];
					else
					{
						temp[i] = 0;
						break;
					}
				}
				v = atoi(temp);
				if (trash[i] == 'c')
				{
					if (v >= 150 && v <= 193) 
					{
						count++;
					}	
				}
				else
				{
					if (v >= 59 && v<= 76) count++;
				}
			}
			else if (value[0] == 'h' && value[1] == 'c')
			{
				if (strlen(trash) == 7)
				{
					int a = 0;
					for(int i = 1; i < 7; ++i)
					{
						if (trash[i] <= '9' && trash[i]>= '0' || trash[i] >='a' && trash[i] <= 'f' ) 
						{
							a++;
						}
						else
						{
							printf("ERROR %c", trash[i]);
						}
					}
					if (a == 6) count++;
				}
			}
			else if(value[0] == 'e')
			{
				if(strcmp("amb", trash)) count++;
				else if(strcmp("blu", trash))  count++;
				else if (strcmp("brn", trash)) count++;
				else if(strcmp("gry", trash)) count++;
				else if(strcmp("grn", trash)) count++;
				else if(strcmp("hzl", trash)) count++;
				else if(strcmp("oth", trash))  count++;
			}
			else
			{
				if (strlen(trash) == 9) count++;
			}

			continue;
		}

		ret = fscanf(in, "%s", trash);


		if (ret == EOF)
		{
			break;
		}
	}

	printf("%d\n", toPrint);
	fclose(in);

}
