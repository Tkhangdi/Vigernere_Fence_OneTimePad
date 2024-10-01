#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<conio.h>
#define MAXN 100

bool la_ky_tu(char x)
{
	if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
		return true;
	return false;
}

void ma_hoa(char ban_ro[], int k, char ban_mo[])
{
	if (k <= 0)
	{
		printf("So hang rao phai lon hon 0!\n");
		return;
	}
	int len = strlen(ban_ro);

	char** ma_tran = new char* [k];
	for (int i = 0; i < k; ++i)
	{
		ma_tran[i] = new char[len];
	}

	int row = 0, col = 0;
	for (int i = 0; i < len; i++)
	{
		ma_tran[row][col++] = ban_ro[i];
		if (row == k - 1)
		{
			row = 0;
			col--;
		}
		else
			row++;
	}


	col = 0;
	int index = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < len; j++)
		{

			if (la_ky_tu(ma_tran[i][j]))
			{
				ban_mo[index] = ma_tran[i][j];
				index++;
			}
		}
	}
	ban_mo[len] = '\0';

	for (int i = 0; i < k; ++i)
	{
		delete[] ma_tran[i];
	}
	delete[] ma_tran;

}

void giai_ma(char ban_mo[], int k, char ban_ro[])
{
	if (k <= 0)
	{
		printf("So hang rao phai lon hon 0!\n");
		return;
	}
	int len = strlen(ban_mo);

	char** ma_tran = (char**)malloc(k * sizeof(char*));
	for (int i = 0; i < k; i++) {
		ma_tran[i] = (char*)malloc(len * sizeof(char));
	}

	int index = 0, n = len % k, m = len / k;

	for (int i = 0; i < k; i++)
	{
		if (n == 0)
		{
			strncpy(ma_tran[i], ban_mo + 0, m);
			int len_new1 = strlen(ban_mo);
			strncpy(ban_mo, ban_mo + m, len_new1 - m);
		}
		else if (n > 0)
		{
			strncpy(ma_tran[i], ban_mo + 0, m + 1);
			int  len_new2 = strlen(ban_mo);
			strncpy(ban_mo, ban_mo + m + 1, len_new2 - m + 1);
			n--;
		}
	}

	index = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (la_ky_tu(ma_tran[j][i]))
			{
				ban_ro[index] = ma_tran[j][i];
				index++;
			}
		}
	}
	ban_ro[len] = '\0';

	for (int i = 0; i < k; i++)
	{
		free(ma_tran[i]);
	}
	free(ma_tran);
}
int main()
{
	char ban_ro[100];
	int k;
	char ban_mo[100];
	int choice;
	do
	{
		printf("Menu:\n");
		printf("1. Ma hoa\n");
		printf("2. Giai ma\n");
		printf("3. Thoat\n");
		printf("Chon chuc nang: ");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			printf("Nhap chuoi can ma hoa: \n");
			gets_s(ban_ro);
			do 
			{
				printf("Nhap khoa K:\n");
				scanf_s("%d", &k);
				if (k <= 0)
					printf("Khoa k phai lon hon hoac bang 0. Nhap lai!\n");
			} while (k <= 0);
			ma_hoa(ban_ro, k, ban_mo);
			printf("Ban mo: %s\n", ban_mo);
			break;
		case 2:
			printf("Nhap chuoi can giai ma: \n");
			gets_s(ban_mo);
			do
			{
				printf("Nhap khoa K:\n");
				scanf_s("%d", &k);
				if (k <= 0)
					printf("Khoa k phai lon hon hoac bang 0. Nhap lai!\n");
			} while (k <= 0);
			giai_ma(ban_mo, k, ban_ro);
			printf("Ban ro: %s\n", ban_ro);
			break;
		case 3:
			printf("Ket thuc!\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai!\n");
		}
	} while (choice != 3);

	return 0;
}
