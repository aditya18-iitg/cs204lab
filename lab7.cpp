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
#define forz(i,n) for(i=0;i<n;i++)

void show(vector<string> v) {
	for(string str: v) {
		cout<<str<<" ";
	}
	cout<<endl;
}
int max(int a,int b) {return (a>b?a:b);}
bool priority(string,string);
//node* newNode(int,int);
//int height(node*);

int main() {
	int n;
	vector<vector<string>> input;
	cin>>n;
	while(n--) {
		int t;
		cin>>t;
		vector<string> temp1;
		while(t--) {
			string t1;
			cin>>t1;
			temp1.pb(t1);
		}
		// show(temp1);
		input.pb(temp1);
	}
	for(vector<string> x: input) {
		// show(x);
		sort(x.begin(),x.end(),priority);
		//show(x);
		for(string str:x) {
			cout<<str;
		}
		cout<<endl;
	}
}

bool priority(string s1, string s2) {
	string xy=s1.append(s2);
	string yx=s2.append(s1);
	if(xy.compare(yx)>=0) return 1;
	else return 0;
	// return (s2+s1).compare(s1+s2);
}
