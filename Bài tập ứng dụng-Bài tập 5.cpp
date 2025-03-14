#include<iostream>
using namespace std;
void nhap(int a[50][100],int &m, int &n)
{
    cout<<"nhập vào số dòng :";
    cin>>m;
    cout<<"nhập vào số cột :";
    cin>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"nhập vào phần tử :";
            cin>>a[i][j];
        }
    }
}
void xuat(int a[50][100],int &m, int &n)
{
    cout<<"mảng đã nhập là :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int Tongdong(int a[50][100],int n,int k)
{
    int s=0;
    for(int j=0;j<n;j++)
    {
        s+=a[k][j];
    }
    return s;
}
void maxdong(int a[50][100],int m,int n)
{
    int maxx=-99999;
    int vt=0;
    for(int i=0;i<m;i++)
    {
        int d=Tongdong(a,n,i);
        if(maxx<d)
        {
            maxx=d;
            vt=i;
        }
    }
    cout<<"Dong co tong lon nhat la dong thu :"<<vt<<endl;
}
void SapXepDong(int a[50][100], int m, int n) {
    for (int i = 0; i < m - 1; i++) 
    {
        for (int j = i + 1; j < m; j++) 
        {
            if (Tongdong(a, n, i) < Tongdong(a, n, j))
            {
                for (int k = 0; k < n; k++) 
                {
                    swap(a[i][k], a[j][k]);
                }
            }
        }
    }
}

int main()
{
    int a[50][100];
    int n,m;
    nhap(a,m,n);
    xuat(a,m,n);
    maxdong(a,m,n);
    SapXepDong(a,m,n);
    cout<<"Mang sau khi sap xep :";
    xuat(a,m,n);
    return 0;
    
}