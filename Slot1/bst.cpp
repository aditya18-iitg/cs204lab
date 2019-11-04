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
    struct node *left, *right; 
}; 
  
struct node *newNode(int item) { 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
void inorder(struct node *root) { 
    if (root != NULL) { 
        inorder(root->left); 
        cout<<root->key<<" ";
        inorder(root->right); 
    } 
} 
  
struct node* insert(struct node* node, int key) {     
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 

    return node; 
} 
  

struct node* minimum(struct node* node) { 
    struct node* current = node; 

    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct node* maximum(struct node* node) { 
    struct node* temp = node; 
    while (temp && temp->right != NULL) 
        temp = temp->right; 

    return temp; 
} 

struct node* deleteNode(struct node* root, int key) { 
   
    if (root == NULL) return root; 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    else { 
        
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        
        struct node* temp = minimum(root->right); 
  
        
        root->key = temp->key; 
  
        
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
  
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