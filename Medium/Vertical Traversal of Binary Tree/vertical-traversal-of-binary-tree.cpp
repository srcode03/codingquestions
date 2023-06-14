//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    map<Node *,int>ct;
    static bool comp(pair<pair<int,int>,Node *>a,pair<pair<int,int>,Node *>b)
    {
        if(a.first.first==b.first.first)
        {
            return a.first.second<b.first.second;
        }
        if(a.first.second==b.first.second && a.first.first==b.first.first)
        {
            return a.second->data<b.second->data;
        }
        return a.first.first<b.first.first;
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<Node *,int>mp;
        queue<Node *>q;
        q.push(root);
        mp[root]=0;
        ct[root]=0;
        int c=1;
        while(!q.empty())
        {
            Node *p=q.front();
            q.pop();
            if(p->left!=NULL)
            {
                q.push(p->left);
                mp[p->left]=mp[p]-1;
                ct[p->left]=c;
            }
            if(p->right!=NULL)
            {
                q.push(p->right);
                mp[p->right]=mp[p]+1;
                ct[p->right]=c;
            }
            c++;
        }
        vector<pair<pair<int,int>,Node *>>ans;
        for(auto it:mp)
        {
            ans.push_back({{it.second,ct[it.first]},it.first});
        }
        sort(ans.begin(),ans.end(),comp);
        vector<int>t;
        for(auto it:ans)
        {
            t.push_back(it.second->data);
        }
        return t;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends