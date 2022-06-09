#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define max 5
int a[max];

int partition(int a[],int start,int end)
{

int pivot=a[start],p1=start+1,i,temp;

for(i=start+1;i<=end;i++)
{

if(a[i]<pivot)
    {
        if(i!=p1)
      {  
            temp=a[p1];
            a[p1]=a[i];
            a[i]=temp;
      }    p1++;
    }
}

        a[start]=a[p1-1];
        a[p1-1]=pivot;

return p1-1;
}



void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
      int p=partition(a,l,h);
      quicksort(a,l,p);
      quicksort(a,p+1,h);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    clock_t tic = clock();
    quicksort(a,0,n-1);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    
    for(int i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}

