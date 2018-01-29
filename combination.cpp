#include <iostream>
#include <cstdio>
using namespace std;

namespace comb{
	int n,k;
	int arr[12];
	int count;
	bool arrsame(int site){
		if(site>0 && arr[site-1]>=arr[site])
			return 0;
		return 1;
	}
	inline void arrprint(){
		for (int  i = 0; i < k; i++) {
			printf("%3d\n",arr[i]);
		}
		puts("");
		count++;
	}
	void calculate(int now){
		if (now==k) {
			arrprint();
			return;
		}
		for (int i = 0; i < n; ++i) {
			arr[now]=i;
			if (arrsame(now)) {
				calculate(now+1);
			}
		}
	}
	inline void run(int nn,int kk){
		n=nn,k=kk;
		count=0;
		if (k<12 && n>=k && k>0) {
			calculate(0);
		}
		if (count ) {
			printf("\n%d combination.\n\n",count );
		} else {
			puts("Input error!");
		}
	}
}
int main(void)
{
	int n,k;
	while (scanf("%d%d",&n,&k)!=EOF) {
		comb::run(n,k);
		fflush(stdout);
	}
	return 0;
}
