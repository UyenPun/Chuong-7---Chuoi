/* Viết hàm nhận vào một chuỗi s và đếm
xem có bao nhiêu từ trong chuỗi đó.

TỪ là gì ???
Là 1 hoặc 1 nhóm các ký tự khác khoảng trắng

s = "Linh xau hoac"

*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

int DemSoTu(char *s)
{
	int dem;

	if(s[0] == ' ')
	{
		dem = 0;
	}
	else
	{
		dem = 1;
	}

	int length = strlen(s);

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
	char s[] = "    Linh    xi    da   ";
	
	int sotu = DemSoTu(s);
	printf("\nSo tu = %d", sotu);

	getch();
	return 0;
}