#include <stdio.h>
#include <conio.h>
#include <string.h>

void Them(char *a, int vitrithem, char phantuthem)
{
	int n = strlen(a);
	for(int i = n - 1; i >= vitrithem; i--)
	{
		a[i + 1] = a[i];
	}
	a[vitrithem] = phantuthem;
	a[n + 1] = '\0';
}

void ChuanHoaCungDoDai(char *s1, char *s2)
{
	int length1 = strlen(s1);
	int length2 = strlen(s2);

	// Chuỗi 1 bị thiếu
	if(length1 < length2)
	{
		for(int i = 1; i <= length2 - length1; i++)
		{
			Them(s1, 0, '0');
		}
	}

	// cHUỖI 2 bị thiếu
	else if(length2 < length1)
	{
		for(int i = 1; i <= length1 - length2; i++)
		{
			Them(s2, 0, '0');
		}
	}
}

char* TinhTong(char *s1, char *s2)
{
	ChuanHoaCungDoDai(s1, s2);

	int length = strlen(s1);
	char ketqua[1000];
	int idx = 0; // index của kết quả
	int nho = 0;

	for(int i = length - 1; i >= 0; i--)
	{
		int so1 = s1[i] - 48;
		int so2 = s2[i] - 48;
		int tong = so1 + so2 + nho;

		nho = tong / 10; // Cập nhật nhớ
		tong %= 10;

		ketqua[idx++] = tong + 48;
		printf("\nTrong vong lap: idx = %d", idx);
	}
	bool Check = false;
	if(nho != 0)
	{
		Check = true;
		printf("\nTRONG IF idx = %d", idx);
		ketqua[idx] = nho + 48;
	}
	printf("\nBen ngoai idx = %d", idx);
	if(Check == true)
		ketqua[idx + 1] = '\0'; // Kết thúc chuỗi.
	else
		ketqua[idx] = '\0';
	strrev(ketqua); // Đảo chuỗi lại
	
	return ketqua;
}

int main()
{
	char s1[1000] = "13";
	char s2[1000] = "45";

	char Tong[1000];
	strcpy(Tong, TinhTong(s1, s2));
	printf("\nTong = %s", Tong);
	
	getch();
	return 0;
}