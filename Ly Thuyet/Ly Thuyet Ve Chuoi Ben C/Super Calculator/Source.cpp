#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
B1: Những số mà độ dài không bằng nhau 
=> Thêm số 0 vào đầu cho cân bằng

B2: Duyệt từ cuối về đầu của 2 chuỗi số tương ứng
, lấy từng ký tự ở từng vị trí tương ứng 
chuyển nó sang số tương ứng rồi cộng lại với nhau
, nếu kết quả > 10 => lấy phần dư và nhớ 1 để c
ộng thêm vào cho lần sau

B3: Cứ thế lặp lại B2 cho đến khi đi hết chuỗi
*/

void ThemKyTuVaoChuoi(char *s, char kytuthem, int vitrithem)
{
	int length = strlen(s);
	for(int i = length - 1; i >= vitrithem; i--)
	{
		s[i + 1] = s[i];
	}
	s[vitrithem] = kytuthem;
	s[length + 1] = '\0';
}

/* 
894
456
----
0531 => rev = 1350
*/

int main()
{
	/*char s[30] = "12";
	ThemKyTuVaoChuoi(s, '0', 0);
	printf("\ns = %s", s);*/

	char s1[100] = "7486468452784578964564634898";
	char s2[100] = "95789412358646546134";

	/* ------------------------ BƯỚC 1 ----------------------- */
	int length_s1 = strlen(s1);
	int length_s2 = strlen(s2);

	int Min = length_s1 < length_s2 ? length_s1 : length_s2;
	int Max = length_s1 > length_s2 ? length_s1 : length_s2;

	if(Min == length_s1) // s1 cần thêm 0 vào đầu cho đủ
	{
		for(int i = 1; i <= Max - Min; i++)
		{
			ThemKyTuVaoChuoi(s1, '0', 0);
		}
	}
	else if(Min == length_s2) // s2 cần thêm 0 vào đầu cho đủ
	{
		for(int i = 1; i <= Max - Min; i++)
		{
			ThemKyTuVaoChuoi(s2, '0', 0);
		}
	}
	/* ------------------------------------------------------------- */

	/* ---------------------- BƯỚC 2 -------------------- */

	char ketqua[100];
	int idx = 0; // idx của ketqua

	int nho = 0;

	for(int i = Max - 1; i >= 0; i--)
	{
		int so = (s1[i] - 48) + (s2[i] - 48) + nho;
		nho = so / 10; // 16 thì nhớ 1
		so %= 10; // 16 thì lấy 6

		ketqua[idx++] = so + 48;
	}
	if(nho != 0)
	{
		ketqua[idx++] = nho + 48;
	}
	ketqua[idx] = '\0'; // Phải có kết thúc chuỗi.

	// đảo lại bởi vì nãy giờ mình làm là từ trái sang phải chứ không phải là từ phải sang trái
	strrev(ketqua);

	printf("\nketqua = %s", ketqua);

	getch();
	return 0;
}