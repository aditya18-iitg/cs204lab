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

lli m,n,c;
vector<vector<lli>> mat;
vector<vector<lli>> vis;
vector<pair<lli,lli>> pr;

lli dfs(lli x,lli y,lli color) {
	//if(mat[x][y]==1){
	lli cnt = 0;
	//cout<<x<<" "<<y<<"\n";
	for(lli i=0;i<pr.size();++i){
		lli x1 = x+pr[i].first;
		lli y1 = y+pr[i].second;
		if(x1>=0 && x1<m && y1>=0 && y1<n && mat[x1][y1]==color && !vis[x1][y1]){
			vis[x1][y1] = 1;
			cnt+=1+dfs(x1,y1,color);
		}
	}

	return cnt;
}
int main() {
	kira;
	lli i,j;
	cin>>m>>n>>c;
	lli mx[c];
	forz(i,c) mx[i]=-1;
	vector<vector<lli>> board(m);
	vector<lli> temp(n);
	forz(i,m) {
		board[i]=temp;
	}

	vis=board;
	lli x;
	forz(i,m) {
		forz(j,n) {
			cin>>x;
			board[i][j]=x;
		}
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
	
	int col;
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			if(!vis[i][j]){
				vis[i][j] = 1; 
				col=mat[i][j];
				mx[col]=max(mx[col],1+dfs(i,j,col));
				//memset(vis,0,sizeof(vis));
			}
		}
	}
	
	lli maxindex=0;
	forz(i,c) {
		if (mx[i]>mx[maxindex]) {
			maxindex=i;
		}
	}
	cout<<mx[maxindex]<<" "<<maxindex<<endl;
	return 0;
}
