#include <bits/stdc++.h>
using namespace std;
#define int long long

void tb()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int N=5e3+9;
int n,m;
struct Edge
{
	int x,y,z;
	/*bool operator<(const Edge &u)const
	{
		return z==u.z?x>u.x:z>u.z;
	}*/
};
vector<Edge> g;
int pre[N],ans;

int root(int x)
{
	pre[x]=(pre[x]==x?x:root(pre[x]));
	return pre[x];
}

signed main()
{
	tb();
	int a1,a2,a3;
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a1>>a2>>a3;
		g.push_back({a1,a2,a3});
	}
	for(int i=1;i<=n;++i)
		pre[i]=i;
	sort(g.begin(), g.end(), [](const Edge &u, const Edge &v)
	{
	   	if(u.z != v.z)return u.z < v.z;
	   	return u.x < v.x;
    });
	for(const auto &t:g)
	{
		int x=t.x,y=t.y,z=t.z;
		if(root(x)!=root(y))
		{
			ans+=z;
			pre[root(y)]=root(x);
		}
	}
	for(int i=1;i<=n;++i)
		if(root(i)!=root(1))
		{
			cout<<"orz";
			return 0;
		}
	cout<<ans;
	return 0;
}
