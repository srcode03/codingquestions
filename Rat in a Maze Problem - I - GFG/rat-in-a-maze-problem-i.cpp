//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void solve(int i,int j,int r,int c,string temp,vector<vector<int>>&vis,vector<vector<int>>&v)
    {
        if(i==r-1 && j==c-1)
        {
            ans.push_back(temp);
            return;
        }
        //move downwards
        if(i+1>=0 && i+1<r && vis[i+1][j]!=1 && v[i+1][j]==1)
        {
            vis[i][j]=1;
            solve(i+1,j,r,c,temp+'D',vis,v);
            vis[i][j]=0;
        }
        //move leftwards
        if(j-1>=0 && j-1<c && vis[i][j-1]!=1 && v[i][j-1]==1)
        {
            vis[i][j]=1;
            solve(i,j-1,r,c,temp+'L',vis,v);
            vis[i][j]=0;
        }
        //move rightwards
        if(j+1>=0 && j+1<c && vis[i][j+1]!=1 && v[i][j+1]==1)
        {
            vis[i][j]=1;
            solve(i,j+1,r,c,temp+'R',vis,v);
            vis[i][j]=0;
        }
        //move upwards
        if(i-1>=0 && i-1<r && vis[i-1][j]!=1 && v[i-1][j]==1)
        {
            vis[i][j]=1;
            solve(i-1,j,r,c,temp+'U',vis,v);
            vis[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &v, int n) {
        // Your code goes here
        string temp;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(v[0][0]==1)solve(0,0,n,n,temp,vis,v);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends