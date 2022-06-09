#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define max 5
int a[max];

void merge(int a[],int l,int m,int h)
{
    int n1=m-l+1,n2=h-m;
    int la[n1],ra[n2];
    
    for(int i=0;i<n1;i++)
    la[i]=a[l+i];
    for(int i=0;i<n2;i++)
    ra[i]=a[m+1+i];
    
    int li=0,ri=0,i=l;
    while(li<n1 && ri<n2)
    {
       if(la[li]<=ra[ri])
       {
           a[i]=la[li];
           li++;
           i++;
       }
       else
       {
           a[i]=ra[ri];
           ri++;
           i++;
       }
    }
    while(li<n1)
    {
        a[i]=la[li];
        li++;
        i++;
    }
    while(ri<n2)
    {
        a[i]=ra[ri];
        ri++;
        i++;
    }
}
void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    clock_t tic = clock();
    mergesort(a,0,n-1);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    
    
    for(int i=0;i<n;i++)
    printf("%d\t",a[i]);

    return 0;
}

