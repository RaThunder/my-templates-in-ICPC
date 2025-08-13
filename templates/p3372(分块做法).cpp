#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int inf=1e9;
const int N=1e5+9;

int n,m;
int a[N];
int id[N];
int len;
long long p[N],lz[N];
int sz[N];

inline void update(int x,int y,int k)
{
    int l=id[x],r=id[y];
    if(l==r)
    {
        for(int i=x;i<=y;++i)
        {
            a[i]+=k;
            p[id[i]]+=k;
        }
        return ;
    }
    for(int i=x;id[i]==l;++i)
    {
        a[i]+=k;
        p[id[i]]+=k;
    }
    for(int i=l+1;i<=r-1;++i)
    {
        lz[i]+=k;
        p[i]+=(long long)sz[i]*k;
    }
    for(int i=y;id[i]==r;--i)
    {
        a[i]+=k;
        p[id[i]]+=k;
    }
}

inline long long query(int x,int y)
{
    int l=id[x],r=id[y];
    long long ans=0;
    if(l==r)
    {
        for(int i=x;i<=y;++i)
            ans+=a[i]+lz[id[i]];
        return ans;
    }
    for(int i=x;id[i]==l;++i)
        ans+=a[i]+lz[id[i]];
    for(int i=l+1;i<=r-1;++i)
        ans+=p[i];
    for(int i=y;id[i]==r;--i)
        ans+=a[i]+lz[id[i]];
    return ans;
}

signed main()
{
    tb;
    cin>>n>>m;
    int len=sqrt(n),cnt=((n-1)/len+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        id[i]=(i-1)/len+1;
        p[id[i]]+=a[i];
    }
    for(int i=1;i<=cnt;++i)
    {
        if(i==cnt)
            sz[i]=n-(cnt-1)*len;
        else
            sz[i]=len;
    }
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            update(x,y,k);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<query(x,y)<<'\n';
        }
    }
    return 0;
}