#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp = fopen("input1.txt", "r");
	
	int vals[2000];
	int val;

	char ch;
	size_t idx = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			vals[idx] = val;
			idx++;
			val = 0;
		}
		else
		{
			val *= 10;
			val += ch - 48;
		}
	}

	fclose(fp);

	FILE *op = fopen("/tmp/eee.txt", "w");
	
	for(size_t i = 0; i < 2000; i++)
	{
		fprintf(op, "%i\n", vals[i]);
	}

	fclose(op);
	
	int res = 0;
	for(size_t i = 0; i < 2000 - 3; i++)
	{
		if(vals[i] + vals[i + 1] + vals[i + 2] < vals[i + 1] + vals[i + 2] + vals[i + 3]) res++;
	}

	printf("%i", res);

	return 0;
}
