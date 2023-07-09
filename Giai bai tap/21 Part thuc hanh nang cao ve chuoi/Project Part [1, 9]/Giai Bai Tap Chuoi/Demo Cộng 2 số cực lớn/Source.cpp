/* 
- 1 ký tự mà muốn đổi sang số tương ứng => lấy ký tự - 48
- 1 số mà muốn đổi sang ký tự tương ứng => lấy số đó + 48

Ý Tưởng:
B1: Chuẩn hóa 2 chuỗi cho có độ dài bằng nhau, chuỗi
nào có độ dài ngắn hơn thì thêm vào số 0 ở đầu sao cho
2 chuỗi bằng nhau

B2: Duyệt từ phải qua trái, lần lượt lấy từng ký
tự ở 2 chuỗi cộng lại với nhau (trước đó đổi ra số),
nếu tổng > 9 => lưu phần nguyên vào 1 biến nhớ và
chỉ xuất kết quả lưu vào chuỗi kết quả (tổng = 16 tức
là nhớ 1 viết 6)

*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

//void Xoa(char *s, int vitrixoa)
//{
//	int n = strlen(s);
//	for(int i = vitrixoa + 1; i < n; i++)
//	{
//		s[i - 1] = s[i];
//	}
//	s[n - 1] = '\0';
//}


void Them(char *s, char kytu, int vitrithem)
{
	int n = strlen(s);
	for(int i = n - 1; i >= vitrithem; i--)
	{
		s[i + 1] = s[i];
	}
	s[vitrithem] = kytu;
	s[n + 1] = '\0';
}

void ChuanHoaCungDoDai(char *s1, char *s2)
{
	int length1 = strlen(s1);
	int length2 = strlen(s2);

	// Thêm số 0 vào chuỗi 1
	if(length1 < length2)
	{
		for(int i = 1; i <= length2 - length1; i++)
		{
			Them(s1, '0', 0);
		}
	}
	// Thêm vào chuỗi s2
	else if(length2 < length1)
	{
		for(int i = 1; i <= length1 - length2; i++)
		{
			Them(s2, '0', 0);
		}
	}
}

char* TinhTong(char *s1, char *s2)
{
	ChuanHoaCungDoDai(s1, s2);

	int length = strlen(s1);
	int nho = 0; // Mặc định nhớ = 0
	char ketqua[200];
	int idx = 0;

	for(int i = length - 1; i >= 0; i--)
	{
		int so1 = s1[i] - 48; // Đổi ký tự sang số
		int so2 = s2[i] - 48;

		int tong = so1 + so2 + nho;
		nho = tong / 10;
		tong %= 10;

		ketqua[idx++] = tong + 48; // Đổi số sang ký tự rồi lưu vào chuỗi kết quả
	}

	if(nho != 0)
	{
		ketqua[idx] = nho + 48;
	}
	ketqua[++idx] = '\0';

	strrev(ketqua); // Đảo chuỗi lại.

	return ketqua;
}


int main()
{
	char s1[200], s2[200];

	strcpy(s1, "95");
	strcpy(s2, "98");

	char ketqua[200];
	strcpy(ketqua, TinhTong(s1, s2));
	printf("\ns1 + s2 = %s", ketqua);


	

	getch();
	return 0;
}