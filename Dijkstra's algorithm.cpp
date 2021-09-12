#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> arr[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y,k;
        cin>>x>>y>>k;
        arr[x].push_back({y,k});
        arr[y].push_back({x,k});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(n+1,INT_MAX);
    pq.push({1,0});
    dis[1]=0;
    while(!pq.empty())
    {
        int curr=pq.top().first;
        int curr_d=pq.top().second;
        pq.pop();
        for(auto i : arr[curr])
        {
            if(curr_d+i.second<dis[i.first])
            {
                dis[i.first]=curr_d+i.second;
                pq.push({i.first,dis[i.first]});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
}
