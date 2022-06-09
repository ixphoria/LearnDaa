#include <stdio.h>
#define inf 99999999

int min(int a, int b)
{
	return (a > b) ? b : a;
}

int coinc(int W,int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
		    if(i==0)
		        K[i][w]=inf;
			else if (w == 0)
				K[i][w] = 0;
			else if (val[i - 1] <= w)
				K[i][w] = min(1+ K[i][w - val[i - 1]],K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

// Driver Code
int main()
{
	int val[] = {1,2,3};
	int W = 10;
	int n = sizeof(val) / sizeof(val[0]);
	printf("%d", coinc(W, val, n));
	return 0;
}


