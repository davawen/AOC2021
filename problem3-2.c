#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 5
#define HEIGHT 12

int main(void)
{
	FILE *fp = fopen("input33.txt", "r");

	if(fp == NULL)
	{
		printf("Error opening file.\n");
		return -1;
	}

	int inputs[HEIGHT] = { 0 };
	for(size_t i = 0; i < HEIGHT; i++){ inputs[i] = 0; }

	int ones[WIDTH] = { 0 };
	int zeroes[WIDTH] = { 0 };
	
	char ch;
	size_t idx = 0;
	size_t lineIdx = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			idx = WIDTH - 1;
			lineIdx++;
		}
		else
		{
			if(ch == '1')
			{
				ones[idx]++;
				inputs[lineIdx] = (inputs[lineIdx] << 1) + 1;
			}
			else if(ch == '0')
			{
				zeroes[idx]++;
				inputs[lineIdx] = (inputs[lineIdx] << 1);
			}


			idx--;
		}
	}

	bool filtered[HEIGHT] = { 0 };

	size_t numLeft = HEIGHT;
	size_t oxygen = 0;
	for(size_t i = 0; i < WIDTH; i++)
	{
		for(size_t j = 0; j < HEIGHT; j++)
		{
			if(filtered[j]) continue;

			if(( (inputs[j] & (1 << i)) >> i ) == (ones[i] >= zeroes[i]))
			{
				if(numLeft == 1) oxygen = j;

				break;
			}
			else
			{
				printf("Filtered %i at bit %zu\n", inputs[j], i);

				filtered[j] = true;
				numLeft--;
			}
		}

		if(numLeft == 1) break;
	}

	printf("Oxygen: %i", inputs[oxygen]);

	
	fclose(fp);

	return 0;
}
