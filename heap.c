#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

int main()
{
    int i,n,a[MAX];
    clock_t start,end;
    double time;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements in array\n");
    for(i=1;i<=n;i++)
    {
        a[i]=rand();
        printf("%d  ",a[i]);
    }


    heapify(a,n);
    start=clock();
    heapsort(a,n);
    end=clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThe sorted elements are:\n");
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);
    printf("\nTime taken to sort is %lf",time);

    return 0;
}

int heapify(int a[MAX],int n)
{
    int i,j,k,v,flag;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        flag=0;
        while(!flag && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                    j=j+1;
            }
            if(v>=a[j])
                flag=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }

}
void heapsort(int a[MAX],int n)
{
    int i,temp;
    for(i=n;i>1;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapify(a,i-1);
    }
}
