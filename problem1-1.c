#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp = fopen("input1.txt", "r");
	
	int res = 0;

	char ch;
	int val = 0, prevVal = -1;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			if(prevVal != -1 && val > prevVal) res++;

			prevVal = val;
			val = 0;
		}
		else
		{
			val *= 10;
			val += ch - 48;
		}
	}

	printf("%i", res);

	return 0;
}
