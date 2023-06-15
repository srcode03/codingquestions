//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
        void dfs(int node,vector<int>&vis,unordered_map<int,list<pair<int,int>>>&adj,stack<int>&st)
        {
          vis[node]=1;
          for(auto it:adj[node])
          {
              if(!vis[it.first])
              {
                  dfs(it.first,vis,adj,st);
              }
          }
          st.push(node);
        }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>vis(N,0);
        stack<int>st;
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,st);
            }
        }
        vector<int>dis(N,1e9);
        dis[0]=0;
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            if(dis[top]!=1e9)
            {
                for(auto it:adj[top])
                {
                    if(dis[top]+it.second<dis[it.first])
                    {
                        dis[it.first]=dis[top]+it.second;
                    }
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dis[i]==1e9)
            {
                dis[i]=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends