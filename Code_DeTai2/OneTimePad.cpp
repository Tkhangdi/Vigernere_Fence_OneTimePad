//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//void ma_hoa(char str[], char key[]) 
//{
//	int i, j;
//	int numstr[100];
//	int numkey[100];
//	int numcipher[100];
//	int len = strlen(str);
//	int key_len = strlen(key);
//	int key_index = 0;
//	for (i = 0, j = 0; i < len; i++)
//	{
//		if (str[i] != ' ')
//		{
//			str[j] = toupper(str[i]);
//			j++;
//		}
//	}
//	str[j] = '\0';
//	for (i = 0, j = 0; i < key_len; i++)
//	{
//		if (key[i] != ' ')
//		{
//			key[j] = toupper(key[i]);
//			j++;
//		}
//	}
//	key[j] = '\0';
//	len = strlen(str);
//	for (i = 0; i < len; i++)
//	{
//		numstr[i] = str[i] - 'A';
//	}
//	for (i = 0; i < len; i++)
//	{
//		numkey[i] = key[key_index] - 'A';
//		key_index++;
//		if (key_index == key_len)
//			key_index = 0;
//	}
//	for (i = 0; i < len; i++)
//	{
//		numcipher[i] = numstr[i] + numkey[i];
//		if (numcipher[i] > 25)
//		{
//			numcipher[i] -= 26;
//		}
//	}
//	printf("Chuoi duoc ma hoa: \n");
//
//	for (i = 0; i < len; i++)
//	{
//		printf("%c", (numcipher[i] + 'A'));
//	}
//	printf("\n");
//}
//
//void giai_ma(char ban_mo[], char key[]) 
//{
//	int i, j;
//	int numcipher[100], numkey[100], numstr[100];
//	int len = strlen(ban_mo);
//	int key_len = strlen(key);
//	int key_index = 0; 
//
//	for (i = 0, j = 0; i < len; i++)
//	{
//		if (ban_mo[i] != ' ')
//		{
//			ban_mo[j] = toupper(ban_mo[i]);
//			j++;
//		}
//	}
//	ban_mo[j] = '\0';
//
//	for (i = 0, j = 0; i < key_len; i++)
//	{
//		if (key[i] != ' ')
//		{
//			key[j] = toupper(key[i]);
//			j++;
//		}
//	}
//	key[j] = '\0';
//
//	len = strlen(ban_mo);
//
//	for (i = 0; i < len; i++)
//	{
//		numcipher[i] = ban_mo[i] - 'A';
//	}
//
//	for (i = 0; i < len; i++)
//	{
//		numkey[i] = key[key_index] - 'A';
//		key_index++;
//		if (key_index == key_len)
//			key_index = 0;
//	}
//
//	for (i = 0; i < len; i++)
//	{
//		numstr[i] = numcipher[i] - numkey[i];
//		if (numstr[i] < 0)
//		{
//			numstr[i] += 26;
//		}
//	}
//	printf("Chuoi da giai ma: \n");
//	for (i = 0; i < len; i++)
//	{
//		printf("%c", (numstr[i] + 'A'));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	char ban_ro[100], key[100], ban_mo[100];
//	int choice;
//
//	do 
//	{
//		printf("Menu:\n");
//		printf("1. Ma hoa\n");
//		printf("2. Giai ma\n");
//		printf("3. Thoat\n");
//		printf("Chon chuc nang: ");
//		scanf("%d", &choice);
//		getchar();
//
//		switch (choice) 
//		{
//		case 1:
//			printf("Nhap chuoi can ma hoa: \n");
//			fgets(ban_ro, sizeof(ban_ro), stdin);
//			ban_ro[strcspn(ban_ro, "\n")] = '\0'; 
//			do 
//			{
//				printf("Nhap khoa K:\n");
//				fgets(key, sizeof(key), stdin);
//				key[strcspn(key, "\n")] = '\0'; 
//				if (strlen(key) < strlen(ban_ro))
//					printf("Khoa k phai co do dai it nhat bang van ban. Nhap lai!");
//			} while (strlen(key) < strlen(ban_ro));
//			ma_hoa(ban_ro, key);
//			break;
//		case 2:
//			printf("Nhap chuoi can giai ma: \n");
//			gets_s(ban_mo);
//			do 
//			{
//				printf("Nhap khoa K:\n");
//				gets_s(key);
//				if (strlen(key) < strlen(ban_mo))
//					printf("Khoa k phai co do dai it nhat bang van ban. Nhap lai!");
//			} while (strlen(key) < strlen(ban_mo));
//			giai_ma(ban_mo, key);
//			break;
//		case 3:
//			printf("Ket thuc!\n");
//			break;
//		default:
//			printf("Lua chon khong hop le. Vui long chon lai!\n");
//		}
//	} while (choice != 3);
//
//	return 0;
//}
