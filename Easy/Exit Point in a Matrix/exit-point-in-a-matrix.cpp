//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat)
    {
        // Code here
        vector<int>t;
        vector<pair<int,int>>v;
        v.push_back({0,1});
        v.push_back({1,0});
        v.push_back({0,-1});
        v.push_back({-1,0});
        int r=0;
        int c=0;
        int i=0;
        while(true)
        {
            if(mat[r][c]==1)
            {
                mat[r][c]=0;
                i=(i+1)%4;
            }
            int nr=r+v[i].first;
            int nc=c+v[i].second;
            if(nr>=n || nr<0 || nc>=m || nc<0)
            {
                t.push_back(r);
                t.push_back(c);
                return t;
            }
            r=nr;
            c=nc;
        }
        return t;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends