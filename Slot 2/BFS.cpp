////  BFS  ////////

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 

void bfs(vector<ll>* adjlist, ll n)
{
    queue<ll> q;
    int visited[n] = {0};
    for(ll j=0;j<n;j++) {
        if(!visited[j])
        {
            q.push(j);
            visited[j] = 1;
            while(!q.empty())
            {
                ll cv = q.front();
                q.pop();
                cout<<cv<<" ";
                for(ll i=0;i<adjlist[cv].size();i++)
                {
                    ll ng = adjlist[cv][i];
                    if(!visited[ng])
                    {
                        visited[ng] = 1; // here ; not above as pushing in queue means visited ;
                        q.push(ng);
                    }
                }
            } 
        } 
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll v,e;
    cin>>v>>e;
    vector<ll> adjlist[v];
    for(ll i=0;i<e;i++)
    {
        ll x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    bfs(adjlist,v);
    
    return 0;
}