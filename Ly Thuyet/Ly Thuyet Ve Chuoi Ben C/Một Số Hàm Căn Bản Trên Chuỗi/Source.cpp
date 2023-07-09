#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> // atoi ...

int main()
{
	char ten[] = "Son Dep Trai";

	int length = strlen(ten);
	printf("\nChuoi dai %d ky tu", length);

	// Duyệt chuỗi (đi từng ký tự)
	int dem = 0;
	for(int i = 0; i < length; i++)
	{
		if(ten[i] == 'o')
		{
			dem++;
		}
		//printf("\nten[%d] = %c", i, ten[i]);
	}

	char ten2[30]; // nếu độ lớn không đủ chứa sẽ bị lỗi tràn bộ nhớ.
	//ten2 = ten; // gán ten sang ten2 => sai
	strcpy(ten2, ten);
	//printf("\nten2[31] = %c", ten2[31]);

	char *ten3 = strdup(ten);
	//strlwr(ten3);
	//strupr(ten3);
	strrev(ten3);
	printf("\nten3 = %s", ten3);

	// "abc\0" => "cba\0"

	char s1[] = "sonDeptrai";
	char s2[] = "sondeptrai";

	int ketqua = stricmp(s1, s2);
	printf("\nketqua = %d", ketqua);

	char ten4[30] = "son";
	char ten5[30] = " dep trai";

	strcat(ten4, ten5);
	printf("\nten4 = %s", ten4);

	char tensach[100] = "day con lam giau";
	char timkiem[] = "lam tinh";

	if(strstr(tensach, timkiem) != NULL)
	{
		printf("\nTim thay");
	}
	else
	{
		printf("\nKhong tim thay");
	}

	char s3[] = "6.9";
	double so = atof(s3);
	printf("\nso = %lf", so);

	int so1 = 250;
	char s4[30];
	itoa(so1, s4, 2);
	printf("\nHe 2 la: %s", s4);

	itoa(so1, s4, 8);
	printf("\nHe 8 la: %s", s4);

	itoa(so1, s4, 10);
	printf("\nHe 10 la: %s", s4);
	
	itoa(so1, s4, 16);
	printf("\nHe 16 la: %s", s4);

	// strtok hỗ trợ cắt chuỗi
	char chuoi[] = "Son, Linh, Thien, Tuan, Dinh";
	char *substr = strtok(chuoi, ", "); // con trỏ substr trỏ tới vùng nhớ được trả về từ hàm strtok
	printf("\nsub = %s", substr);

	substr = strtok(NULL, ", "); // con trỏ substr trỏ tới vùng nhớ được trả về từ hàm strtok, để NULL tức là sẽ xét duyệt từ lần cắt ở trước đó.
	printf("\nsub = %s", substr);

	substr = strtok(NULL, ", "); // con trỏ substr trỏ tới vùng nhớ được trả về từ hàm strtok, để NULL tức là sẽ xét duyệt từ lần cắt ở trước đó.
	printf("\nsub = %s", substr);

	substr = strtok(NULL, ", "); // con trỏ substr trỏ tới vùng nhớ được trả về từ hàm strtok, để NULL tức là sẽ xét duyệt từ lần cắt ở trước đó.
	printf("\nsub = %s", substr);

	substr = strtok(NULL, ", "); // con trỏ substr trỏ tới vùng nhớ được trả về từ hàm strtok, để NULL tức là sẽ xét duyệt từ lần cắt ở trước đó.
	printf("\nsub = %s", substr);

	// có 5 chuỗi, mỗi chuỗi có tối đa 40 ký tự.
	/*char danhsach[5][40] = 
	{"Nguyen Viet Nam Son", 
	"Nguyen Luu Duc Tuan", 
	"Le Minh Thien", 
	"Tran Duong Thuy Linh", 
	"Maria Ozawa"};

	for(int i = 0; i < 5; i++)
	{
		printf("\n%s", danhsach[i]);
	}*/



	getch();
	return 0;
}