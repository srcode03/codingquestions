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

class Solution{
    private:
    Node* reverseLinkedList(Node* head){
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(current != NULL){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    void insertAtTail(Node* &head, Node* &tail, int val){
        Node* temp = new Node(val);
        
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    Node* add(Node* first, Node* second){
        int carry = 0;
        int sum = 0;
        int digit = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL && second != NULL){
            sum = carry + first->data + second->data;
            digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            first = first -> next;
            second = second -> next;
        }
        
        while(first != NULL){
            sum = carry + first->data;
            digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            first = first -> next;
        }
        
        while(second != NULL){
            sum = carry + second -> data;
            digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            second = second -> next;
        }
        while(carry != 0){
            sum = carry;
            digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
        }
        
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2){
        
        // step 01: reversing the linked list
        Node* first = reverseLinkedList(num1);
        Node* second = reverseLinkedList(num2);
        
        // step 02: start adding them
        Node* ans = add(first, second);
        
        // step 03: reversing the ans linked list
        
        ans = reverseLinkedList(ans);
        
        while(ans -> data == 0 && ans->next != NULL){
            ans = ans -> next;
        }
        
        return ans;
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
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends