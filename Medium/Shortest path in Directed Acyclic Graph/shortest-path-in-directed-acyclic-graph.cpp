//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& e)
     {
        // code here
        unordered_map<int,list<pair<int,int>>>adj;
        queue<int>q;
        vector<int>in(N,0);
        for(int i=0;i<M;i++)
        {
            adj[e[i][0]].push_back({e[i][1],e[i][2]});
            in[e[i][1]]+=1;
        }
        for(int i=0;i<N;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>t;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            t.push_back(f);
            for(auto it:adj[f])
            {
                int val=it.first;
                in[val]-=1;
                if(in[val]==0)
                {
                    q.push(val);
                }
            }
        }
        vector<int>dis(N,1e9);
        for(int i=0;i<t.size();i++)
        {
            int val=t[i];
            if(i==0)
            {
                dis[val]=0;
            }
            for(auto it:adj[val])
            {
                if(dis[val]+it.second<dis[it.first])
                {
                    dis[it.first]=dis[val]+it.second;
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