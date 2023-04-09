//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *p=NULL;
        Node *q=NULL;
        Node *r=head;
        while(r!=NULL)
        {
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        head=q;
        while(q->data==9)
        {
            q->data=0;
            if(q->next==NULL)
            {
                Node *t=new Node(1);
                t->next=head;
                head=t;
                return head;
                
            }
            q=q->next;
        }
        q->data=q->data+1;
        Node *a=NULL;
        Node *b=NULL;
        Node *c=head;
        while(c!=NULL)
        {
            a=b;
            b=c;
            c=c->next;
            b->next=a;
        }
        head=b;
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends