#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const long long inf=2e18;

const int N=1e6+9;
int n,m,R;
vector<int> g[N];
int v[N];
int in[N],out[N];
int cnt;
long long t[N<<2],lz[N<<2];

inline void dfs(int x,int fa)
{
	in[x]=++cnt;
	for(const auto &y:g[x])
		if(y!=fa)
			dfs(y,x);
	out[x]=cnt;
}

inline void pushup(int x)
{
	t[x]=t[x<<1]+t[x<<1|1];
}

inline void pushdown(int s,int e,int x)
{
	if(lz[x]==0)
		return ;
	int mid=(s+e)>>1;
	int ls=x<<1,rs=x<<1|1;
	t[ls]+=lz[x];
	t[rs]+=lz[x];
	lz[ls]+=lz[x];
	lz[rs]+=lz[x];
	lz[x]=0;
}

inline void update(int l,int r,int k,int s,int e,int x)
{
	if(l<=s&&e<=r)
	{
		t[x]+=k;
		lz[x]+=k;
		return ;
	}
	pushdown(s,e,x);
	int mid=(s+e)>>1;
	if(mid>=l)
		update(l,r,k,s,mid,x<<1);
	if(mid+1<=r)
		update(l,r,k,mid+1,e,x<<1|1);
	pushup(x);
}

inline long long query(int l,int r,int s,int e,int x)
{
	if(l<=s&&e<=r)
		return t[x];
	pushdown(s,e,x);
	long long res=0;
	int mid=(s+e)>>1;
	if(mid>=l)
		res+=query(l,r,s,mid,x<<1);
	if(mid+1<=r)
		res+=query(l,r,mid+1,e,x<<1|1);
	return res;
}

signed main()
{
	tb;
	cin>>n>>m>>R;
	for(int i=1;i<=n;++i)
		cin>>v[i];
	for(int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(R,0);
	for(int i=1;i<=n;++i)
		update(in[i],in[i],v[i],1,n,1);
	while(m--)
	{
		int op,a;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>a>>x;
			update(in[a],in[a],x,1,n,1);
		}
		else
		{
			cin>>a;
			cout<<query(in[a],out[a],1,n,1)<<'\n';
		}
	}
	return 0;
}
