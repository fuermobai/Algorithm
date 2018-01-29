#include <stdio.h>

#define QUEENS 15
#define IS_OUTPUT 1

int A[QUEENS*3],B[QUEENS*3],C[QUEENS*3],k[QUEENS+1][QUEENS+1];
int inc,*a=&A[QUEENS],*b=&B[QUEENS],*c=&C[QUEENS];
void lay(int i){
	int j=0,t,u;

	while (++j<=QUEENS ) {
		if (a[j]+b[j-i]+c[j+i]==0) {
			k[i][j]=a[j]=b[j-i]=c[j+i]=1;
			if (i<QUEENS ) {
				lay(i+1);
			} else {
				++inc;
				if (IS_OUTPUT ) {
					for(printf("(%d)\n",inc),u=QUEENS+1;--u;printf("\n"))
						for(t=QUEENS+1;--t;)
							k[t][u]?printf("Q "):printf("+ ");
					printf("\n\n\n");
				}
			}
			a[j]=b[j-i]=c[j+i]=k[i][j]=0;
		}
	}
}

int main(void)
{
	lay(1);
	printf(" %d Queens has %d Solves\n", QUEENS,inc);
	return 0;
}
