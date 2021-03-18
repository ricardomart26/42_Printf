#include <stdio.h>
#include <stdlib.h>

char	*func(char *str)
{
	str = "O fred cheira a bananas";
	return (str);
}

int main(void)
{
	int i;
	char *str;

	str = NULL;
	i = 0;
	str = func(str);
	printf("%s", str);

	return (0);
}
