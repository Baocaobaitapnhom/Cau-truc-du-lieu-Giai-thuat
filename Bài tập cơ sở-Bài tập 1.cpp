#include <iostream>
#include <algorithm> 
using namespace std;
void Nhapmang(int a[], int &n)
{
	cout << " Vui long nhap so phan tu cua mang : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap phan tu thu a[" << i << "]: ";
		cin >> a[i];
	}
}
void Xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void Hoanvi(int &a,int &b)
{
    int t=a;
        a=b;
        b=t;
}
void interchange(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                Hoanvi(a[i],a[j]);
            }
        }
    }
}
int minx(int a[],int x,int n)
{
    int min=x;
    for(int i=x+1;i<n;i++)
    {
       if(a[i]<a[min])
       {
           min=i;
       }
    }
    return min;
}
void selection(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
      int b=minx(a,i,n);
      {
        Hoanvi(a[i],a[b]);
      }
  }
}
void insertion(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int x=a[i];
        while((j>=0)&&a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}
void bubble(int a[],int n)
{
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                Hoanvi(a[j],a[j+1]);
            }
        }
    }
}
int main()
{
	int n;
	int a[50];
	int b[50];
	Nhapmang(a, n);
	
	cout<<"Mang vua nhap la :";
	Xuatmang(a, n);
	cout<<endl;
	
	copy(a, a + n, b);
	interchange(b,n);
	cout<<"Mang sau Interchange sort : ";
	Xuatmang(b,n);
	cout<<endl;
	
	copy(a, a + n, b);
	selection(b,n);
	cout<<"Mang sau Selection   sort : ";
	Xuatmang(b,n);
	cout<<endl;
	
	copy(a, a + n, b);
	insertion(b,n);
	cout<<"Mang sau Insertion   sort : ";
	Xuatmang(b,n);
	cout<<endl;
	
	copy(a, a + n, b);
	bubble(b,n);
	cout<<"Mang sau Bubble      sort : ";
	Xuatmang(b,n);
	return 0;
}