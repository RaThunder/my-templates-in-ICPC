#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const long long inf=2e18;

const int N=1e5+9;
int n,p,m;
long long a[N],t[N<<2],lz[N<<2],lzk[N<<2];

inline long long mo(const long long &x)
{
	return (x%p+p)%p;
}

inline void pushup(const int x)
{
	t[x]=mo(t[x<<1]+t[x<<1|1]);
}

void build(const int &s,const int &e,const int &x)
{
	lzk[x]=1;
	lz[x]=0;
	if(s==e)
	{
		t[x]=a[s];
		return ;
	}
	int mid=(s+e)>>1;
	build(s,mid,x<<1);
	build(mid+1,e,x<<1|1);
	pushup(x);
}

inline void pushdown(const int &s,const int &e,const int &x)
{
	if(lz[x]==0&&lzk[x]==1)
		return ;
	int mid=(s+e)>>1;
	int ls=x<<1,rs=x<<1|1;
	t[ls]=mo(mo(t[ls]*lzk[x])+mo((mid-s+1)*lz[x]));
	lzk[ls]=mo(lzk[ls]*lzk[x]);
	lz[ls]=mo(lz[ls]*lzk[x]+lz[x]);
	t[rs]=mo(mo(t[rs]*lzk[x])+mo((e-mid)*lz[x]));
	lzk[rs]=mo(lzk[rs]*lzk[x]);
	lz[rs]=mo(lz[rs]*lzk[x]+lz[x]);
	lzk[x]=1;
	lz[x]=0;
}

inline void update(const int &l,const int &r,const long long &k,const long long &v,const int &s,const int &e,const int &x)
{
	if(l<=s&&e<=r)
	{
		t[x]=mo(mo(t[x]*k)+mo((e-s+1)*v));
		lzk[x]=mo(lzk[x]*k);
		lz[x]=mo(lz[x]*k+v);
		return ;
	}
	pushdown(s,e,x);
	int mid=(s+e)>>1;
	if(mid>=l)
		update(l,r,k,v,s,mid,x<<1);
	if(mid+1<=r)
		update(l,r,k,v,mid+1,e,x<<1|1);
	pushup(x);
}

inline long long query(const int &l,const int &r,const int &s,const int &e,const int &x)
{
	if(l<=s&&e<=r)
		return mo(t[x]);
	pushdown(s,e,x);
	int mid=(s+e)>>1;
	int res=0;
	if(mid>=l)
		res=mo(res+query(l,r,s,mid,x<<1));
	if(mid+1<=r)
		res=mo(res+query(l,r,mid+1,e,x<<1|1));
	return res;
}

signed main()
{
	tb;
	cin>>n>>p;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	cin>>m;
	build(1,n,1);
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y;
			long long k;
			cin>>x>>y>>k;
			update(x,y,k,0,1,n,1);
		}
		else if(op==2)
		{
			int x,y;
			long long k;
			cin>>x>>y>>k;
			update(x,y,1,k,1,n,1);
		}
		else
		{
			int x,y;
			cin>>x>>y;
			cout<<query(x,y,1,n,1)<<endl;
		}
	}
	return 0;
}
