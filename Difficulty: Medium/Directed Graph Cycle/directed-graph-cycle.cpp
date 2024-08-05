//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>in(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                in[it]+=1;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        int ct=0;
        while(!q.empty())
        {
            int node=q.front();
            ct+=1;
            q.pop();
            for(auto it:adj[node])
            {
                in[it]-=1;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(ct==V)
        {
            return 0;
        }
        else{
            return 1;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends