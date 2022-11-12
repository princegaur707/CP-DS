#include <bits/stdc++.h>
#define l 5555555
int ehPrimo[l];
int main(void) {
	for(int i=2;i<l;i++)
		if(ehPrimo[i]==0)
			for(int j=i;j<=l;j+=i)
				ehPrimo[j]=ehPrimo[j/i]+1;
	for(int i=1;i<=l;i++)
		ehPrimo[i]+=ehPrimo[i-1];
		int t;
	scanf("%d",&t);
	while(t--)
	{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d \n",(ehPrimo[a]-ehPrimo[b]));
	}
	return 0;
}
  