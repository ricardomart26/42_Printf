#include <stdio.h>


void	andar_frente(char **str)
{
	(*str)++;
}


int main(void)
{
	char *str = "A ines e a Maior";
	printf("%s\n", str);

	andar_frente(&str);

	printf("%s", str);

}
