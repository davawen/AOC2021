#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp = fopen("input2.txt", "r");
	FILE *op = fopen("/tmp/eee.txt", "w");

	int horizontal = 0, depth = 0;
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
				horizontal += *(res + sizeof("forward")) - 48;
				printf("Adding %i to horizontal %i\n", *(res + sizeof("forward")) - 48, horizontal);
			}
			else if((res = strstr(line, "down")))
			{
				depth += *(res + sizeof("down")) - 48;
				printf("Adding %i to depth %i\n", *(res + sizeof("down")) - 48, depth);
			}
			else if((res = strstr(line, "up")))
			{
				depth -= *(res + sizeof("up")) - 48;
				printf("Removing %i from depth %i\n", *(res + sizeof("up")) - 48, depth);
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
