//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
struct Node{
    struct Node *links[26];
    bool flg=false;
    int pre=0;
};
class Solution{
  public:
    void insert(Node *root,string s)
    {
        Node *p=root;
        for(int i=0;i<s.length();i++)
        {
            if(p->links[s[i]-'a']==NULL)
            {
                Node *t=new Node();
                p->links[s[i]-'a']=t;
            }
            p=p->links[s[i]-'a'];
            p->pre=p->pre+1;
        }
        p->flg=true;
    }
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        Node *root=new Node();
        for(int i=0;i<n;i++)
        {
            insert(root,arr[i]);
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            Node *p=root;
            string t="";
            for(int j=0;j<arr[i].length();j++)
            {
                if(p->links[arr[i][j]-'a']->pre==n)
                {
                    t+=arr[i][j];
                }
                else{
                    break;
                }
                p=p->links[arr[i][j]-'a'];
            }
            if(t.length()>ans.length())
            {
                ans=t;
            }
        }
        if(ans.length()==0)
        {
            ans="-1";
            return ans;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends