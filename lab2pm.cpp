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
#define nl cout<<endl

struct point {
	lli x;
	lli y;
};

point p0;

bool ysort(point a, point b) {
	return (a.y<b.y || a.y==b.y && a.x<b.x);
}
void show(vector<point> vec) {
	for(point a: vec) cout<<a.x<<" "<<a.y<<endl;
}

bool polar(point, point);
lli orientation(point,point,point);
stack<point> hull(vector<point>, lli);
point nexttop(stack<point>);
lli dist(point, point);
vector<point> reorder(vector<point>);

int main() {
	lli t;
	cin>>t;
	lli i;
	vector<point> vert;
	forz(i,t) {
		point temp;
		cin>>temp.x;
		cin>>temp.y;
		vert.pb(temp);
	}
	stack<point> st=hull(vert, t);
	vector<point> vec;
	while(!st.empty()) {
		vec.pb(st.top());
		st.pop();
	}
	vec=reorder(vec);
	show(vec);
}

stack<point> hull(vector<point> vert, lli n) {
	int i;
	sort(vert.begin(),vert.end(), ysort);
	p0=vert[0];
	sort(vert.begin(),vert.end(), polar);
	// vector<point> ver;
	// nl;
	// show(vert);
	// nl;
	lli m=1;
	for(i=1;i<n;i++) {
		while ((i<n-1) && orientation(p0,vert[i],vert[i+1])==0) i++;
		vert[m]=vert[i];
		m++;
	}
	vert.erase(vert.begin()+m+1,vert.end());
	// nl;
	// show(vert);
	// nl;
	stack<point> st;
	st.push(vert[0]);

	st.push(vert[1]); if(m==2) return st;
	st.push(vert[2]);

	for(i=3;i<m;i++) {
		while (orientation(nexttop(st),st.top(),vert[i])!=2) st.pop();
		st.push(vert[i]);
	}
	return st;
}

point nexttop(stack<point> S) {
	point p=S.top();
	S.pop();
	point res=S.top();
	S.push(p);
	return res;
}

lli orientation(point p, point q, point r) {
	lli val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if (val==0) return 0;
	return (val>0?1:2);
}

bool polar(point p1, point p2) {
	lli o = orientation(p0,p1,p2);
	if (o==0) 
		return (dist(p0,p1)<dist(p0,p2)?1:0);
	return ((o==1)?0:1);
}

lli dist(point p1, point p2) 
{ 
    return (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y); 
} 

vector<point> reorder(vector<point> v) {
	int min=0;
	int i;
	for (i=0; i<v.size();i++) {
		if(v[i].x<v[min].x || (v[i].x==v[min].x && v[i].y<v[min].y)) {
			min=i;
		} 
	}
	vector<point> v1;
	for (i=min; i<v.size(); i++) {
		v1.pb(v[i]);
	}
	for(i=0; i<min; i++) {
		v1.pb(v[i]);
	}
	return v1;
}
