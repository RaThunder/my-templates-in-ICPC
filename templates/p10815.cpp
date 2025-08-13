#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}

int n,a,sum;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a=read();
		sum+=a;
	}
	write(sum);
	return 0;
}
