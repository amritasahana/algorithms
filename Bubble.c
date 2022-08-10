#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int n,i,j,temp;
	clock_t start,end;
	double time;

	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[n];

	//printf("\nEnter the elements in the array:\n");
	printf("\nRandom elements in the array are:\n");
	for(i=0;i<n;i++)
    {
	    //scanf("%d",&arr[i]);
		arr[i]=rand();
		printf("%d ",arr[i]);
	}

	start=clock();
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nSorted Array are: \n");

	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nTime taken to sort is %lf\n",time);
}
