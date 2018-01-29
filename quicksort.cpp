#include <stdio.h>
int a[101],n;

void quicksort(int left,int right){
	int i,j,t,temp;
	if(left>right)
		return;

	temp=a[left];
	i=left;
	j=right;
	while (i!=j) {
		while (a[j]>=temp && i<j) {
			j--;
		}
		while (a[i]<=temp && i<j) {
			i++;
		}

		if (i<j) {
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}

	a[left]=a[i];
	a[i]=temp;

//	for (i = 1; i <=n; ++i) {
//		printf("%d ",a[i]);
//	}

//跟从做还是从右没有关系
	quicksort(left,i-1);
//	for (i = 1; i <=n; ++i) {
//		printf("%d ",a[i]);
//	}


	quicksort(i+1,right);
//	for (i = 1; i <=n; ++i) {
//		printf("%d ",a[i]);
//	}
}


int main(void)
{
	int i;
	scanf("%d",&n);
	for (i = 1; i <=n; ++i) {
		scanf("%d",&a[i]);
	}
	quicksort(1,n);


	for (i = 1; i <=n; ++i) {
		printf("%d ",a[i]);
	}
	return 0;
}
