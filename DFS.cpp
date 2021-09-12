#include <bits/stdc++.h>
using namespace std;
vector<int> arr[10001];
int vis[10001];
void dfs(int node)
{
	vis[node]=1;
	for(int i : arr[node])
	{
		if(vis[i]==0)
		{
			dfs(i);
		}
	}
}
int main() {
	int n,m;
	cin>>n>>m;
	int x=m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		arr[x].push_back(y);
		arr[y].push_back(x);
 
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i);
			count++;
		}
	}
	if(count==1 && x==n-1)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
