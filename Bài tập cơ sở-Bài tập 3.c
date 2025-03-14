#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>
void Sift(int a[], int p, int q, int *ss);
void Partition(int a[], int p, int q, int *ss, int *hv);
void Taomang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
	    a[i]=rand()%10000;
	}
}
void Xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
void Hoanvi(int *a,int *b,int *hv)
{
    int t=*a;
        *a=*b;
        *b=t;
    (*hv)++;
}
void interchange(int a[],int n)
{
    int ss=0;
    int hv=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ss++;
            if(a[i]>a[j])
            {
                Hoanvi(&a[i],&a[j],&hv);
            }
        }
    }
    printf("Interchange Sort - So sanh: %d, Hoan vi: %d\n", ss, hv);
}
int minx(int a[],int x,int n, int *ss)
{
    int min=x;
    for(int i=x+1;i<n;i++)
    {
        (*ss)++;
       if(a[i]<a[min])
       {
           min=i;
       }
    }
    return min;
}
void selection(int a[],int n)
{
    int hv=0;
    int ss=0;
  for(int i=0;i<n;i++)
  {
    int b=minx(a,i,n,&ss);
    {
        Hoanvi(&a[i],&a[b],&hv);
    }
  }
   printf("Selection Sort - So sanh: %d, Hoan vi: %d\n", ss, hv);
}
void insertion(int a[],int n)
{
    int hv=0;
    int ss=0;
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int x=a[i];
        while((j>=0)&&a[j]>x)
        {
            ss++;
            a[j+1]=a[j];
            hv++;
            j--;
        }
        a[j+1]=x;
    }
    printf("Insertion Sort - So sanh: %d, Hoan vi: %d\n", ss, hv);
}
void bubble(int a[],int n)
{
    int ss=0; int hv=0;
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            ss++;
            if (a[j] > a[j+1])
            {
                Hoanvi(&a[j],&a[j+1],&hv);
            }
        }
    }
    printf("Bubble Sort - So sanh: %d, Hoan vi: %d\n", ss, hv);
}
void Heap(int a[], int n)
{
    int hv=0;
    int ss=0;
    int k = n / 2 - 1;
    for (int i = k; i >= 0; i--)
    {
        Sift(a, i, n-1,&ss);
    }
    for (int i = n-1; i > 0; i--)
    {
        hv++;
        Hoanvi(&a[0], &a[i],&hv);
        Sift(a, 0, i-1,&ss);
    }
}
void Sift(int a[], int p, int q,int *ss)
{
    int x=a[p];
    int i=p;
    int j=2*i+1;
    bool cont = true;
    while((j<=q)&& cont)
    {
        (*ss)++;
        if(j<q)
        {
            if(a[j]<a[j+1])
            {
                j+=1;
            }
        }
        if(x<a[j])
        {
            a[i]=a[j];
            i=j;
            j=j*2+1;
        }
        else
        {
            cont = false;
        }
    }
    a[i]=x;
}
void QuickSort(int a[], int n)
{
    int ss=0;
    int hv=0;
    Partition(a, 0, n-1, &ss, &hv);
    printf("Quick Sort - So sanh: %d, Hoan vi: %d\n", ss, hv);
}
void Partition(int a[], int p, int q ,int *ss,int *hv)
{
    int x=a[(p+q)/2];
    int i=p;
    int j=q;
    do
    {
        while(a[i]<x)
        {
            i++;
            (*ss)++;
        }
        while(a[j]>x)
        {
            j--;
            (*ss)++;
        }
        if(i<=j)
        {
            Hoanvi(&a[i],&a[j],&hv);
            i++;
            j--;
        }
    }
    while(i>j);
    if(p<j)
    {
        Partition(a,p,j,ss,hv);
    }
    if(i<q)
    {
        Partition(a,i,q,ss,hv);
    }
}
double Time(void (*sortFunction)(int[], int), int a[], int n)
{
    int *temp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i];
    }
    clock_t bd, kt;
    bd = clock();
    sortFunction(a, n);
    kt = clock();
    free(temp);
    return ((double)(kt - bd)) / CLOCKS_PER_SEC;
}
void ThucNghiem(void (*sortFunction)(int[], int), char *sortName) 
{
    int sizes[] = {10, 100, 200, 500, 1000, 5000, 10000};
    int t = 5;
    printf("\nThực nghiệm với thuật toán %s:\n", sortName);
    printf("%-10s %-15s\n", "n", "Thời gian (s)");

    for (int s = 0; s < sizeof(sizes) / sizeof(sizes[0]); s++) 
    {
        int n = sizes[s];
        double total_time = 0;
        for (int i = 0; i < t; i++) 
        {
            int a[n];
            Taomang(a, n);
            total_time += Time(sortFunction, a, n);
        }
        printf("%-10d %-15f\n", n, total_time / t);
    }
}
int main() {
    srand(time(NULL));
    ThucNghiem(interchange, "Interchange Sort");
    ThucNghiem(selection, "Selection Sort");
    ThucNghiem(insertion, "Insertion Sort");
    ThucNghiem(bubble, "Bubble Sort");
    ThucNghiem(Heap, "Heap Sort");
    ThucNghiem(QuickSort, "Quick Sort");
    return 0;
}