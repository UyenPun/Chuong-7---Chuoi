#include <stdio.h>
#include <conio.h>
#include <string.h>

char* BienChuoiThanhThuong(char *s)
{
	// tạo bản sao
	char *p = strdup(s);

	// biến thành thường
	strlwr(p);

	return p;
}

char* BienChuoiThanhHoa(char *s)
{
	// tạo bản sao
	char *p = strdup(s);

	// biến thành thường
	strupr(p);

	return p;
}

char* BienKyTuDauThanhHoa(char *s)
{
	// tạo bản sao
	char *p = strdup(s);

	// biến đổi
	/* 
Làm sao để tìm ra được ký tự đầu tiên
của 1 từ ???
=> Nếu trước đó là 1 khoảng trắng và tiếp
theo sau là 1 cái gì đó khác khoảng trắng
thì đó chính là ký tự đầu tiên của 1 từ

Lưu ý: Nếu đầu tiên của chuỗi không phải
là khoảng trắng thì sẽ bị lỗi
	*/

	int length = strlen(p);

	if(p[0] != ' ')
	{
		if(p[0] >= 'a' && p[0] <= 'z')
		{
			p[0] -= 32;
		}
	}

	for(int i = 0; i < length; i++)
	{
		if(p[i] == ' ' && p[i + 1] != ' ')
		{
			if(p[i + 1] >= 'a' && p[i + 1] <= 'z')
			{
				p[i + 1] -= 32;
			}
		}
	}
	return p;
}

void XoaKyTu(char *s, int vitrixoa)
{
	int length = strlen(s);

	for(int i = vitrixoa + 1; i < length; i++)
	{
		s[i - 1] = s[i];
	}
	s[length - 1] = '\0';
}

char* XoaHetKhoangTrangThua(char *s)
{
	// tạo bản sao
	char *p = strdup(s);

	int length = strlen(p);

	for(int i = 0; i < length; i++)
	{
		if(p[i] == ' ' && p[i + 1] == ' ')
		{
			XoaKyTu(p, i);
			i--;
			length--;
		}
	}

	if(p[0] == ' ')
	{
		XoaKyTu(p, 0);
		length--;
	}

	if(p[length - 1] == ' ')
	{
		XoaKyTu(p, length - 1);
		length--;
	}

	return p;
}

int main()
{
	char s[] = "     son    dep    trai     ";

	char p[100];

	strcpy(p, XoaHetKhoangTrangThua(s));
	printf("\ns = %s", s);
	printf("\np = %s", p);
	



	getch();
	return 0;
}