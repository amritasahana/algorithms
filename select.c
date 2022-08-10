#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    int i,j,n,min,swap;
    clock_t start,end;
	double time;

    printf("\nEnter the number of elements:");
    scanf("%d",&n);

    int array[n];
    printf("\nEnter the elements in the array\n");
    for(i=0;i<n;i++)
    {
        //scanf("%d",&array[i]);
        array[i]=rand();
        printf("%d\t",array[i]);
    }
    //Implementation of selection sort
    start=clock();
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(array[j]<array[min])
            min=j;
        }
        if(min!=i)
        {
            swap=array[i];
            array[i]=array[min];
            array[min]=swap;
        }
    }
    end=clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThe sorted array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",array[i]);
        printf("\nTime taken to sort is %lf",time);
    return 0;


}
