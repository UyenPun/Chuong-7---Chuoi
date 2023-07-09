#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// nếu là số thì trả về 1, ngược lại trả về 0
int KiemTraLaSoNguyen(char *s)
{
	int length = strlen(s);

	for(int i = 0; i < length; i++)
	{
		if(s[i] < '0' || s[i] > '9')
		{
			return 0; // sai
		}
	}
	return 1; // đúng
}

int main()
{
	int soluong;
sondeptrai:
	char chuoi[30];
	fflush(stdin);
	printf("\nNhap vao so luong: ");
	gets(chuoi);

	int kiemtra = KiemTraLaSoNguyen(chuoi);
	if(kiemtra == 0)
	{
		printf("\nLoi kieu du lieu");
		goto sondeptrai;
	}
	else
	{
		soluong = atoi(chuoi);
		printf("\nSo luong = %d", soluong);
	}



	getch();
	return 0;
}