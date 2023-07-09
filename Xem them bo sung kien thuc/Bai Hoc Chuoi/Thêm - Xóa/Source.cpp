// Thêm xóa ký tự trên chuỗi
#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
void Xoa(int a[], int &n, int vitrixoa)
{
	for(int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}

void Them(int a[], int &n, int vitrithem, int phantuthem)
{
	for(int i = n - 1; i >= vitrithem; i--)
	{
		a[i + 1] = a[i];
	}
	a[vitrithem] = phantuthem;
	n++;
}


*/

void Xoa(char *s, int vitrixoa)
{
	int n = strlen(s);
	for(int i = vitrixoa + 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n - 1] = '\0'; // tương đương n-- bên mảng số nguyên
}

void Them(char *s, int vitrithem, char phantuthem)
{
	int n = strlen(s);
	for(int i = n - 1; i >= vitrithem; i--)
	{
		s[i + 1] = s[i];
	}
	s[vitrithem] = phantuthem;
	s[n + 1] = '\0';
}

int main()
{
	char s[30] = "abcdef";

	// Xóa ký tự d
	//Xoa(s, 3);

	// Thêm ký tự g vào vị trí 3
	Them(s, 3, 'g');

	printf("\ns = %s", s);

	getch();
	return 0;
}