#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<utility>
#include<iterator>
using namespace std;

typedef long long int lli;
#define pb push_back 
#define mp make_pair
#define forc(i,n) for(int i=0;i<n;i++)
#define forz(i,n) for(i=0;i<n;i++)
#define nl cout<<endl
#define kira ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

void edge(vector<int>*, int, int);
bool bipartite(vector<int>*,int,vector<bool>&,vector<int>&);

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	vector<bool> visited(n+1);
	vector<int> color(n+1);

	int t1,t2;
	forc(i,m) {
		cin>>t1>>t2;
		edge(adj,t1,t2);
	} 
	// visited[1]=true;
	color[1]=0;
	bool bi=true;
	for(int i=1;i<n+1;i++) {
		if (visited[i]==0) {
			visited[i]=1;
			if (!bipartite(adj,i,visited,color)) bi=false;
		}
	}
	if (bi==true) cout<<"YES";
	else cout<<"NO";
	return 0;
}

void edge(vector<int> adj[], int u, int v) {
	adj[u].pb(v);
	adj[v].pb(u);
}

bool bipartite(vector<int> adj[], int v, vector<bool>& visited, vector<int>& color) {
	for(int u: adj[v]) {
		if (visited[u]==false) {
			visited[u]=true;
			color[u]=!color[v];
			if (!bipartite(adj, u, visited, color))
				return false;
		}
		else if (color[u]==color[v]) {
			return false;
		}
	}
	return true;
}
