#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include<string.h>
void menu()
{
    printf("\n1.Kiem tra chuoi co toan ky tu so hay khong");
    printf("\n2.Doi ky tu dau thanh hoa cac ki tu sau thanh ky tu thuong");
    printf("\n3.Xoa khoang trang thua");
    printf("\n4.Tim kiem ten trong chuoi ho ten");
    printf("\n5.Cat chuoi thanh 2 chuoi con");
    printf("\n6.Nhap danh sach va the hien ra man hinh");
}

void inputString(char* str, int size) {
    printf("Nhap vao mot chuoi: ");
    fgets(str, size, stdin);


    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
bool ktso(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            return true;
        s++;
    }
    return false;
}

int main() {
    char s[100];
    int lc;
    do
    {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        getchar();
        switch (lc)
        {
        case 1:
        {
            inputString(s, strlen(s));
            if (ktso(s) == true)
                printf("Chuoi chua toan ky tu so.\n");
            else
                printf("Chuoi khong chua toan ky tu so.\n");
        }break;
        }
    } while (lc < 7);


    return 0;
}