#include <stdio.h>
#include <stdlib.h>

#define WIDTH 12

int main(void)
{
	FILE *fp = fopen("input3.txt", "r");

	if(fp == NULL)
	{
		printf("Error opening file.\n");
		return -1;
	}

	int vals[WIDTH];
	int total = 0;
	
	char ch;
	size_t idx = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			total++;
			idx = 0;
		}
		else
		{
			if(ch == '1') vals[idx]++;

			idx++;
		}
	}

	int gamma = 0, epsilon = 0;
	for(size_t i = 0; i < WIDTH; i++)
	{
		gamma |= (vals[i] > total / 2) << ((WIDTH - 1) - i); // vals is big endian, reconstructing in little endian
		epsilon |= (vals[i] < total / 2) << ((WIDTH - 1) - i);
	}

	printf("\n%i %i %i", gamma, epsilon, gamma * epsilon);
	
	fclose(fp);

	return 0;
}
