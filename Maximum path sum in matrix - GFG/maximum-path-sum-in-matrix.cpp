//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(j<0 || j>grid[0].size()-1)
        {
            return -1e9;
        }
        if(i==0)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=grid[i][j]+solve(i-1,j,grid,dp);
        int l=grid[i][j]+solve(i-1,j-1,grid,dp);
        int r=grid[i][j]+solve(i-1,j+1,grid,dp);
        return dp[i][j]=max(up,max(l,r));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,-1));
        int ans=INT_MIN;
        for(int i=N-1;i>=0;i--)
        {
            ans=max(ans,solve(N-1,i,Matrix,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends