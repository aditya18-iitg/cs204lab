#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct Node* head = NULL;
struct Node  
{  
	pair<int,int> xy;  
	Node *next;  
};


void AddFirst(int x,int y)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    	new_node->xy=make_pair(x,y);
	new_node->next=head;
	head=new_node;
}

void DelFirst()
{
	if (head == NULL) {
        	cout<<"empty linked list";
		return;
	}

    	Node* temp = head;
    	head = head->next;
    	delete(temp);

}

void Del(int x,int y)
{
   
   	if (head == NULL) {
      		cout<<"Empty Linked List";
		return;
	}
   	struct Node* temp = head;
  	struct Node* prev = NULL;
	pair<int,int> point=make_pair(x,y);
   	if ((head->xy)==point) {
        	head = temp->next;    
        	free(temp);              
        	return;
    	}
    	for (int i=0; temp!=NULL; i++) {
             	if(temp->xy==point)
             	{
                 	break;
             	}
             	prev = temp;
             	temp = temp->next;
         }
    	if (temp == NULL) {
    		cout<<"not found";
		return ;
	}
	prev->next=temp->next;
    	free(temp); 
    	
}

void Search(float d)
{
    	struct Node* temp = head;
    	while (temp!= NULL) {
        	if((temp->xy.first)*(temp->xy.first)+(temp->xy.second)*(temp->xy.second)<=d*d)
        	{
        	    	cout<<"("<<(temp->xy.first)<<","<<(temp->xy.second)<<") ";
        	}
        temp=temp->next;
    	}
}

bool Search(int x,int y)
{
    	struct Node* temp = head;
    	while (temp!= NULL) {
        	if((temp->xy.first)==x&&(temp->xy.second)==y)
        {
            return true;
        }
        temp=temp->next;
    	}
    	return false;
}

int Length()
{
    struct Node* temp = head;
    int len=0;
    while (temp!= NULL) {
        len++;
        temp=temp->next;
    }
    return len;
}


int main()
{
	int a,x,y;
	long long int t;
	cout<<"Enter No. of Inputs: "<<endl;
	cin>>t;
	while(t!=0)
    	{
       		
		cin>>a;
		if(a==1) {
		    	cin>>x>>y;
		    	AddFirst(x,y);
		}
		if(a==2) {DelFirst();}
		if(a==3) {
		    	cin>>x>>y;
		    	Del(x,y);
		}
		if(a==4) {
		    	cin>>x;
		    	Search(x);
		    	cout<<endl;
		   
		}
		if(a==5) {
			string res;
		    	int x,y;
		    	cin>>x>>y;
			bool z=Search(x,y);
			if (z==false) res="False";
			if (z==true) res="True";
		    	cout<<res<<endl;
		}
		if(a==6) {
		    	cout<<Length()<<endl;
		}
		t--;
    	}
}
