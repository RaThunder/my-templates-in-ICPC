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
//����ÿ�� (i, j)������ i * j ��ֵ k����������ֵ�ӵ� ans[k] �ϡ�
//����ֵ�ļ��㣺
//��� i == 1������Ϊ 1��
//���򣬹���Ϊ ��(i) * i / 2��ע�� 1ll ���ڱ��������������
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
