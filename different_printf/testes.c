#include <stdio.h>

int main(void)
{
	int i, j;
	char *str;

	i = 0;
	i = printf("%-c%-c%c*", 1, '0', 0);
	printf("\n%d", i);
	j = ft_printf("%-c%-c%c*", 1, '0', 0);
	printf("\n%d", j);
}

