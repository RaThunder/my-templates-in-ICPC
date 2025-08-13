#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tb ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1e6+9;
string s1,s2;
int nextp[N];

void getnext(const string &c)
{
	nextp[0]=0;
	int i=1,j=0,cnt=0;
	while(i<c.length())
	{
		if(c[j]==c[i])
		{
			nextp[++cnt]=++j;
			i++;
		}
		else
		{
			if(j==0)
			{
				nextp[++cnt]=0;
				i++;
			}
			else
				j=nextp[j-1];
		}
	}
}

void kmp(const string &tar,const string &mp)
{
	int j=0;
	for(int i=0;i<tar.length();i++)
	{
		while(j!=0&&mp[j]!=tar[i])
			j=nextp[j-1];
	    if(mp[j]==tar[i])
			j++;
	    if(j==mp.length())
		{
			cout<<i-j+2<<endl;
			j=nextp[j-1];
		}
	}
}

signed main()
{
	tb;
	cin>>s1>>s2;
	getnext(s2);
	kmp(s1,s2);
	for(int i=0;i<s2.length();++i)
		cout<<nextp[i]<<' ';
	return 0;
}
