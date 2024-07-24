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
}void NhapMaTran(int a[][100], int m, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = (rand() % 28);
        }
    }
}

void XuatMaTran(int a[][100], int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}
void sumdong(int m, int n, int a[][100]) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
        printf("\n Tong dong  %d: %d\n", i, sum);
    }
}
void maxcot(int m, int n, int a[][100]) {
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("\nMax cot  %d: %d", j, max);
    }
}
void printbien(int m, int n, int a[][100]) {
    printf("Bien tren : ");
    for (int j = 0; j < n; j++) {
        printf("%d ", a[0][j]);
    }
    printf("\n");

    printf("Bien duoi : ");
    for (int j = 0; j < n; j++) {
        printf("%d ", a[m - 1][j]);
    }
    printf("\n");

    printf("Bien trai : ");
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i][0]);
    }
    printf("\n");

    printf("Bien phai: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i][n - 1]);
    }
    printf("\n");
}
void xuatphantumax(int m, int n, int a[][100]) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }
    }
    printf("Phan tu max trong mang la %d ", max);
}
void xuatdongchan(int m, int n, int a[][100]) {
    for (int i = 0; i < n; i++) {
        int isEvenRow = 1;
        for (int j = 0; j < m; j++) {
            if (a[i][j] % 2 != 0) {
                isEvenRow = 0;
                break;
            }
        }
        if (isEvenRow == 1) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
        }
        
        }
}
int main()
{
    int lc;
    int a[100][100];
    int m, n;
    do {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        switch (lc)
        {
        case 1:
        {
            printf("nhap so hang m = ");
            scanf_s("%d", &m);
            printf("nhap so cot n = ");
            scanf_s("%d", &n);
            printf("nhap vao ma tran:\n");
            NhapMaTran(a, m, n);
            XuatMaTran(a, m, n);
        }break;
        case 2 :
        {
            printf("Tong gia tri tung dong la ");
            sumdong(m, n, a);

        }break;
        case 3:
        {
            printf("\nMax tung cot la ");
            maxcot(m, n, a);
        }break;
        case 4:
        {
            printbien(m, n, a);
        }break;
        case 5 :
        {
            xuatphantumax(m, n, a);
        }break;
        case 6 :
        {
            printf("Dong chi so chan la ");
            xuatdongchan(m, n, a);
        }break;
        }
    } while (lc < 8);
    return 0;
}