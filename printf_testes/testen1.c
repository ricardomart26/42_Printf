#include <stdio.h>

int main(void)
{
// 	// WIDTH com ints
// 	printf("%5d\n", 5); // (    5)
// 	printf("%1d\n", 5); // (5) Com o 0 fica igual
// 	printf("%3d\n", 12345); // (12345)
// 	printf("%7d\n\n", 12345); // (  12345) 7 - 5 e fica com dois espacos atras

// 	// Precision
// 	printf("%.2d\n", 5); // (05)
// 	printf("%.1d\n", 5); // (5) Fica igual
// 	printf("%.10s\n", 5); // (0000000005) 9 zeros 10 - 1 = 9
// 	printf("%.2d\n", 12345); // (12345) Fica igual
// 	printf("%.7d\n\n", 12345); // (0012345) 2 zeros 7 - 5 = 2

	printf("%2.5d\n", 10); // (00010)
	printf("%10.5d\n", 10); // (     00010)
	printf("%10.3d\n", 10); // (       010)
	printf("%10.12d\n", 10); // (     00010)

	printf("%5.1d\n", 400); // (400)
 

	// // align
	// printf("sgpjoisjgios %-02.3d\n", 5); // (05)
	// printf("sgpjoisjgios %-d\n", 5); // (5) Fica igual
	// printf("sgpjoisjgios %-5d\n", 5); // (0000000005) 9 zeros 10 - 1 = 9
	// printf("sgpjoisjgios %-d\n", 12345); // (12345) Fica igual
	// printf("sgpjoisjgios %-2d\n", 12345); // (0012345) 2 zeros 7 - 5 = 2
	// printf("sgpjoisjgios %02d\n", 12345); // (0012345) 2 zeros 7 - 5 = 2
	// printf("sgpjoisjgios %0-2d\n", 12345); // (0012345) 2 zeros 7 - 5 = 2
}
