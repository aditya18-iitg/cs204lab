#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<utility>
#include<iterator>
using namespace std;

#define pb push_back 
#define mp make_pair
#define forz(i,n) for(i=0;i<n;i++)

struct node 
{ 
    string val; 
    node* left;
    node* right; 
};   


int isassign(string);
string postfix(string);
void show(vector<string>);
int prec(char);
string process(string);
bool isOperator(char); 
bool isChar(char);
bool isInt(char);
// bool valid(string)
void inorder(node*); 
node* newNode(string); 
node* constructTree(string,map<string,int>); 
int solve(node*);
int toInt(string);
pair<string,int> assign(string,map<string,int>);
string unary(string);
string edit(string,int);

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		map<string,int> var;
		pair<string,int> var1;
		vector<string> v,ass,eval;
		node* tree;
		string temp,post;
		cin>>n;
		while(n--) {
			cin>>temp;
			v.pb(temp);
		}
		cout<<"\n";
		for (string x:v) {
			if (isassign(x)==1) {
				ass.pb(x);
				var1=assign(x,var);
				// string f=var1.first
				if (var1.first[var1.first.length()-1]!='$') {
					map<string,int>::iterator itr=var.find(var1.first);
					if (itr==var.end()) var.insert(var1);
					else itr->second=var1.second;
				}
			}
			else {
				x=process(x);
				post=postfix(x);
				eval.pb(post);
				tree=constructTree(post,var);
				if(tree!=NULL) cout<<solve(tree)<<endl;
				else cout<<"CANT BE EVALUATED"<<endl;
			}
		}
		// cout<<endl;
		// show(eval);
		// // cout<<endl;
		// for (string x:eval) {
		// 	tree.pb(constructTree(x));
		// }
		// for (node* x: tree) {
		// //	inorder(x);
		// 	cout<<endl;
		// 	cout<<solve(x)<<endl;
		// }
	}
}

int isassign(string a) {
	for (char& ch:a) {
		if (ch=='=') return 1;
	}
	return 0;
}

string postfix(string s) { 
    stack<char> st; 
    st.push('N'); 
    int len = s.length(); 
    string ns; 
    for(int i = 0;i < len;i++) {
        if((isChar(s[i]))||(isInt(s[i]))||(s[i]=='#')) 
        	ns+=s[i];
        else if(s[i] == '(') 
        	st.push('('); 
        else if(s[i] == ')') { 
            while(st.top() != 'N' && st.top() != '(') { 
                char c = st.top(); 
                st.pop(); 
               	ns += c; 
            } 
            if(st.top() == '(') { 
                char c = st.top(); 
                st.pop(); 
            }
        }
        else {
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]);     
    	}
    }
    while(st.top() != 'N') { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    } 
    return ns;
}

void show(vector<string> vec) {
	for (string x:vec) {
		cout<<x<<endl;
	}
}

int prec(char c) { 
    if(c == '^') 
    	return 3; 
    else if(c == '*' || c == '/') 
    	return 2; 
    else if(c == '+' || c == '-') 
    	return 1; 
    else
    	return -1; 
} 

string process(string str) {
	str=unary(str);
	int len=str.length();
	int j;
	for (int i=0;i<len;i++) {
		if(!(isInt(str[i]))&&(isInt(str[i-1]))||!(isChar(str[i]))&&(isChar(str[i-1]))) {
			string temp="";
			for(j=0;j<i;j++) {
				temp+=str[j];
			}
			temp+='#';
			for(j=i;j<len;j++) {
				temp+=str[j];
			}
			str=temp;
			i++;
			len++;
		}
	}
	if(isInt(str[len-1])||isChar(str[len-1])) str+='#';
	return str;
}


bool isOperator(char c) { 
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
        return true; 
    return false; 
} 

bool isChar(char c) {
	if((c>='a' && c<='z')||(c>='A'&&c<='Z'))
		return true;
	return false;
}

bool isInt(char c) {
	if(c>='0' && c<='9')
		return true;
	return false;
}

void inorder(node *t) 
{ 
    if(t) 
    { 
        inorder(t->left); 
        cout<<t->val;
        inorder(t->right); 
    }
} 

node* newNode(string v) 
{ 
    node *temp = new node; 
    temp->left = temp->right = NULL; 
    temp->val = v; 
    return temp; 
}; 
  
node* constructTree(string postfix,map<string,int> var) 
{ 
    stack<node*> st; 
    int flag;
    node *root, *t1, *t2, *t; 
    string temp;
    for (int i=0; i<postfix.length(); i++) { 
    	temp="";
        if (!isOperator(postfix[i])) {
        	if(isInt(postfix[i])||isChar(postfix[i])) {
        		if(isInt(postfix[i])) flag=0;
        		else flag=1;
        		do {
        			temp+=postfix[i];
        			i++;
        		} while(postfix[i]!='#');	
        	}
        	else {
        		temp+=postfix[i];
        	}
        	if (flag==0) t = newNode(temp);
        	else {
        		map<string,int>::iterator itr=var.find(temp);
        		if (itr==var.end()) return NULL;
        		t = newNode(to_string(itr->second));
        	}
            st.push(t); 
        } 
        else { 
        	temp+=postfix[i];
            t = newNode(temp); 
            t->right=st.top(); 
            st.pop();      
            t->left=st.top(); 
            st.pop(); 
            st.push(t); 
        } 
    } 

    root = st.top(); 
    st.pop(); 
    return root; 
} 

int solve(node* tree) {
	if (!tree) return 0;
	if (!tree->left && !tree->right) 
		return toInt(tree->val);

	int lef=solve(tree->left);
	int rig=solve(tree->right);
	if ((tree->val)=="+") return (lef+rig);
	if ((tree->val)=="-") return (lef-rig);
	if ((tree->val)=="*") return (lef*rig);
	if ((tree->val)=="/") return (lef/rig);
	if ((tree->val)=="^") return (pow(lef,rig));
}

int toInt(string s) {  
    int num = 0;  
   	if(s[0]!='-') {
    	for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
   	}
    else
        for (int i=1; i<s.length(); i++) { 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        }
    return num;  
}  

pair<string,int> assign(string str, map<string,int> var) {
	int i=0;
	int ans=0;
	i=str.find("=");
	string prec=str.substr(0,i);
	string ante=str.substr(i+1);
	node* tree=constructTree(postfix(process(ante)),var);
	if (tree==NULL) {
		prec+="$";
	}
	else ans=solve(tree);
	return mp(prec,ans);
}

string unary(string f) {
	int i=0;
	if(f[i]=='-') f=edit(f,i);
	int len=f.length();
	for(i=1;i<len;i++) {
		if(f[i]=='-') {
			if (isOperator(f[i-1])||(f[i-1]=='(')) {
				f=edit(f,i);
				len+=3;
				i+=2;
			}
		}
	}
	return f;
}

string edit(string str, int j) {
	string ans="";
	int i;
	// ans=str.substr(0,j);
	for(i=0;i<j;i++) {
		ans+=str[i];
	}
	ans+="(0-";
	i=j+1;
	while(isInt(str[i])||isChar(str[i])) {
		ans+=str[i];
		i++;
	}
	ans+=")";
	ans+=str.substr(i);
	return ans;
}