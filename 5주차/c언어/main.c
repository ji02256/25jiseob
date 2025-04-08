#include <stdio.h>

int main()
{
	if (1)
	{
		int i = 5;
		int j = 4;

		while (i)
		{
			j = 6 - i;
			while (j)
			{
				printf("*");
				j = j - 1;

			}
			printf("\n");
			i = i - 1;
		}
	}

	return 0;
