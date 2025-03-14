#include <iostream>

using namespace std;

void mangnghichthe(int a[], int b[], int n) 
{
    for (int i = 0; i < n; i++) b[i] = 0;
    for (int x = 1; x <= n; x++)
    {
        int vt = -1;
        for (int i = 0; i < n; i++) 
        {
            if (a[i] == x) 
            {
                vt= i;
                break;
            }
        }
        for (int j = 0; j < vt; j++) 
        {
            if (a[j] > x) 
            {
                b[x - 1]++;
            }
        }
    }
}
void timhoanvi(int b[], int a[], int n) 
{
    int da_chon[n + 1] = {0}; 
    for (int i = 0; i < n; i++) 
    {
        int dem = 0;
        for (int x = 1; x <= n; x++) 
        {
            if (!da_chon[x]) dem++;
            if (dem > b[i]) 
            { 
                a[i] = x;     
                da_chon[x] = 1; 
                break;
            }
        }
    }
}
void xuatmang(int a[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    int a[] = {5, 9, 1, 8, 2, 6, 4, 7, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int b[n];
    mangnghichthe(a, b, n);
    cout << "Mang nghich the B: ";
    xuatmang(b, n);
    timhoanvi(b, a, n);
    cout << "Hoan vi A tim duoc: ";
    xuatmang(a, n);
    return 0;
}
