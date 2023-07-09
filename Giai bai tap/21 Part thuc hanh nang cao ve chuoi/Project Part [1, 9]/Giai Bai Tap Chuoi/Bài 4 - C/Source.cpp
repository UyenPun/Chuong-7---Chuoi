/* 
Từ là 1 hoặc nhiều ký tự khác khoảng trắng
vd: Nam Son
=> có 2 từ là từ "Nam" & từ "Son"

*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

int DemSoTu(char *s)
{
	int length = strlen(s);
	int dem = 0;

	if(s[0] != ' ')
	{
		dem = 1;
	}

	for(int i = 0; i < length - 1; i++)
	{
		if(s[i] == ' ' && s[i + 1] != ' ')
		{
			dem++;
		}
	}
	return dem;
}


int main()
{
	char s[] = "Nam Son";

	int sotu = DemSoTu(s);
	printf("\nSo tu = %d", sotu);


	getch();
	return 0;
}
