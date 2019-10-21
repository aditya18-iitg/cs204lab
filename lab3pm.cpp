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

lli m,n;
vector<vector<lli>> mat;
vector<vector<lli>> vis;
vector<pair<lli,lli>> pr;

lli dfs(lli x,lli y){
	//if(mat[x][y]==1){
	lli cnt = 0;
	//cout<<x<<" "<<y<<"\n";
	for(lli i=0;i<pr.size();++i){
		lli x1 = x+pr[i].first;
		lli y1 = y+pr[i].second;
		if(x1>=0 && x1<m && y1>=0 && y1<n && mat[x1][y1]==1 && !vis[x1][y1]){
			vis[x1][y1] = 1;
			
			cnt+=1+dfs(x1,y1);
		}
	}

	return cnt;
}
int main() {
	kira;
	lli mx = -1;
	lli k,i,j;
	cin>>m>>n;
	cin>>k;
	vector<vector<lli>> board(m);
	vector<lli> temp(n);
	forz(i,m) {
		board[i]=temp;
	}

	vis=board;
	lli x,y;
	forz(i,k) {
		cin>>x>>y;
		board[x][y]=1;
	}
	mat=board;

	pr.push_back(make_pair(-1,0));
	// pr.push_back(make_pair(-1,-1));
	// pr.push_back(make_pair(-1,1));
	pr.push_back(make_pair(0,-1));
	pr.push_back(make_pair(0,1));
	// pr.push_back(make_pair(1,-1));
	pr.push_back(make_pair(1,0));
	// pr.push_back(make_pair(1,1));
	
	for(i=0;i<m;++i){
		for(lli j=0;j<n;++j){
			if(mat[i][j]==1 && !vis[i][j]){
				vis[i][j] = 1; 
				mx=max(mx,1+dfs(i,j));
				//memset(vis,0,sizeof(vis));
			}
		}
	}

	// i=j=0;
	// for(int r=0;r<k;r++){
	// 	while(vis[i][j]||mat[i][j]==0) {
	// 		j=(j+1)%n;
	// 		if (j==0) i=(i+1);
	// 	}
	// 	if(i==m) break;
	// 	if(mat[i][j]==1 && !vis[i][j]){
	// 			vis[i][j] = 1; 
	// 			mx=max(mx,1+dfs(i,j));
	// 			//memset(vis,0,sizeof(vis));
	// 	}
	// }
	cout<<mx<<endl;
	return 0;
}