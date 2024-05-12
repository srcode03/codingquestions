//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int d,int sdx,int edx){
      
      if(sdx-d>=0 && (sdx-d)%2==0)
      return edx;
      edx++;
      return solve(d,sdx+edx,edx);
  }
    int minSteps(int d) {
        return solve(d,0,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends