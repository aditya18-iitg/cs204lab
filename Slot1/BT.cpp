#include<bits/stdc++.h>

using namespace std;
struct Node {
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node* new_node(int k) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node*));
	if(n!=NULL) {
		n->key=k;
		n->left=NULL;
		n->right=NULL;
		return n;
	}
	else {
		cout<<"Memory allocation failed";
	}
}

void insert(struct Node* temp, int key) { 
    queue<struct Node*> q; 
    q.push(temp);
    while (!q.empty()) { 
        struct Node* temp = q.front(); 
        q.pop(); 
        if (!temp->left) { 
            temp->left = new_node(key); 
            break; 
        } 
        else q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = new_node(key); 
            break; 
        } 

        else q.push(temp->right); 
    } 
} 
  

int main() {
	cout<<"Enter the number of elements in the tree: "<<"\n";
	int num;
	cin>>num;
	int arr[1000];
	struct Node* root=NULL;
	for(int i=0;i<num;i++)cin>>arr[i];
	for(int i=0;i<num;i++) {	
		insert(root,arr[i]); 
	}
}