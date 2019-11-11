////   DFS   ////////

#include <bits/stdc++.h>
using namespace std;
 
#define lli long long
 
void dfs2(vector<lli>* adjlist, lli n, int* visited, lli start)
{
    visited[start] = 1;
    cout<<start<<" ";
    for(lli i=0;i<adjlist[start].size();i++)
    {
        lli cv = adjlist[start][i];
        if(!visited[cv])
        {
            dfs2(adjlist,n,visited,cv);
        }
    }
}

void dfs(vector<lli>* adjlist, lli n)
{
    int visited[n] = {0};
    
    for(lli i=0;i<n;i++)
    {
        if(!visited[i])
            {dfs2(adjlist,n,visited,i);}
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    lli v,e;
    cin>>v>>e;
    vector<lli> adjlist[v];
    for(lli i=0;i<e;i++)
    {
        lli x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    dfs(adjlist,v);
    
    return 0;
}