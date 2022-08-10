#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mergesort();
void merge();

int main()
{
    int n,i;
    clock_t start,end;
	double time;
    printf("Enter the size of array: ");
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
	mergesort(arr,0,n-1);
	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nSorted Array: \n");
    for(i=0;i<n;i++)
        printf("\%d ",arr[i]);
        printf("\nTime taken to sort is %lf\n",time);
    return 0;
}

void mergesort(int arr[],int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(arr,low,mid);//For subarray 1
        mergesort(arr,mid+1,high);//For subarray 2
        merge(arr,low,mid,high);

    }
}

void merge(int arr[],int low,int mid,int high)
{
    int M[100000];
    int i,j,k;
    i=low;  j=mid+1;    k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
            M[k++]=arr[i++];
        else
            M[k++]=arr[j++];
    }
    if(i>mid)
    {
        while(j<=high)
            M[k++]=arr[j++];
    }
    else
    {
        while(i<=mid)
            M[k++]=arr[i++];
    }
    for(i=low;i<high;i++)
        arr[i]=M[i];
}
