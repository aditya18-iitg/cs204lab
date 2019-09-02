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
typedef long long int lli;

struct node {
	int key;
	int bal;
	int height;
	node* left;
	node* right;
};

int max(int a,int b) {return (a>b?a:b);}
int height(node*);
node* newNode(int,int);
node* insert(node*,int,int);
node* leftRotate(node*);
node* rightRotate(node*);
node* search(node*,int);
int getBalance(node*);


int main() {
	long long int n,q;
	int i;
	cin>>n;
	cin>>q;
	int temp;
	vector<vector<int>> input;
	forz(i,q) {
		cin>>temp;
		vector<int> vtemp;
		vtemp.pb(temp);
		if (temp==1) {
			cin>>temp;
			vtemp.pb(temp);
			cin>>temp;
			vtemp.pb(temp);
		}
		input.pb(vtemp);
	}
	int maxi=-1, maxid=0;
	node* tree=NULL;
	for(vector<int> v: input) {
		if (v[0]==1) {
			node* found=search(tree,v[1]);
			if (found==NULL) 
				tree=insert(tree,v[1],v[2]);
				found=search(tree,v[1]);
				if (found->bal>maxi) {
					maxid=found->key;
					maxi=found->bal;
				}
			else {
				found->bal+=v[2];
				if (found->bal>maxi) {
					maxid=found->key;
					maxi=found->bal;
				}
			}
		}
		if (v[0]==2) {
			if (maxid) cout<<maxid<<endl;
			else cout<<"No data available"<<endl;

		}
	}
}

node* newNode(int id, int b) { 
    node *temp = new node; 
    temp->left = temp->right = NULL; 
    temp->key = id;
    temp->bal = b;
    temp->height=1;
    return temp; 
}

int height(node* tree) {
	if (tree==NULL) return 0;
	else return tree->height;
}

node* rightRotate(node *y) {  
    node *x = y->left;  
    node *T2 = x->right;
    x->right = y;  
    y->left = T2; 
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                   height(x->right)) + 1;  
    return x;  
}  
 
node* leftRotate(node *x) {  
    node *y = x->right;  
    node *T2 = y->left;  
    y->left = x;  
    x->right = T2;  

    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
    return y;  
}  

int getBalance(node *N) {  
    if (N == NULL)  
        return 0;  
    return height(N->left)-height(N->right);  
}  

node* insert(node* node, int key, int bal) {  
    if (node == NULL)  
        return(newNode(key,bal)); 
    if (key < node->key)  
        node->left = insert(node->left, key, bal);  
    else if (key > node->key)  
        node->right = insert(node->right, key, bal);    
    node->height = 1 + max(height(node->left),  
                        height(node->right));  

    int balance = getBalance(node);                                    
    if (balance > 1 && key < node->left->key) return rightRotate(node);  
    if (balance < -1 && key > node->right->key) return leftRotate(node);  

    if (balance > 1 && key > node->left->key) {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }                             
    if (balance < -1 && key < node->right->key) {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }
    return node;  
}  

node* search(node* tree, int find) {
	if (tree==NULL) return NULL;
	if (find<tree->key) return search(tree->left,find);
	if (find>tree->key) return search(tree->right,find);
	if (find=tree->key) return tree;
}


