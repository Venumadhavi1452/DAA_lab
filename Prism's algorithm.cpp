#include<bits/stdc++.h>
using namespace std;
 
int V;
 
int selectMinVertex(vector<int>& value,vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(setMST[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}
 
void findMST(int graph[1001][1001])
{
	int parent[V];		
	vector<int> value(V,INT_MAX);	
	vector<bool> setMST(V,false);	
 
 
	parent[0] = -1;	
	value[0] = 0;	
 
	for(int i=0;i<V-1;++i)
	{
		int U = selectMinVertex(value,setMST);
		setMST[U] = true;	
 
		for(int j=0;j<V;++j)
		{
			if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j])
			{
				value[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}
	for(int i=1;i<V;++i)
		cout<<parent[i]<<" - "<<i<<"\n";
}
 
int main()
{
    cin>>V;
    int t;
    cin>>t;
    int graph[1001][1001];
    memset(graph, 0, sizeof(graph)); 
    while(t--)
    {
        int x,y,cost;
        cin>>x>>y>>cost;
        graph[x][y]=cost;
    }
	findMST(graph);	
	return 0;
}
