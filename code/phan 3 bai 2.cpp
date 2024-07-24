#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
    printf("\n1.Tao va xuat ma tran a co thanh phan ngau nhien cap lon hon 5");
    printf("\n2.Xuat cac phan tu tren duong cheo chinh");
    printf("\n3.Xuat cac phan tu thuoc duong cheo chinh va song song");
    printf("\n4.Tim phan tu max tren duong cheo chinh");
    printf("\n5.Sap xep ma tran theo kieu zic zac");
    printf("\n6.Sap xep duong cheo chinh tang dan tu tren xuong ");
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
void xuatduongcheoching(int m, int n, int a[][100]) {
    printf("Main diagonal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}
int main()
{
    int a[100][100];
    int lc, m, n;
    do {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        switch (lc)
        {
        case 1:
        {
            printf(" So dong ");
            scanf_s("%d", &m);
            printf(" So cot ");
            scanf_s("%d", &n);
            NhapMaTran(a, m, n);
            XuatMaTran(a, m, n);
        }break;
        case 2:
        {
            printf("\nDuong cheo chinh ");
            xuatduongcheoching(m, n, a);
        }break;
        }
    } while (lc);
    return 0;
}