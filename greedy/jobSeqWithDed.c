#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job 
{
	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
} Job;

int compare(const void* a, const void* b)
{
	Job* temp1 = (Job*)a;
	Job* temp2 = (Job*)b;
	return (temp2->profit - temp1->profit);
}

void printJobScheduling(Job arr[], int n)
{

	qsort(arr, n, sizeof(Job), compare);
	
	int maxd=arr[0].dead;
	for(int i=0;i<n;i++)
	if(maxd<arr[i].dead)
	maxd=arr[i].dead;
	
	int result[maxd]; // To store result (Sequence of jobs)
	bool slot[maxd]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < maxd; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for(int i = 0; i < n; i++) 
	{
	    int index=arr[i].dead-1;
	    if(!slot[index])
	    {
	        slot[index]=true;
	        result[index]=arr[i].id;
	    }
	    else
	    {
	        index--;
	        while(index>=0)
	        {
	            if(!slot[index])
        	    {
        	        slot[index]=true;
        	        result[index]=arr[i].id;
        	        break;
        	    }
        	    else
        	    index--;
	        }
	    }
	}

	// Print the result
	for (int i = 0; i < maxd; i++)
		printf("%c ", result[i]);
}

// Driver code
int main()
{
    int n=5;
	Job arr[n]; 
	printf("enter id deadline profit of jobs : \n");
    for(int i = 0; i < n; i++)
        scanf("%s%d%d",&arr[i].id,&arr[i].dead,&arr[i].profit);
	printf(
		"Following is maximum profit sequence of jobs \n");

	// Function call
	printJobScheduling(arr, n);
	return 0;
}


