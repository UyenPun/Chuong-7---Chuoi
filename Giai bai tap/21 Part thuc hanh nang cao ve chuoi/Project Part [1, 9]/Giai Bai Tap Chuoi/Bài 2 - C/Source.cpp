#include <stdio.h>
#include <conio.h>
#include <string.h>
int STRLEN(char *);

void STRCPY(char *s1, char *s2) // gán s2 qua s1
{
	int length = STRLEN(s2);
	for(int i = 0; i < length; i++)
	{
		s1[i] = s2[i];
	}
	s1[length] = '\0'; // Kết thúc chuỗi.
}

int STRLEN(char *s)
{
	int dem = 0;
	while(s[dem] != '\0')
	{
		dem++;
	}
	return dem;
}

char* STRLWR(char *s)
{
	char *p = strdup(s);
	int length = strlen(p);

	for(int i = 0; i < length; i++)
	{
		if(p[i] >= 'A' && p[i] <= 'Z')
		{
			p[i] += 32; // Đổi sang thường
		}
	}
	return p;
}

char* STRUPR(char *s)
{
	char *p = strdup(s);
	int length = strlen(p);

	for(int i = 0; i < length; i++)
	{
		if(p[i] >= 'a' && p[i] <= 'z')
		{
			p[i] -= 32; // Đổi sang hoa
		}
	}
	return p;
}

void VietHoaKyTuDau(char *s)
{
	int length = STRLEN(s);
	if(s[0] != ' ')
	{
		if(s[0] >= 'a' && s[0] <= 'z')
		{
			s[0] -= 32;
		}
	}

	for(int i = 0; i < length; i++)
	{
		if(s[i] == ' ' && s[i + 1] != ' ')
		{
			if(s[i + 1] >= 'a' && s[i + 1] <= 'z')
			{
				s[i + 1] -= 32;
			}
		}
	}
}

void Xoa(char *a, int vitrixoa)
{
	int n = STRLEN(a);
	for(int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	a[n - 1] = '\0';
}

void XoaKhoangTrangThua(char *s)
{
	int length = STRLEN(s);
	for(int i = 0; i < length; i++)
	{
		if(s[i] == ' ' && s[i + 1] == ' ')
		{
			Xoa(s, i);
			i--;
			length--;
		}
	}

	// Xóa đầu
	if(s[0] == ' ')
	{
		Xoa(s, 0);
		length--;
	}

	// Xóa cuối
	if(s[length - 1] == ' ')
	{
		Xoa(s, length - 1);
		length--;
	}
}


int main()
{
	char s[100];
	//strcpy(s, "Son Xau Trai");
	STRCPY(s, "    son    xau  trai      haha    "); // Hàm tự viết

	//int dodai = STRLEN(s);
	//printf("\nDo dai = %d", dodai);

	// 'a' => 97
	// 'A' => 65
	// Cách nhau 32

	/*char p[30];
	strcpy(p, STRLWR(s));

	printf("\nChuoi thuong: %s", p);

	strcpy(p, STRUPR(s));

	printf("\nChuoi hoa: %s", p);

	printf("\nChuoi s ban dau: %s", s);*/

	// Từ là 1 hoặc nhiều ký tự khác khoảng trắng
	VietHoaKyTuDau(s);
	printf("\nViet hoa ky tu dau: %s", s);

	/* 
	Chuẩn hóa chuỗi (Xóa khoảng trắng thừa)
	- Đầu chuỗi & cuối chuỗi không có khoảng trắng
	- Ở trong đoạn giữa chuỗi thì giữa 2 từ chỉ
	được phép có 1 khoảng trắng

	*/

	XoaKhoangTrangThua(s);
	printf("\nChuoi sau khi xoa khoang trang thua: %s", s);

	getch();
	return 0;
}