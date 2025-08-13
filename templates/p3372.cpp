#include <bits/stdc++.h>
using namespace std;
#define ing long long
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const long long inf=2e18;

const int N=1e5+9;
int n,m,op;
long long a[N],t[N<<2],lz[N<<2];

inline void pushup(const int &x)
{
	t[x]=t[x<<1]+t[x<<1|1];
}

void build(const int &s,const int &e,const int &x)
{
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
	if(lz[x]==0)
		return ;
	int mid=(s+e)>>1;
	int ls=x<<1,rs=x<<1|1;
	t[ls]+=(mid-s+1)*lz[x];
	lz[ls]+=lz[x];
	t[rs]+=(e-mid)*lz[x];
	lz[rs]+=lz[x];
	lz[x]=0;
}

inline void update(const int &l,const int &r,const long long &v,const int &s,const int &e,const int &x)
{
	if(l<=s&&e<=r)
	{
		t[x]+=(e-s+1)*v;
		lz[x]+=v;
		return ;
	}
	pushdown(s,e,x);
	int mid=(s+e)>>1;
	if(mid>=l)
		update(l,r,v,s,mid,x<<1);
	if(mid+1<=r)
		update(l,r,v,mid+1,e,x<<1|1);
	pushup(x);
}

inline long long query(const int &l,const int &r,const int &s,const int &e,const int &x)
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
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	build(1,n,1);
	while(m--)
	{
		cin>>op;
		if(op==1)
		{
			int l,r;
			long long k;
			cin>>l>>r>>k;
			update(l,r,k,1,n,1);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			cout<<query(l,r,1,n,1)<<endl;
		}
	}
	return 0;
}
