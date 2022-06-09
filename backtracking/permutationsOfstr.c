#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int low, int high)
{
    int i;
    if (low == high)
        printf("%s\n", a);
    else
    {
        for (i = low; i <= high; i++)
        {
            swap((a + low), (a + i));
            permute(a, low + 1, high);
            swap((a + low), (a + i));
        }
    }
}

int main()
{
    printf("Enter the String :");
    char str[10];
    gets(str);
    //printf("%s\n", str);

    int n = strlen(str);
    permute(str,0,n-1);
    return 0;
}