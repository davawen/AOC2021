#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp = fopen("input2.txt", "r");
	FILE *op = fopen("/tmp/eee.txt", "w");

	int horizontal = 0, depth = 0, aim = 0;
	char ch;
	char line[80];
	size_t idx = 0;

	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			line[idx] = '\0';

			fprintf(op, "%s\n", line);

			char *res;
			
			if((res = strstr(line, "forward")))
			{
				int val = *(res + sizeof("forward")) - 48;
				horizontal += val;
				depth += aim * val;
			}
			else if((res = strstr(line, "down")))
			{
				aim += *(res + sizeof("down")) - 48;
			}
			else if((res = strstr(line, "up")))
			{
				aim -= *(res + sizeof("up")) - 48;
			}

			idx = 0;
		}
		else
		{
			line[idx] = ch;
			idx++;
		}
	}

	printf("%i\n", horizontal * depth);

	fclose(fp);
	fclose(op);

	return 0;
}
