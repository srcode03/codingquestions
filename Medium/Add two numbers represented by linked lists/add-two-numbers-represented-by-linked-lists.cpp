//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reversell(Node *root)
    {
        Node *p=NULL;
        Node *q=NULL;
        Node *r=root;
        while(r!=NULL)
        {
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        Node *head=q;
        return q;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reversell(first);
        second=reversell(second);
        Node *p=new Node(0);
        Node *q=p;
        int c=0;
        while(first!=NULL && second!=NULL)
        {
            Node *t=new Node(0);
            if(first->data+second->data+c>9)
            {
                t->data=first->data+second->data+c-10;
                c=1;
            }
            else{
                 t->data=first->data+second->data+c;
                 c=0;
            }
            p->next=t;
            p=t;
            first=first->next;
            second=second->next;
        }
        while(first!=NULL)
        {
            Node *t=new Node(0);
            if(first->data+c>9)
            {
                t->data=first->data+c-10;
                c=1;
            }
            else{
                 t->data=first->data+c;
                 c=0;
            }
            p->next=t;
            p=t;
            first=first->next;
        }
        while(second!=NULL)
        {
            Node *t=new Node(0);
            if(second->data+c>9)
            {
                t->data=second->data+c-10;
                c=1;
            }
            else{
                 t->data=second->data+c;
                 c=0;
            }
            p->next=t;
            p=t;
            second=second->next;
        }
        if(c!=0)
        {
            Node *t=new Node(1);
            p->next=t;
            p=t;
        }
        q->next=reversell(q->next);
        return q->next;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends