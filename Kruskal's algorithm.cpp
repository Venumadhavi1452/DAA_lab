#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int a,b,w;
};
bool comp(edge a , edge b)
{
    return a.w<b.w;
}
edge arr[100001];
int par[100001];
int ra[100001];
int find(int a)
{
    if(par[a]==-1)
    {
        return a;
    }
    else{
        return par[a]=find(par[a]);
    }
}
void merge(int a,int b)
{
    if(ra[a]>ra[b])
    {
        par[b]=a;
        ra[a]+=ra[b];
    }
    else{
        par[a]=b;
        ra[b]+=ra[a];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        par[i]=-1;
        ra[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>arr[i].a>>arr[i].b>>arr[i].w;
    }
    sort(arr,arr+m,comp);
    int sum=0;
    for(int i=0;i<m;i++)
    {
        int x=find(arr[i].a);
        int y=find(arr[i].b);
        if(x!=y)
        {
            sum+=arr[i].w; 
            merge(x,y);
        }
    }
    cout<<sum;
}
