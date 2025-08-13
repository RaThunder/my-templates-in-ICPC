#include <bits/stdc++.h>
using namespace std;
#define int long long

void tb()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int N=2e5+9;
int pre[N],n,m;

int root(int x)
{
	return pre[x]=(pre[x]==x?x:root(pre[x]));
}

signed main()
{
	tb();
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		pre[i]=i;
	while(m--)
	{
		int z,x,y;
		cin>>z>>x>>y;
		if(z==1)
			pre[root(x)]=root(y);
		else
		{
			if(root(x)==root(y))
				cout<<"Y\n";
			else
				cout<<"N\n";
		}
	}
	return 0;
}
