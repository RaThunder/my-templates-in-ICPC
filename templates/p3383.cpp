#include <bits/stdc++.h>
using namespace std;

#define M 100000005
int n,q;
long long a[M],cnt,c[M];
bool b[M];

void ou(int x)
{
	b[0]=1;
	b[1]=1;
	for(int i=2;i<=x;++i)
	{
		if(b[i]==0)
		{
			a[cnt]=i;
			cnt++;
		}
		for(int j=0;i*a[j]<=x&&j<cnt;++j)
		{
			b[i*a[j]]=1;
			if(i%a[j]==0)
				break;
		}
	}
}

int main()
{
	cin>>n>>q;
	ou(n);
	for(int i=0;i<q;++i)
		cin>>c[i];
	for(int i=0;i<q;++i)
		cout<<a[c[i]-1]<<endl;
	return 0;
}
