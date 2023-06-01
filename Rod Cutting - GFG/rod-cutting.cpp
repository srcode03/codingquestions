//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int i,int w,int price[],vector<vector<int>>&dp)
  {
     if(i==0)
     {
         return price[i]*(w/(i+1));
     }
     if(dp[i][w]!=-1)
     {
         return dp[i][w];
     }
     int notake=solve(i-1,w,price,dp);
     int take=-1e9;
     if(i+1<=w)
     {
         take=price[i]+solve(i,w-i-1,price,dp);
     }
     return dp[i][w]=max(take,notake);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int wt=n;
        int ans=solve(n-1,wt,price,dp);
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
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends