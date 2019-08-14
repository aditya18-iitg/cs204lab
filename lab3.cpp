#include<iostream>
#include<stack>


using namespace std;
int main() {
	int n;
	int res;
	cin>>n;
	string br;
	stack<char> op;
	while(n--) {
		while(!op.empty()) op.pop();
		//cout<<op.size()<<endl;
		res=1;
		cin>>br;
		int mod_flag=0;
		for (char& c: br) {
			if (c=='(') {
				op.push(c);
			}
			if (c=='{') {
				op.push(c);
			}
			if (c=='[') {
				op.push(c);
			}
			if (c=='<') {
				op.push(c);
			}
			if (c=='|') {
				if (mod_flag==0) {
					op.push(c);
					mod_flag=1;
				}
				else if (mod_flag==1) {
					if (op.empty()) {
						res=0;
						break;
					}
					if (op.top()=='|') {
						op.pop();
						mod_flag=0;
					}
					else {
						res=0;
						break;
					}
				}
			}
			if (c==')') {
				if (op.empty()) {
						res=0;
						break;
				}
				if (op.top()=='(') op.pop();
				else {
					res=0;
					break;
				}
			}
			if (c=='}') {
				if (op.empty()) {
						res=0;
						break;
				}
				if (op.top()=='{') op.pop();
				else {
					res=0;
					break;
				}
			}
			if (c==']') {
				if (op.empty()) {
						res=0;
						break;
				}
				if (op.top()=='[') op.pop();
				else {
					res=0;
					break;
				}
			}
			if (c=='>') {
				if (op.empty()) {
						res=0;
						break;
				}
				if (op.top()=='<') op.pop();
				else {
					res=0;
					break;
				}
			}
		}
		if (res==1 && op.empty()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
}

