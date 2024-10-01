#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 26

// Hàm mã hóa 
char* ma_hoa(const char* ban_ro, const char* key)
{
    char* van_ban_duoc_ma_hoa = (char*)malloc(strlen(ban_ro) + 1);
    if (van_ban_duoc_ma_hoa == NULL)
    {
        printf("Loi! \n");
        exit(EXIT_FAILURE);
    }

    int key_index = 0;
    for (size_t i = 0; i < strlen(ban_ro); i++)
    {
        if (isalpha(ban_ro[i]))
        {
            char key_char = key[key_index % strlen(key)];
            int shift = toupper(key_char) - 'A';

            if (islower(ban_ro[i]))
            {
                van_ban_duoc_ma_hoa[i] = ((ban_ro[i] - 'a' + shift) % SIZE) + 'a';
            }
            else
            {
                van_ban_duoc_ma_hoa[i] = ((ban_ro[i] - 'A' + shift) % SIZE) + 'A';
            }
            key_index++;
        }
        else
        {
            van_ban_duoc_ma_hoa[i] = ban_ro[i];
        }
    }
    van_ban_duoc_ma_hoa[strlen(ban_ro)] = '\0';

    return van_ban_duoc_ma_hoa;
}

// Hàm giải mã 
char* giai_ma(const char* van_ban_duoc_ma_hoa, const char* key)
{
    char* van_ban_duoc_giai_ma = (char*)malloc(strlen(van_ban_duoc_ma_hoa) + 1);
    if (van_ban_duoc_giai_ma == NULL)
    {
        printf("Loi! \n");
        exit(EXIT_FAILURE);
    }

    int key_index = 0;
    for (size_t i = 0; i < strlen(van_ban_duoc_ma_hoa); i++)
    {
        if (isalpha(van_ban_duoc_ma_hoa[i]))
        {
            char key_char = key[key_index % strlen(key)];
            int shift = toupper(key_char) - 'A';

            if (islower(van_ban_duoc_ma_hoa[i]))
            {
                van_ban_duoc_giai_ma[i] = ((van_ban_duoc_ma_hoa[i] - 'a' - shift + SIZE) % SIZE) + 'a';
            }
            else
            {
                van_ban_duoc_giai_ma[i] = ((van_ban_duoc_ma_hoa[i] - 'A' - shift + SIZE) % SIZE) + 'A';
            }
            key_index++;
        }
        else
        {
            van_ban_duoc_giai_ma[i] = van_ban_duoc_ma_hoa[i];
        }
    }
    van_ban_duoc_giai_ma[strlen(van_ban_duoc_ma_hoa)] = '\0';

    return van_ban_duoc_giai_ma;
}
int main()
{
    char ban_ro[100];
    char key[100];
    char ban_mo[100];
    int choice;
    char* van_ban_duoc_ma_hoa = NULL;
    char* van_ban_duoc_giai_ma = NULL;
    do 
    {
        printf("Menu:\n");
        printf("1. Ma hoa\n");
        printf("2. Giai ma\n");
        printf("3. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar(); // Đọc ký tự thừa '\n' sau khi nhập lựa chọn
        switch (choice) 
        {
        case 1:
            printf("Nhap chuoi can ma hoa: \n");
            gets_s(ban_ro);
            printf("Nhap khoa K:\n");
            gets_s(key);
            ma_hoa(ban_ro, key);
            van_ban_duoc_ma_hoa = ma_hoa(ban_ro, key);
            printf("Van ban duoc ma hoa: %s\n", van_ban_duoc_ma_hoa);
            break;
        case 2:
            printf("Nhap chuoi can giai ma: \n");
            gets_s(ban_mo);
            printf("Nhap khoa K:\n");
            gets_s(key);
            giai_ma(ban_mo, key);

            van_ban_duoc_giai_ma = giai_ma(ban_mo, key);
            printf("Van ban duoc giai ma: %s\n", van_ban_duoc_giai_ma);
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
