//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int>dr={-1,1,0,0};
    vector<int>dc={0,0,1,-1};
    int n,m;
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        for(int k=0;k<4;k++)
        {
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m)
            {
                if(grid[nr][nc]==1 && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    dfs(nr,nc,grid,vis);    
                }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                vis[i][0]=1;
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1)
            {
                vis[i][m-1]=1;
                dfs(i,m-1,grid,vis);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
            {
                vis[0][i]=1;
                dfs(0,i,grid,vis);
            }
            if(grid[n-1][i]==1)
            {
                vis[n-1][i]=1;
                dfs(n-1,i,grid,vis);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    ans++;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends