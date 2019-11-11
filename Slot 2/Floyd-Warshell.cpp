////  Floyd-Warshell  ////////

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
typedef pair<int, int> iPair;  


 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll v,e;
    cin>>v>>e;
    ll a[v][v];
    ll adjmatrix[v][v];
    for(ll i=0;i<v;i++)
    {
        for(ll j=0;j<v;j++)
        {
            if(i==j){a[i][j]=0;continue;}
            a[i][j] = INT_MAX;
            adjmatrix[i][j] = 0;
        }
    }
    for(ll i=0;i<e;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        a[x][y] = w;
        adjmatrix[x][y] = w;
    }
    for(ll k=0;k<v;k++)
    {
        for(ll i=0;i<v;i++)
        {
            for(ll j=0;j<v;j++)
            {
                if(a[i][j] > a[i][k]+a[k][j])
                {
                    a[i][j] = a[i][k]+a[k][j];
                }
            }
        }
    }
    
    for(ll i=0;i<v;i++)
    {
        for(ll j=0;j<v;j++)
        {
            if(a[i][j]==INT_MAX)
            {
                cout<<"INF ";
                continue;
            }
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
    
    return 0;
}