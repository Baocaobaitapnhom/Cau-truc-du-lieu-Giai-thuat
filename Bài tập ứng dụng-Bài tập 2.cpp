#include<iostream>
using namespace std;
struct SoHang
{
    double heSo;
    int bac;
};
void Nhap(SoHang a[], int &n)
{
    cout<<"Nhap so luong so hang : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<" Nhap he so va bac cua so hang thu "<<i<<" :";
        cin>>a[i].heSo>>a[i].bac;
    }
}
void Hoanvi(SoHang &a,SoHang &b)
{
    SoHang t=a;
           a=b;
           b=t;
}
void SapXep(SoHang a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minx=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j].bac<a[minx].bac)
            {
                minx=j;
            }
        }
        if(minx != i)
        {
            Hoanvi(a[i],a[minx]);
        }
    }
}
int main()
{
    int n;
    SoHang a[100];
    Nhap(a,n);
    SapXep(a,n);
    cout<<"Day sau khi sap xep la :";
    for(int i=0;i<n;i++)
    {
        cout<<a[i].heSo<<"x^"<<a[i].bac<<endl;
    }
    return 0;
}