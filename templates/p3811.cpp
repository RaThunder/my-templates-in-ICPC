#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tb ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=3e6+9;
int n,p;
int inv[N];

void putin()
{
	cin>>n>>p;
}

signed main()
{
	tb;
	putin();
	cout<<1<<"\n";
	inv[1]=1;
	for(int i=2;i<=n;++i)
	{
		inv[i]=(p-p/i)*inv[p%i]%p;
		cout<<inv[i]<<"\n";
	}
	return 0;
}
