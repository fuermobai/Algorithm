#include <stdio.h>
int a[10],book[10],n,sum=0;

void dfs(int step)
{
	int i;
	if (step==n+1) {
		for (i = 1; i <=n; ++i) {
			printf("%d", a[i]);
		}
		printf("\n");
		sum++;

		return;
	}

	for (i = 1; i <=n; ++i) {
		if (book[i]==0) {
			a[step]=i;
			book[i]=1;


			dfs(step+1);
			book[i]=0;
		}
	}
	return ;
}

int main(void)
{
	scanf("%d",&n);
	dfs(1);
	printf("%d\n", sum);

	return 0;
}
