#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

#define pb push_back 

struct node 
{ 
    string val; 
    node* left;
    node* right; 
};   

int assign(string);
string postfix(string);
void show(vector<string>);
int prec(char);
string process(string);
bool isOperator(char); 
void inorder(node*); 
node* newNode(string); 
node* constructTree(string); 
int solve(node*);
int toInt(string);

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		vector<string> v,ass,eval;
		vector<node*> tree;
		string temp;
		cin>>n;
		while(n--) {
			cin>>temp;
			v.pb(temp);
		}
		for (string x:v) {
			if (assign(x)==1) ass.pb(x);
			else {
				x=process(x);
				eval.pb(postfix(x));
			}
		}
		// cout<<endl;
		// show(eval);
		// cout<<endl;
		for (string x:eval) {
			tree.pb(constructTree(x));
		}
		for (node* x: tree) {
		//	inorder(x);
			cout<<endl;
			cout<<solve(x)<<endl;
		}
	}
}

int assign(string a) {
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

        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0'&&s[i]<='9')||(s[i]=='#')) 
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
        else{ 
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
	int len=str.length();
	int j;
	for (int i=0;i<len;i++) {
		if(!(str[i]>='0'&&str[i]<='9')&&(str[i-1]>='0'&&str[i-1]<='9')) {
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
	if(str[len-1]>='0'&&str[len-1]<='9') str+='#';
	return str;
}


bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
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
  
node* constructTree(string postfix) 
{ 
    stack<node*> st; 
    node *root, *t1, *t2, *t; 
    string temp;
    for (int i=0; i<postfix.length(); i++) { 
    	temp="";
        if (!isOperator(postfix[i])) {
        	if(postfix[i]>='0'&&postfix[i]<='9') {
        		do {
        			temp+=postfix[i];
        			i++;
        		} while(postfix[i]!='#');
        		
        	}
        	else {
        		temp+=postfix[i];
        	}
            t = newNode(temp);
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
	if (!tree->left && !tree->right) return toInt(tree->val);
	int lef=solve(tree->left);
	int rig=solve(tree->right);
	if ((tree->val)=="+") return (lef+rig);
	if ((tree->val)=="-") return (lef-rig);
	if ((tree->val)=="*") return (lef*rig);
	if ((tree->val)=="/") return (lef/rig);
	if ((tree->val)=="^") return (pow(lef,rig));
}

int toInt(string s)  
{  
    int num = 0;  
   // if(s[0]!='-') 
    	for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
    // else
    //     for (int i=1; i<s.length(); i++)  
    //     { 
    //         num = num*10 + (int(s[i])-48);  
    //         num = num*-1; 
    //     }
    return num;  
}  