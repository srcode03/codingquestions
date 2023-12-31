//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
     int solveTab(int N, int coins[], int sum){
        vector<vector<int>> dp(N+1, vector<int>(sum+1, 0)) ;
        
        for(int i = 0; i<=N ; i++){
            for(int col = 0; col<=sum; col++){
                if(col!=0&&(col%20==0||col%24==0||col%2024==0)){
                    dp[i][col] = 1;
                }
            }
        }
        
        for(int ind = N-1 ; ind>=0 ; ind--){
            for(int col = sum; col>=0; col--){
                if(col!=0&&(col%20==0||col%24==0||col%2024==0)){
                    continue;
                }
                int ans1 = 0, ans2=0 ;
                 
                if(col+coins[ind]<=sum)
                  ans1 = dp[ind+1][col+coins[ind]] ;
                ans2 = dp[ind+1][col] ;
                
                dp[ind][col]=ans1||ans2;
                
            } 
        }
        
        return dp[0][0] ;
    }
    int isPossible(int N , int coins[]) 
    {
        // vector<vector<int>> dp(367, vector<int>(2025, -1)) ;
        // return solve(N, coins, 0, 0, dp) ;
        
        int sum = 0 ;
        sum = accumulate(coins, coins + N, sum) ;
        // cout<<sum<<endl;
        return solveTab(N, coins, sum) ;
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends