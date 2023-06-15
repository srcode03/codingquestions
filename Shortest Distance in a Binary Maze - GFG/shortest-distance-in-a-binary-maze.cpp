//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> de) {
        // code here
        if(grid[de.first][de.second]==0 || grid[source.first][source.second]==0)
        {
            return -1;
        }
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e5));
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{source.first,source.second}});
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};
        while(!pq.empty())
        {
            int r=pq.front().second.first;
            int c=pq.front().second.second;
            int d=pq.front().first;
            if(r==de.first && c==de.second)
            {
                return d;
            }
            pq.pop();
            for(int i=0;i<4;i++)
            {
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && d+1<dis[nr][nc])
                    {
                        dis[nr][nc]=1+d;
                        if(nr==de.first && nc==de.second)
                        {
                            return 1+d;
                        }
                        pq.push({d+1,{nr,nc}});
                    }
                
            }
            
        }
        return -1;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends