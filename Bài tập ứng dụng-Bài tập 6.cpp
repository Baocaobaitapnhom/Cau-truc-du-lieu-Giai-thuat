#include <iostream>
using namespace std;
void hoanDoi(int &a, int &b) {
    int tam = a;
    a = b;
    b = tam;
}
void sapXepTang(int a[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (a[i] > a[j]) 
            {
                hoanDoi(a[i], a[j]);
            }
        }
    }
}

// Hàm sắp xếp giảm dần
void sapXepGiam(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j]) 
            {
                hoanDoi(a[i], a[j]);
            }
        }
    }
}
void sapXepMang(int mang[], int n)
{
    int chan[100], le[100]; 
    int soLuongChan = 0, soLuongLe = 0;
    for (int i = 0; i < n; i++)
    {
        if (mang[i] % 2 == 0 && mang[i] != 0) 
        {
            chan[soLuongChan++] = mang[i];
        } else if (mang[i] % 2 == 1) 
        {
            le[soLuongLe++] = mang[i];
        }
    }
    sapXepTang(chan, soLuongChan);
    sapXepGiam(le, soLuongLe);
    int viTriChan = 0, viTriLe = 0;
    for (int i = 0; i < n; i++) 
    {
        if (mang[i] == 0) continue; 
        if (mang[i] % 2 == 0) 
        {
            mang[i] = chan[viTriChan++];
        } else
        {
            mang[i] = le[viTriLe++];
        }
    }
}
int main()
{
    int mang[] = {0, 3, 1, 4, 2, 5, 0, 6, 7, 8}; 
    int n = sizeof(mang) / sizeof(mang[0]); 
    sapXepMang(mang, n); 
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) 
    {
        cout << mang[i] << " ";
    }

    return 0;
}
