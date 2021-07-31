#include <stdio.h>
#include <stdlib.h>
#include <cmath>

void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap vao phan tu a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

//Phan tu lon nhat cua mang
int max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}

//Phan tu nho nhat cua mang
int min(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (min > a[i])
            min = a[i];
    return min;
}

//Ting tong cac phan tu trong mang
long int S(int a[], int n)
{
    long int temp = 0;
    for (int i = 0; i < n; i++)
        temp += a[i];
    return temp;
}

//Tinh trung binh cong
int average(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    float tb = sum / n;
    return tb;
}

//Kiem tra co phan tu trong mang co phai la so nguyen to
bool isPrime(int x)
{
     if (x < 2)
        return false;
    for (int i = 2; i <= x / 2; i++)
        if (x % i == 0)
            return false;
    return true;
}

//Tinh tong cua cac phan tu la so nguyen to trong mang
int primesSum(int a[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
        if (isPrime(a[i]) == true)
            tong = tong + a[i];
    return tong;
    return -1;
}

//Tinh so luong phan tu la so nguyen to trong mang
int primesCount(int a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            cnt++;
        }
    }
    return cnt;
}

//Phan tu am lon nhat cua mang
int findMaxNegative(int a[], int n)
{
    int ln;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            ln = a[i];
            for (int j = 0; j < n; j++)
            {
                if (a[j] > ln && a[j] < 0)
                    ln = a[j];
            }
        }
    }
    return ln;
}

//Phan tu duong nho nhat cua mang
int findMinPositive(int a[], int n)
{

    int i, min;

    for (i = 0; i < n; i++)
    {

        if (a[i] > 0)
        {

            min = a[i];

            break;
        }
    }

    for (i = 0; i < n; i++)
    {

        if (a[i] > 0 && a[i] < min)

            min = a[i];
    }

    return min;
}

//Tong cac phan tu co can bac hai nguyen
bool squareRootSum(int n)
{
    int tam = (int)sqrt(n);
    if (tam * tam == n)
        return true;
    else
        return false;
}

//Gom cac so le, tong cong co bao nhieu so le
int SumOdd(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            sum += a[i];
        }
    }
    return sum;
}

//Gom cac so chan, tong cong co bao nhieu so chan
int SumEven(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            continue;
        }
        sum += a[i];
    }
    return sum;
}
// Kiem tra tinh doi xung cua mang
int isSymmetric(int a[], int n)
{
    int co = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
            co = 0;
    }
    return co;
}

int findFirstPrime(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (isPrime(a[i]) == 1)
            return a[i];
    return -1;
}

int main()
{
    int a[999];
    int n;
    printf("\nNhap n = ");
    scanf("%d", &n);
    nhap(a, n);
    printf("\nMax = %d", max(a, n));
    printf("\nMin = %d", min(a, n));
    printf("\nTong mang = %d", S(a, n));
    printf("\nKQ Trung binh cong la: %d", average(a, n));
    printf("\nTong cac SNT trong mang la %d", primesSum(a, n));
    printf("\nMang co %d SNT!", primesCount(a, n));
    printf("\nPhan tu am lon nhat la: %d", findMaxNegative(a, n));
    printf("\nPhan tu duong nho nhat: %d", findMinPositive(a, n));
    printf("\nTong so le = %d", SumOdd(a, n));
    printf("\nTong so chan = %d", SumEven(a, n));
    if (isSymmetric(a, n) == 0)
        printf("\nKhong phai mang doi xung ");
    else
        printf("\nLa mang doi xung");
    printf("\nSNT dau tien la: %d", findFirstPrime(a, n));
    system("pause");
    return 0;
}