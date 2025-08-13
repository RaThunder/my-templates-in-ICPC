#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const long long inf=2e18;

const int N=1e6+9;
int n;
int t;
vector<int> p;
long long phi[N];
bitset<N> b;
long long ans[N];

void getprime()
{
	b[0]=1;
	b[1]=1;
	phi[1]=1;
	for(int i=2;i<=N;++i)
	{
		if(!b[i])
		{
			p.push_back(i);
			phi[i]=i-1;
		}
		for(int j=0;j<p.size()&&i*p[j]<=N;++j)
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
	cin>>t;
	getprime();
	for(int i=1;i<=N;++i)
		for(int j=1;j*i<=N;++j)
			ans[i*j]+=(i==1?1:(long long)phi[i]*i/2);
//对于每个 (i, j)，计算 i * j 的值 k，并将贡献值加到 ans[k] 上。
//贡献值的计算：
//如果 i == 1，则贡献为 1；
//否则，贡献为 φ(i) * i / 2（注意 1ll 用于避免整数溢出）。
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		cout<<n*ans[n]<<endl;
	}
	return 0;
}
