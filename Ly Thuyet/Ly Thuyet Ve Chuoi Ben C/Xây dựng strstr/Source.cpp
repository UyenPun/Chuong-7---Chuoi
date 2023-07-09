#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int STRLEN(char *s)
{
	int dem = 0;
	while(s[dem++] != '\0'){}
	return dem - 1;

	/*while (true)
	{
		if(s[dem] == '\0')
		{
			return dem - 1;
		}
		dem++;
	}*/
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// trả về vị trí tìm thấy
void STRSTR(char *s, char *key)
{
	int arr[100];
	int idx = 0;
	int length_s = STRLEN(s);
	int length_key = STRLEN(key);

	// duyệt cái chuỗi đang chứa chuỗi cần tìm
	for(int i = 0; i < length_s; i++)
	{
		if(s[i] == key[0])
		{
			//printf("\nTest1: Tim thay tai vi tri: %d", i);
			int k = 1;
			int Check = true;
			int temp = i + 1;
			for(int j = 1; j < length_key; j++)
			{
				if(s[temp++] != key[j])
				{
					Check = false;
					break;
				}
			}
			if(Check == true)
			{
				//printf("\nTest2: Tim thay tai vi tri: %d", i);
				//return i; // vị trí tìm thấy đầu tiên
				// i là start, i + length_key - 1 là end
				//printf("\nStart = %d & End = %d", i, i + length_key - 1);
				arr[idx++] = i;
			}
		}
	}

	idx = 0;
	// duyệt lại chuỗi ban đầu.
	for(int i = 0; i < length_s; i++)
	{
		// bat dau
		if(i == arr[idx])
		{
			textcolor(14); // bat mau vang
		}

		// ket thuc
		if(i == arr[idx] + length_key)
		{
			textcolor(7); // bat mau trang
			idx++; // chuyen sang vi tri tiep theo tim thay
		}
		printf("%c", s[i]);
	}

}




int main()
{
	char s1[] = "Nam Son lang tu dep trai hao hoa lang tu dep trai phong luu da tinh lang tu";
	char key[] = "lang ";

	STRSTR(s1, key);
	

	getch();
	return 0;
}