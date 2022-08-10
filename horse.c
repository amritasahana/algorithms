    #include<stdio.h>
    #include<string.h>
	#include<time.h>
    #define MAX 500
    int t[MAX];
    void shifttable(char p[]) {
    	int i,j,m;
    	m=strlen(p);
    	for (i=0;i<MAX;i++)
    	  t[i]=m;
    	for (j=0;j<m-1;j++)
    	  t[p[j]]=m-1-j;
    }
    int horspool(char src[],char p[]) {
    	int i,j,k,m,n;
    	n=strlen(src);
    	m=strlen(p);
    	printf("\nLength of text=%d\n",n);
    	printf("\nLength of pattern=%d\n",m);
    	i=m-1;
    	while(i<n) {
    		k=0;
    		while((k<m)&&(p[m-1-k]==src[i-k]))
    		   k++;
    		if(k==m)
    		   return(i-m+1); else
    		   i+=t[src[i]];
    	}
    	return -1;
    }
    int main() {
    	char src[100];
		char p[100];
    	int pos;
		clock_t start,end;
		double time;
    	printf("---------------HARSEPOOL ALGORITHM-----------------\n");
    	printf("Enter the text in which pattern is to be searched:\n");

		scanf("%s",src);
    	printf("Enter the pattern to be searched:\n");

		scanf("%s",p);
		start=clock();
    	shifttable(p);
    	pos=horspool(src,p);
    	if(pos>=0)
    	  printf("\n\nThe desired pattern was found starting from position %d",pos+1);
		else
    	  printf("\n\nThe pattern was not found in the given text\n");
		end=clock();
		time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\nTotal time taken to match string is %lf secs",time);
    return 0;
	printf("--------------------------------------------------\n");
    }
