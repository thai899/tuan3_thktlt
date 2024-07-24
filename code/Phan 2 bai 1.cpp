#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
    printf("\n1.Tao va xuat ma tran a co thanh phan ngau nhien");
    printf("\n2.Tinh va xuat tong gia tri tung dong");
    printf("\n3.Xuat phan tu lon nhat tren tung cot");
    printf("\n4.Xuat cac phan tu thuoc phan bien tren duoi trai phai");
    printf("\n5.Xuat cac phan tu cuc dai");
    printf("\n6.Xuat dong chi chua so chan");
    printf("\n7.Sap xep mang a tang theo tung dong");
}void NhapMaTran(int a[][100], int n, int m)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = (rand() % 28);
        }
    }
}

void XuatMaTran(int a[][100], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}
int main()
{
    int lc;
    int a[100][100];
    do {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        switch (lc)
        {
        case 1:
        {
            int m, n;
            printf("nhap so hang m = ");
            scanf_s("%d", &m);
            printf("nhap so cot n = ");
            scanf_s("%d", &n);
            printf("nhap vao ma tran:\n");
            NhapMaTran(a, n, m);
            XuatMaTran(a, n, m);
        }break;
        }
    } while (lc < 8);
    return 0;
}