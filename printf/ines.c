
// Esta bem para o inteiro
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i] != '\0')
		i++;
	return (i);
}

void ft_width(char *str, int width, int zero, int point)
{
	int i = 0;

	if (width > ft_strlen(str))
	{
		while (width > ft_strlen(str))
		{
			if (zero == 1)
				printf("0");
			else
				printf(" ");
			width--;
		}
		if (point <= 0)
			printf("%s", str);
		else
		{
			while (point > 0 && str[i] != '\0')
			{
				printf("%c", str[i]);
				i++;
				point--;
			}
		}
	}
	else if (width < 0)
	{
		width *= -1;
		if (point <= 0)
			printf("%s", str);
		else
		{
			while (point > 0 && str[i] != '\0')
			{
				printf("%c", str[i]);
				i++;
				point--;
			}
		}
		while (width > ft_strlen(str))
		{
			printf(" ");
			width--;
		}
	}
	else if (width < ft_strlen(str))
	{
		if (point == 0)
			printf("%s", str);
		while (point > 0 && str[i] != '\0')
		{
			printf("%c", str[i]);
			i++;
			point--;
		}
	}

}

int main()
{
	ft_width("Ines", 15, 0, 6);
	printf(".");
	printf("    -- Teste 15w, no zero and 6 char");

	printf("\n\n");
	ft_width("Ines", 15, 0, 2);
	printf(".");
	printf("    -- Teste 15w, no zero and 2 char");


	printf("\n\n");
	ft_width("Ines", 15, 1, 6);
	printf(".");
	printf("    -- Teste 15w, Zero and 6 char");
	printf("\n\n");

	ft_width("Ines", 15, 1, 2);
	printf(".");
	printf("    -- Teste 15w, Zero and 2 char");
	printf("\n\n");

	ft_width("Ines", 2, 1, 2);
	printf(".");
	printf("    -- Teste 2w, Zero and 2 char");
	printf("\n\n");

	ft_width("Ines", 2, 0, 5);
	printf(".");
	printf("    -- Teste 2w, no zero and 5 char");
	printf("\n\n");

	return 0;

}
