//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& e, int N,int M, int src)
    {
        // code here
        unordered_map<int,list<int>>adj;
        for(int i=0;i<M;i++)
        {
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        vector<int>dis(N,1e9);
        dis[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(dis[node]+1<dis[it])
                {
                    dis[it]=1+dis[node];
                    q.push(it);
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends