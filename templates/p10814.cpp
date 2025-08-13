#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int inf=1e9;
const int N=2e6+9;

int ans[N],n,m,a[N];
struct node{
	int x,id,val;
};
vector<node> vec[N];
int f[N];

int lowbit(int i)
{
	return i&(-i);
}

void add(int x)
{
	for(int i=x;i<=N;i+=lowbit(i))
        f[i]++;
}

int ask(int x)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))
        ans+=f[i];
	return ans;
}

int main(){
    tb;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
        cin>>a[i];
	for(int i=1;i<=m;i++)
    {
		int l,r,x;
		cin>>l>>r>>x;
		vec[l-1].push_back({x,i,-1});
		vec[r].push_back({x,i,1});
	}
	for(int i=1;i<=n;i++)
    {
		add(a[i]);
		for(int j=0;j<vec[i].size();j++)
			ans[vec[i][j].id]+=vec[i][j].val*ask(vec[i][j].x);
	}
	for(int i=1;i<=m;i++)
        cout<<ans[i]<<"\n";
	return 0;
}