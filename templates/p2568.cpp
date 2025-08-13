#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const long long inf=2e18;

const int N=1e7+9;
vector<int> p;
long long phi[N];
bitset<N> b;
long long sum[N],ans;
int n;

void getprime()
{
	b[0]=1;
	b[1]=1;
	phi[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!b[i])
		{
			p.push_back(i);
			phi[i]=i-1;
		}
		for(int j=0;j<p.size()&&i*p[j]<=n;++j)
		{
			b[i*p[j]]=1;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*phi[p[j]];
		}
	}
}

signed main()
{
	tb;
	cin>>n;
	getprime();
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+phi[i];
	for(int i=0;i<p.size();++i)
		ans+=(2*sum[n/p[i]]-1);
	cout<<ans;
	return 0;
}
