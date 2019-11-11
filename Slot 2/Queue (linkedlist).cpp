    #include<bits/stdc++.h>
    using namespace std;

    struct node {  
        int data;   
        struct node *next;  
    };  

    struct node *front;  
    struct node *rear;   
    void insert();  
    void deletes();  
    void display();  
    int main () {  
        int choice;   
        while(choice!= 4) {     
            cout<<"\n\nMain Menu";  
            cout<<"\n1.Enqueue\n2.Dequeue\n3.Display the queue\n4.Exit\n";  
            cout<<"Enter your choice: ";  
            cin>>choice; 
            switch(choice) {  
                case 1:  
                insert();  
                break;  
                case 2:  
                deletes();  
                break;  
                case 3:  
                display();  
                break;  
                case 4:  
                exit(0);  
                break;  
                default:   
                cout<<("Enter valid choice: ");  
            }  
        }  
        return 0;
    }  

    void insert() {  
        struct node *ptr;  
        int item;   
          
        ptr = new node;  
        if(ptr == NULL) {  
            cout<<("\nOVERFLOW\n");  
            return;  
        }  
        else {   
            cout<<"\nEnter value: ";  
            cin>>item; 
            ptr -> data = item;  
            if(front == NULL)  
            {  
                front=ptr;  
                rear=ptr;   
                front->next = NULL;  
                rear->next = NULL;  
            }  
            else   
            {  
                rear->next = ptr;  
                rear = ptr;  
                rear->next = NULL;  
            }  
        }  
    }     

    void deletes()  
    {  
        struct node *ptr;  
        if(front == NULL)  
        {  
            cout<<"\nUNDERFLOW\n";  
            return;  
        }  
        else   
        {  
            ptr = front;  
            front = front->next;  
            delete ptr; 
        }  
    }  

    void display() {  
        struct node *ptr;  
        ptr = front;      
        if(front == NULL) {  
            cout<<"\nEmpty queue\n";  
        }  
        else  {   
            cout<<"printing values: ";  
            while(ptr != NULL)  {  
                cout<<ptr->data<<" ";  
                ptr = ptr->next;  
            }  
        }  
    }  