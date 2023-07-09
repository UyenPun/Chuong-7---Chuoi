#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// strlen
int STRLEN(char *s)
{
	int idx = 0;
	while(s[idx] != '\0')
	{
		idx++;
	}
	return idx;
}

// strcpy(s1, s2); // Gán s2 qua s1
void STRCPY(char *s1, char *s2)
{
	int length = STRLEN(s2);

	for(int i = 0; i < length; i++)
	{
		s1[i] = s2[i];
	}
	s1[length] = '\0'; // Nếu không có kết thúc thì sẽ sinh ra ký tự lạ
}

// strlwr(s); // Biến chuỗi s thành chữ thường

// 'a': 97
// 'A': 65

void STRLWR(char *s)
{
	int length = STRLEN(s);

	for(int i = 0; i < length; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32; // Biến thành thường.
		}
	}
}

// strupr(s); // Biến chuỗi s thành chữ hoa

void STRUPR(char *s)
{
	int length = STRLEN(s);

	for(int i = 0; i < length; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32; // Biến thành hoa.
		}
	}
}

// strrev(s); // Đảo ngược chuỗi s
// vd: namson => nosman
/*
=> length = 6
0 1 2 3 4 5
n a m s o n

0 hoán vị 5
1 hoán vị 4
2 hoán vị 3

th2:
=> length = 5
namso => osman

0 1 2 3 4
n a m s o

0 hoán vị 4
1 hoán vị 3
*/

void HoanVi(char &a, char &b)
{
	char Temp = a;
	a = b;
	b = Temp;
}

void STRREV(char *s)
{
	int length = STRLEN(s);

	for(int i = 0; i < length / 2; i++)
	{
		HoanVi(s[i], s[length - 1 - i]);
	}
}

/* 
So sánh chuỗi
có 2 loại
strcmp: Có phân biệt hoa thường
stricmp: Không phân biệt hoa thường
*/

int STRCMP(char *s1, char *s2)
{
	int length1 = STRLEN(s1);
	int length2 = STRLEN(s2);

	int LengthMin = length1 < length2 ? length1 : length2;
	// s1 = "abc"
	// s2 = "a"
	for(int i = 0; i < LengthMin; i++)
	{
		if(s1[i] < s2[i])
		{
			return -1;
		}
		else if(s1[i] > s2[i])
		{
			return 1;
		}
	}
	if(length1 > length2)
	{
		return 1;
	}
	else if(length1 < length2)
	{
		return -1;
	}
	return 0;
}

int STRICMP(char *s1, char *s2)
{
	/* Cách làm 1: Dễ nhất */
	
	// Biến 2 chuỗi cùng thành chữ thường
	/*STRLWR(s1);
	STRLWR(s2);

	return STRCMP(s1, s2);*/

	/* Cách 2: Ta xử lý ở ngay bước so sánh ký tự */

	int length1 = STRLEN(s1);
	int length2 = STRLEN(s2);

	int LengthMin = length1 < length2 ? length1 : length2;
	// s1 = "abc"
	// s2 = "a"
	for(int i = 0; i < LengthMin; i++)
	{
		char temp1 = s1[i];
		char temp2 = s2[i];

		// quy hết tất cả về ký tự thường
		if(temp1 >= 'A' && temp1 <= 'Z')
		{
			temp1 += 32;
		}

		if(temp2 >= 'A' && temp2 <= 'Z')
		{
			temp2 += 32;
		}

		if(temp1 < temp2)
		{
			return -1;
		}
		else if(temp1 > temp2)
		{
			return 1;
		}
	}
	if(length1 > length2)
	{
		return 1;
	}
	else if(length1 < length2)
	{
		return -1;
	}
	return 0;
}

// strcat(s1, s2); // Nối s2 vào sau s1
void STRCAT(char *s1, char *s2)
{
	int length1 = STRLEN(s1);
	int size1 = sizeof(s1);
	printf("\nsize1 = %d", size1);
	int length2 = STRLEN(s2);

	for(int i = 0; i < length2; i++)
	{
		s1[length1++] = s2[i];
		if(length1 == size1 - 1)
		{
			break; // Tự động ngắt.
		}
	}
	// s1[6] => tức là tối đa được 5 ký tự
	// tức là chỉ số từ 0 -> 4
}

/*
strstr(s1, s2);
Tìm vị trí xuất hiện đầu tiên của chuỗi s2
trong chuỗi s1. Nếu không có thì trả ra -1

vd:
s1 = "Nguyen Viet Nam Son"
s2 = "Nam Son"

*/

int STRSTR(char *s1, char *s2)
{
	int length1 = STRLEN(s1);
	int length2 = STRLEN(s2);
	int Start;
	bool Check;

	for(int i = 0; i < length1; i++)
	{
		if(s1[i] == s2[0])
		{
			Start = i;
			Check = true; // Mặc định

			int Temp = Start;
			for(int j = 1; j < length2; j++)
			{
				if(s1[++Temp] != s2[j])
				{
					Check = false;
					break;
				}
			}
			if(Check == true)
			{
				return Start;
			}
		}
	}
	return -1;
}

/*
strdup(s); // Sao chép chuỗi s bỏ qua vùng
nhớ mới có độ lớn vừa đủ chứa

độ lớn sao chép: length + 1
*/
char* STRDUP(char *s)
{
	int length = STRLEN(s);

	char *p = (char *)malloc((length + 1) * sizeof(char));

	for(int i = 0; i < length; i++)
	{
		p[i] = s[i];
	}
	p[length] = '\0';
	return p;
}

int main()
{
	char s[] = "Son Dep Trai";
	
	int length = STRLEN(s);
	printf("\nlength = %d", length);

	char s1[100];
	STRCPY(s1, "hihi haha hoho");
	printf("\ns1 = %s", s1);

	STRLWR(s);
	printf("\nChu thuong: %s", s);

	STRUPR(s);
	printf("\nChu hoa: %s", s);

	char s2[] = "NamSon";

	STRREV(s2);
	printf("\ns2 = %s", s2);

	char s3[] = "abcd";
	char s4[] = "Abed";

	int kq = STRICMP(s3, s4);
	printf("\nKq = %d", kq);

	char s5[20] = "abc";
	char s6[7] = "defghi";

	STRCAT(s5, s6);
	printf("\ns5 = %s", s5);

	char s7[] = "Nguyen Viet Nam Son";
	char s8[] = "Viet";

	int ViTri = STRSTR(s7, s8);
	printf("\nVi tri = %d", ViTri);

	char s9[] = "Son xau trai";
	char *p = STRDUP(s9);
	printf("\np = %s", p);

	free(p);

	getch();
	return 0;
}