#include <stdio.h>
#define size 20
int a[size];
int max,min;

void minmax(int low,int high)
{
    if(high==low)
    min=max=a[high];
    else if(low==high-1)
    {
        if(a[high]>a[low])
        {
            max=a[high];
            min=a[low];
        }
        else
        {
            max=a[low];
            min=a[high];
        }
    }
    else
    {
        int mid=(high+low)/2;
        minmax(low,mid);
        int cmax=max;
        int cmin=min;
        minmax(mid+1,high);
        if(cmin<min)
        min=cmin;
        if(cmax>max)
        max=cmax;
        
    }
}

int main()
{
    int i, n;
    printf ("\nEnter n : ");
    scanf ("%d",&n);
    printf ("Enter array : \n");
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);

    max = a[0];
    min = a[0];
    minmax(1, n);
     printf ("Minimum element in an array : %d\n", min);
     printf ("Maximum element in an array : %d\n", max);

    return 0;
}
