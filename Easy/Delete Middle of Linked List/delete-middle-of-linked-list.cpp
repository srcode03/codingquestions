//{ Driver Code Starts
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



// } Driver Code Ends
/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        if(head==NULL)return head;
        if(head->next==NULL)
        {
            return NULL;
        }
        if(head->next->next==NULL)
        {
            head->next=NULL;
            return head;
        }
        Node* f=head;
        Node* s1=head;
        Node* s2=NULL;
        int fg=0;
        while(f!=NULL)
        {
            if(f->next==NULL)
            {
                fg=1;
                break;
            }
            f=f->next;
            if(f->next==NULL)
            {
                fg=0;
                break;
            }
            f=f->next;
            s2=s1;
            s1=s1->next;
        }
        if(fg==0)
        {
            s2=s2->next;
            s1=s1->next;
        }
        s2->next=s1->next;
        return head;
    }
};

//{ Driver Code Starts.



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends