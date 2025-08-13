#include <bits/stdc++.h>
using namespace std;
#define int long long

void tb()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n,q;
map<int,map<int,int>> mp;

signed main()
{
	tb();
	cin>>n>>q;
	while(q--)
	{
		int a,x,y,k;
		cin>>a>>x>>y;
		if(a==1)
		{
			cin>>k;
			mp[x][y]=k;
		}
		else
			cout<<mp[x][y]<<endl;
	}
	return 0;
}
