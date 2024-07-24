#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
    printf("\n1.Tao va xuat ma tran a co thanh phan ngau nhien cap lon hon 5");
    printf("\n2.Xuat cac phan tu tren duong cheo chinh");
    printf("\n3.Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh");
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
void xuatduongcheochinh(int m, int n, int a[][100]) {
    printf("Main diagonal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}
void xuatduongsongsong(int m,int n, int a[][100]) {
    
    for (int k = 1; k < n; k++) {
  
        printf("Phia tren duong cheo chinh voi k = %d: ", k);
        for (int i = 0; i < n - k; i++) {
            printf("%d ", a[i][i + k]);
        }
        printf("\n");

       
        printf("Duoi duong cheo chinh voi k = %d: ", k);
        for (int i = 0; i < n - k; i++) {
            printf("%d ", a[i + k][i]);
        }
        printf("\n");
    }
}
int phantumaxthuoctamgiacduongcheochinh(int n, int m, int a[][100]) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] > max)
        {
            max = a[i][i];
        }
    }
    return max;
}
void zigzagSort(int n, int a[][100]) {
    int x = n * n;
    int temp[x];
    int index = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[index++] = a[i][j];
        }
    }


    for (int i = 0; i < x - 1; i++) {
        for (int j = i + 1; j < x; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }


    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[index++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }
}
void tangdanduongcheochinh(int n, int a[][100]) {

    int diag[5];
    for (int i = 0; i < n; i++) {
        diag[i] = a[i][i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diag[i] > diag[j]) {
                int temp = diag[i];
                diag[i] = diag[j];
                diag[j] = temp;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        a[i][i] = diag[i];
    }
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
        case 3 :
        {
            printf("\nDuong song song voi cheo chinh");
            xuatduongsongsong(m, n, a);
        }break;
        case 4:
        {
            printf("\nPhan tu max tren duong tam giac cheo chinh la : %d ", phantumaxthuoctamgiacduongcheochinh(m, n, a));
        }break;
        case 5:
        {
            printf("\nZigzag sorted matrix:\n");
            zigzagSort(n, a);
            XuatMaTran(a, m, n);

        }break;
        case 6:
        {
            printf("Duong cheo chinh tang dan:\n ");
            tangdanduongcheochinh(n, a);
            XuatMaTran(a, m, n);

        }break;
        }
    } while (lc);
    return 0;
}