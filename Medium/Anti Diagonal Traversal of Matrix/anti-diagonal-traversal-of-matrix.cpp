//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) 
    {
        int n = mat.size(); 
        vector<int> res; 
        
        int i = 0, j = 0; 
        while(i < n && j < n) {
            int i1 = i, j1 = j; 
            while(i1 < n && j1 >= 0) {
                res.push_back(mat[i1][j1]); 
                i1++, j1--; 
            }
            if(j == n - 1) i++; 
            else j++; 
        }
        return res; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends