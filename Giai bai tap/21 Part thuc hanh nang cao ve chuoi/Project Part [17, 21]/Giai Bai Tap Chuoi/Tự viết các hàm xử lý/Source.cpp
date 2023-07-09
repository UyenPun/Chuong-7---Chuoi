#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int STRLEN(char *s)
{
	int dem = 0;
	while(s[dem] != '\0')
	{
		dem++;
	}
	return dem;
}

/*
"1234"
lần lượt lấy từng ký tự ra rồi đổi sang số
tương ứng

ta thấy kết quả mong muốn sẽ là 1234
1234 = 1*10^3 + 2*10^2 + 3*10^1 + 4*10^0
*/
int ATOI(char *s)
{
	int tong = 0;

	int length = STRLEN(s);
	int Temp = length;
	
	// Xác định Temp để biết phạm vi mình sẽ duyệt
	for(int i = 0; i < length; i++)
	{
		if(s[i] < '0' || s[i] > '9')
		{
			Temp = i;
			break;
		}
	}

	// Tính ra kết quả
	int Temp1 = Temp;
	for(int i = 0; i < Temp; i++)
	{
		tong += (s[i] - 48) * pow(10.0, --Temp1); 
	}

	return tong;
}

double ATOF(char *s)
{
	char phannguyen[30];
	int idx = 0;
	char phanle[30];

	int length = STRLEN(s);
	bool Check = true;

	// Đổ phần nguyên sang
	for(int i = 0; i < length; i++)
	{
		if(Check == true)
		{
			phannguyen[idx++] = s[i];
		}
		else
		{
			phanle[idx++] = s[i];
		}

		if(s[i] == '.')
		{
			Check = false;
			idx = 0; // reset lại
		}
	}

	return ATOI(phannguyen) + ATOI(phanle) / pow(10.0, idx);
}

// "namson" => "nosman"
/*
length = 6
0 1 2 3 4 5
n a m s o n

0 1 2 3 4 5
n o s m a n

for(int i = 0; i < length / 2; i++)
swap(s[i], s[length - 1 - i])
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


void ITOA(int value, char *ketqua, int coso)
{
	int idx = 0;
	while(value != 0)
	{
		int so = value % coso;
		if(so < 10)
		{
			ketqua[idx++] = so + 48;
		}
		else if(so == 10)
		{
			ketqua[idx++] = 'A';
		}
		else if(so == 11)
		{
			ketqua[idx++] = 'B';
		}
		else if(so == 12)
		{
			ketqua[idx++] = 'C';
		}
		else if(so == 13)
		{
			ketqua[idx++] = 'D';
		}
		else if(so == 14)
		{
			ketqua[idx++] = 'E';
		}
		else if(so == 15)
		{
			ketqua[idx++] = 'F';
		}
		value /= coso;
	}
	ketqua[idx] = '\0'; // Kết thúc chuỗi
	STRREV(ketqua);
}

// SUBSTR(s, x, y); // Cắt chuỗi con trong đoạn [x, y] của chuỗi s

char* SUBSTR(char *s, int x, int y)
{
	char ketqua[100];
	int idx = 0;

	for(int i = x; i <= y; i++)
	{
		ketqua[idx++] = s[i];
	}
	ketqua[idx] = '\0'; // Kết thúc
	return ketqua;
}

// Nếu không tồn tại trả về -1
// Nếu có tồn tại thì trả về vị trí đầu tiên
int TimViTriDauTien(char *s, char *find)
{
	/*
	s = "Nguyen Viet Nam Son"
	find = "Nam Son"
	*/
	int length_s = STRLEN(s);
	int length_find = STRLEN(find);
	int Start;
	bool Check;

	// Duyệt chuỗi s
	for(int i = 0; i < length_s; i++)
	{
		if(s[i] == find[0])
		{
			Start = i;
			Check = true;
			int Temp = Start;
			// Duyệt chuỗi find
			for(int j = 1; j < length_find; j++)
			{
				if(find[j] != s[++Temp])
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

int main()
{
	// th1: "1234" => 1234
	// th2: "12abc34" => 12
	// th3: "abc1234" => 0
	//char s[] = "865.3589";

	//int x = ATOI(s);
	//printf("\nx = %d", x);

	//double y = ATOF(s);
	//printf("\ny = %lf", y);

	/*int value = 250;
	char ketqua[1000];
	int coso = 8;

	ITOA(value, ketqua, coso);

	printf("\nKet qua = %s", ketqua);*/

	/*char s[] = "Nam, Hoa, Tun, Teo, Ti";

	char *p1 = strtok(s, ", ");
	printf("\nten1: %s", p1);

	char *p2 = strtok(NULL, ", ");
	printf("\nten1: %s", p2);*/

	char s[] = "Nguyen Viet Nam Son";
	/*char sub[100];
	strcpy(sub, SUBSTR(s, 7, 10));
	printf("\nsub = %s", sub);*/

	int ViTri = TimViTriDauTien(s, "Viet");
	printf("\nVi tri = %d", ViTri);

	getch();
	return 0;
}
