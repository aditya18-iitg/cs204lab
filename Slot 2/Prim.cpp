////  Prim  ////////

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
typedef pair<int, int> iPair;  

void prim(vector<pair<ll,ll>> adjlist[], ll n)
{
    ll weight[n];
    ll parent[n];
    int visited[n] = {0};
    for(ll i=0;i<n;i++)
    {
        weight[i] = INT_MAX;
        parent[i] = -1;
    }
    // starting vertex is 0
    parent[0] = 0;
    weight[0] = 0;
    // min heap
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; // (weight,source)
    pq.push(make_pair(0,0));
    
    while(!pq.empty())
    {
        ll cv = pq.top().second;
        ll cvw = pq.top().first;
        pq.pop();
        visited[cv] = 1;
        for(ll i=0;i<adjlist[cv].size();i++)
        {
            ll ng = adjlist[cv][i].first;
            ll ngw = adjlist[cv][i].second;
            if(!visited[ng] && weight[ng]>ngw)
            {
                weight[ng] = ngw;
                pq.push(make_pair(ngw,ng));
                parent[ng] = cv;
            }
        }
    }
    for(ll i=1;i<n;i++)
    {
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
    }
    
    
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll v,e;
    cin>>v>>e;
    vector<pair<ll,ll> > adjlist[v];
    for(ll i=0;i<e;i++)
    {
        ll x,y,w;
        cin>>w>>x>>y;
        adjlist[x].push_back(make_pair(y,w));
        adjlist[y].push_back(make_pair(x,w));
    }
    
    prim(adjlist,v);
    
    return 0;
}