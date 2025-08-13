#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const long long inf=2e18;

const int N=1e6+9;
int n,m,R;
vector<int> g[N];
int v[N];
int dep[N],sz[N],fa[N][32];
int in[N],out[N],cnt;
long long t[N],t1[N],t2[N];

inline void dfs(int x,int f)
{
	in[x]=++cnt;
	fa[x][0]=f;
	dep[x]=dep[fa[x][0]]+1;
	for(int i=1;i<=20;++i)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(const auto &y:g[x])
		if(y!=f)
			dfs(y,x);
	out[x]=cnt;
}

inline int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=20;i>=0;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for(int i=20;i>=0;--i)
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}

inline int lowbit(const int &x)
{
	return x&-x;
}

inline void update_point(int x,int ink)
{
	for(int i=ink;i<=n;i+=lowbit(i))
		t[i]+=x;
}

inline void update_line(int x,int ink,int depk)
{
	for(int i=ink;i<=n;i+=lowbit(i))
	{
		t1[i]+=x;
		t2[i]+=depk*x;
	}
}

inline long long query(int k,bool op)
{
	long long ans=0;
	if(op==1)
		for(int i=k;i>=1;i-=lowbit(i))
			ans+=t[i];
	else if(op==2)
		for(int i=k;i>=1;i-=lowbit(i))
			ans+=t1[i];
	else if(op==3)
		for(int i=k;i>=1;i-=lowbit(i))
			ans+=t2[i];
	return ans;
}

inline long long getans(int a)
{
	long long sum1,sum2,sum3;
	sum1=query(out[a],1)-(in[a]-1,1);
	sum2=query(out[a],2)-(in[a]-1,2);
	sum3=query(out[a],3)-(in[a]-1,3);
	return sum1+sum3-sum2*(dep[a]-1);
}

signed main()
{
	tb;
	cin>>n>>m>>R;
	dep[R]=1;
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
		update_point(v[i],in[i]);
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int a,b,x;
			cin>>a>>b>>x;
			int l=lca(a,b);
			update_line(x,in[a],dep[a]);
			update_line(x,in[b],dep[b]);
			update_line(-x,in[l],dep[l]);
			if(l!=R)
				update_line(-x,in[fa[l][0]],dep[l]-1);
		}
		else if(op==2)
		{
			int a;
			cin>>a;
			long long add_val = query(in[a], 2) - (in[a]>1 ? query(in[a]-1, 2) : 0);
			cout << v[a] + add_val << '\n';
		}
		else
		{
			int a;
			cin>>a;
			cout<<getans(a)<<'\n';
		}
	}
	return 0;
}
