#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


// 12345 = 1*10^4 + 2*10^3 + 3*10^2 + 4*10^1 + 5*10^0

int ATOI(char *s) // s là chuỗi
{
	int tong = 0;
	int dodai = strlen(s);
	int temp = dodai;
	for(int i = 0; i < dodai; i++)
	{
		tong += (s[i] - 48) * pow(10.0, --temp);
	}
	return tong;
}

int main()
{
	/*char s[] = "12345";
	int so = atoi(s);
	printf("\nso = %d", so);

	int so1 = ATOI(s);
	printf("\nSo1 = %d", so1);

	int x = 250;
	char ketqua[30];
	itoa(x, ketqua, 8);
	printf("\nHe 8: %s", ketqua);*/

	char str[] = "Nam, Son, Minh, Huyen, Anh";

	char *ten1 = strtok(str, ", ");
	printf("\nten1 = %s", ten1);

	char *ten2 = strtok(NULL, ", ");
	printf("\nten2 = %s", ten2);

	char *ten3 = strtok(NULL, ", ");
	printf("\nten3 = %s", ten3);

	getch();
	return 0;
}