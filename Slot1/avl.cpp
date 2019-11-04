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
#define nl cout<<endl


struct node {
    int key;
    int height;
    node* left;
    node* right;
};

int max(int a,int b) {return (a>b?a:b);}
int height(node*);
node* newNode(int);
node* insert(node*,int);
node* leftRotate(node*);
node* rightRotate(node*);
node* search(node*,int);
int getBalance(node*);
void inorder(node*);
node* minValueNode(node*); 
node* deleteNode(node*, int); 

int main() {
    struct node *root = NULL; 
    int n,i;
    cin>>n;
    forz(i,n) {
        int val;
        cin>>val;
        root=insert(root,val);
    }
    inorder(root); 
    nl;
    int val;
    cin>>val;
    root=deleteNode(root,val);
    inorder(root);
    return 0; 
}

node* newNode(int id) { 
    node *temp = new node; 
    temp->left = temp->right = NULL; 
    temp->key = id;
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

node* insert(node* node, int key) {  
    if (node == NULL)  
        return(newNode(key)); 
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  

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

void inorder(struct node *root) { 
    if (root != NULL) { 
        inorder(root->left); 
        cout<<root->key<<" ";
        inorder(root->right); 
    } 
} 

node* minValueNode(node* node) {  
    struct node* current = node;  
    while (current->left != NULL)  
        current = current->left;  
    return current;  
}  

node* deleteNode(node* root, int key)  {  
    if (root == NULL)  return root;  
    if (key < root->key)  
        root->left = deleteNode(root->left, key);  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
    else {  
        if( (root->left == NULL) || (root->right == NULL) )  {  
            node *temp = (root->left?root->left:root->right);   
            if (temp == NULL) {  
                temp = root;  
                root = NULL;  
            }  
            else *root = *temp; 
        }  
        else {  
            node* temp = minValueNode(root->right);  
            root->key = temp->key;  
            root->right = deleteNode(root->right, temp->key);  
        }  
    }

    if (root == NULL) return root;  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  

    int balance = getBalance(root);  
    if (balance > 1 &&  getBalance(root->left) >= 0) return rightRotate(root);  
    if (balance > 1 &&  getBalance(root->left) < 0) {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    } 
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);  
    if (balance < -1 && getBalance(root->right) > 0) {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
    return root;  
}  