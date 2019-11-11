////  Kruskal  ////////

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
struct kruskal
{
    ll x;
    ll y;
    ll w;
};

struct node
{
    ll parent;
    ll rank;
};

bool comapre(kruskal a, kruskal b)
{
    return a.w < b.w;
}
 
ll find(ll x, node* a)
{
    if(a[x].parent == x)
    {
        return x;
    }
    a[x].parent = find(a[x].parent, a);
}

void unionset(ll x, ll y, node* a)
{
    ll xroot = find(x,a);
    ll yroot = find(y,a);
    
    if(a[xroot].rank < a[yroot].rank)
    {
        a[xroot].parent = yroot;
    }
    else if(a[xroot].rank > a[yroot].rank)
    {
        a[yroot].parent = xroot;
    }
    else
    {
        a[yroot].parent = xroot;
        a[xroot].rank++;
    }
}
 
void mstkruskal(kruskal* edges, ll e, vector<kruskal>&mst, ll v)
{
    node a[v];
    for(ll i=0;i<v;i++)
    {
        a[i].parent = i;
        a[i].rank = 0;
    }
    
    ll count = 0;
    ll i = 0;
    while(count<v-1)
    {
        ll x = edges[i].x;
        ll y = edges[i].y;
        if(find(x,a)!=find(y,a))
        {
            mst.push_back(edges[i]);
            unionset(x,y,a);
            count++;
        }
        i++;
    }
    
    
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll v,e;
    cin>>v>>e;
    //vector<ll> adjlist[v];
    kruskal edges[e];
    vector<kruskal> mst;
    for(ll i=0;i<e;i++)
    {
        cin>>edges[i].w>>edges[i].x>>edges[i].y;
    }
    sort(edges,edges+e,comapre);
    mstkruskal(edges,e,mst,v);
    for(ll i=0;i<mst.size();i++)
    {
        cout<<mst[i].x<<" "<<mst[i].y<<" "<<mst[i].w<<endl;
    }
    return 0;
}