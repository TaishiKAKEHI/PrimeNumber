#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 1000000000
int main(void){
	printf("Until %d PrimeNumbers Calculation Time is ",N);
	clock_t start,end;
  	start = clock();
	static unsigned char prime[N+1];
	int i,j,limit,flag;
	for(i=2; i<=N; i++)
		prime[i]=1;
	limit=(int)sqrt(N);
	for(i=2; i<=limit; i++){
		if (prime[i]==1){
			for(j=2*i; j<=N; j+=i)
				prime[j]=0;
		}
	}
	end = clock();
  	printf("%.3f[sec]\n",(double)(end-start)/CLOCKS_PER_SEC);
	printf("Output PrimeNumbers List?(Y:1,N:0)--->");
	scanf("%d",&flag);
	if(flag == 1){
		FILE *outfile;
		outfile = fopen("PrimeNumberList.txt","w");
		if (outfile == NULL) {
    		printf("cannot open\n");
    		exit(1);
  		}
		for(i=2,j=1; i<=N; i++){
			if(prime[i]==1){
				fprintf(outfile,"[%d] %d\n",j,i);
				j++;
			}
		}
	}
return 0;
}