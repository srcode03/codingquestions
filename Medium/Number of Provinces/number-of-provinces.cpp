//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int>&vis,unordered_map<int,list<int>>&adjlist)
    {
        vis[node]=1;
        for(auto it:adjlist[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adjlist);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        unordered_map<int,list<int>>adjlist;
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(adj[i][j]==1)
                {
                    adjlist[i+1].push_back(j+1);
                    adjlist[j+1].push_back(i+1);
                }
            }
        }
        vector<int>vis(V+1,0);
        int ans=0;
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adjlist);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends