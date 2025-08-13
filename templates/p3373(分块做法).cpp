#include <bits/stdc++.h>
using namespace std;
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int inf=1e9;
const int N=1e5+9;

int n,q,m;
int a[N];
int len,sz[N],id[N],cnt;
long long p[N];

int main()
{
    tb;
    cin>>n>>q>>m;
    len=sqrt(n);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        id[i]=(i-1)/len+1;
        p[id[i]]+=a[i];
    }
    while(m--)
    {

    }
}