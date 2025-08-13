#include <bits/stdc++.h>
using namespace std;
#define tb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int inf=1e9;

const int N=5e2+9;
int n,m;
char s[N][N];
struct node
{
	int x,y;
};
deque<node> dq;//È·±£ÉýÐò
bool vis[N][N];
int d[N][N];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int px1,px2,py1,py2;

void dij_bfs()
{
	dq.clear();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			d[i][j]=inf;
			vis[i][j]=0;
		}
	d[px1][py1]=0;
	dq.push_front({px1,py1});
	while(!dq.empty())
	{
		int x=dq.front().x;
		int y=dq.front().y;
		dq.pop_front();
		if(vis[x][y])
			continue;
		vis[x][y]=1;
		int x0,y0;
		for(int i=0;i<4;++i)
		{
            x0=x+dx[i];
            y0=y+dy[i];
            if(x0>n||x0<1||y0>m||y0<1)
				continue;
            int w=(s[x0][y0]==s[x][y]?0:1);
            if(d[x][y]+w<d[x0][y0])
            {
            	d[x0][y0]=d[x][y]+w;
            	if(w==0)
            		dq.push_front({x0,y0});
            	else
            		dq.push_back({x0,y0});
			}
		}
	}
}

int main()
{
	tb;
	while(1)
	{
		cin>>n>>m;
		if(n==m&&n==0)
			break;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>s[i][j];
		cin>>px1>>py1>>px2>>py2;
		px1++;px2++;py1++;py2++;
		dij_bfs();
		cout<<d[px2][py2]<<'\n';
	}
	return 0;
}
