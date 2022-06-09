#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job 
{
	char id; // Job Id
	int weight; // weight of job
	float profit; // Profit if job is over before or on deadline
	float ratio;
} Job;

int compare(const void* a, const void* b)
{
	Job* temp1 = (Job*)a;
	Job* temp2 = (Job*)b;
	return (temp2->ratio - temp1->ratio);
}

void printkpsc(Job arr[], int n,int c)
{
	qsort(arr, n, sizeof(Job), compare);
	float profit=0;
	int i=0;
	int knps[n];
	for(int i=0;i<n;i++)
	knps[i]=-1;
	
	while(i<n && c!=0)
	{
	    if(arr[i].weight<c)
	    {
	        c=c-arr[i].weight;
	        profit=profit+arr[i].profit;
	        knps[i]=arr[i].id;
	        i++;
	    }
	    else
	    {
	        profit=profit+((float)c/(float)arr[i].weight)*arr[i].profit;
	        knps[i]=arr[i].id;
	        c=0;
	        i++;
	    }
	}
	printf("max profit : %f\n",profit);
	for(i=0;i<n;i++)
	printf("%c  ",knps[i]);

}
//a 10 60
//b 20 100
//c 30 120

// Driver code
int main()
{
    int n=3;
    int c;
    scanf("%d",&c);
	Job arr[n]; 
	printf("enter id weight profit of jobs : \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%s%d%f",&arr[i].id,&arr[i].weight,&arr[i].profit);
        arr[i].ratio=arr[i].profit/arr[i].weight;
    }
    
	printf("Following is maximum profit sequence of jobs \n");
	printkpsc(arr, n,c);
	return 0;
}


