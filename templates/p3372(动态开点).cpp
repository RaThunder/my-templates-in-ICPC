#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int inf=1e9;

const int M=1e5+9;
const int N=1e5+9;
int n,m;
long long a;
long long t[N<<1],lz[M<<1];
int ls[M<<1],rs[M<<1],siz,rt;

void pushup(int x)
{
    t[x]=t[ls[x]]+t[rs[x]];
}

void pushdown(int s,int e,int x)
{
    if(!lz[x])
        return ;
    if(!ls[x])
        ls[x]=++siz;
    if(!rs[x])
        rs[x]=++siz;
    int mid=(s+e)>>1;
    t[ls[x]]+=(mid-s+1)*lz[x];
	lz[ls[x]]+=lz[x];
	t[rs[x]]+=(e-mid)*lz[x];
	lz[rs[x]]+=lz[x];
	lz[x]=0;
}

void update(int l,int r,long long k,int s,int e,int &x)
{
    if(!x)
        x=++siz;
    if(l<=s&&e<=r)
    {
        t[x]+=(e-s+1)*k;
        lz[x]+=k;
        return ;
    }
    pushdown(s,e,x);
    int mid=(s+e)>>1;
    if(mid>=l)
        update(l,r,k,s,mid,ls[x]);
    if(mid+1<=r)
        update(l,r,k,mid+1,e,rs[x]);
    pushup(x);    
}

long long query(int l,int r,int s,int e,int x)
{
    if(!x)
        return 0;
    if(l<=s&&e<=r)
        return t[x];
    pushdown(s,e,x);
    int mid=(s+e)>>1;
    long long res=0;
    if(mid>=l)
        res+=query(l,r,s,mid,ls[x]);
    if(mid+1<=r)
        res+=query(l,r,mid+1,e,rs[x]);
    return res;
}

signed main()
{
    tb;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        update(i,i,a,1,n,rt);
    }
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            long long k;
            cin>>x>>y>>k;
            update(x,y,k,1,n,rt);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<query(x,y,1,n,rt)<<'\n';
        }
    }
    return 0;
}