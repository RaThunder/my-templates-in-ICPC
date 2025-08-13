#include <bits/stdc++.h>
using namespace std;
#define int long long

void tb()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int N=1e5+9;
int n,m,s;
long long inf=INT_MAX;
int d[N];
bitset<N> vis;
struct Edge
{
	int x,w;
	bool operator<(const Edge &u)const
	{
		return w==u.w?x>u.x:w>u.w;
	}
};
vector<Edge> g[N];
priority_queue<Edge> pq;

void dij(int k)
{
	for(int i=1;i<=n;++i)
		d[i]=inf;
	d[k]=0;
	pq.push({k,d[k]});
	while(!pq.empty())
	{
		int bef=pq.top().x;
		pq.pop();
		if(vis[bef])
			continue;
		vis[bef]=1;
		for(const auto &v:g[bef])
			if(d[bef]+v.w<d[v.x])
			{
				d[v.x]=d[bef]+v.w;
				pq.push({v.x,d[v.x]});
			}
	}
}

signed main()
{
	tb();
	cin>>n>>m>>s;
	int ui,vi,wi;
	for(int i=1;i<=m;++i)
	{
		cin>>ui>>vi>>wi;
		g[ui].push_back({vi,wi});
	}
	dij(s);
	for(int i=1;i<=n;++i)
		cout<<min(d[i],inf)<<" ";
	return 0;
}
