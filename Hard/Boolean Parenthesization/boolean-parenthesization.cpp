//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int mod= 1003;

    int solve(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue]; 
        
        if(i==j){
            if(isTrue){
                if(s[i]=='T') return 1;
                else{
                    return 0;
                }
            }
            else{
                if(s[i]=='F') return 1;
                else{
                    return 0;
                }
            }
        }
        
        int ways=0;
        
        for(int index=i+1; index<j; index+=2){
            int lt= solve(i,index-1,1,s,dp);
            int lf= solve(i,index-1,0,s,dp);
            int rt= solve(index+1,j,1,s,dp);
            int rf= solve(index+1,j,0,s,dp);
            
            if(s[index]=='&'){
                if(isTrue){
                    ways= (ways%mod + (lt % mod * rt % mod) % mod ) % mod; 
                }
                else{
                    ways= (ways%mod + (lf % mod * rt % mod)%mod + (lt % mod * rf % mod)%mod + (lf % mod * rf % mod)%mod ) % mod;
                }
            }
            
            else if(s[index]=='|'){
                if(isTrue){
                    ways= (ways%mod + (lf % mod * rt % mod)%mod + (lt % mod * rf % mod)%mod + (lt % mod * rt % mod)% mod )%mod;
                }
                else{
                    ways=(ways%mod + (lf % mod * rf % mod)% mod) % mod;
                }
            }
            else{
                if(isTrue){
                    ways= (ways%mod + (lf % mod * rt % mod)%mod + (lt % mod * rf % mod)% mod) % mod;
                }
                else{
                    ways=(ways%mod + (lt % mod * rt % mod)%mod + (lf % mod * rf % mod)%mod) % mod;
                }
                
            }
            
            
        }
        dp[i][j][isTrue]= ways % mod;
        return dp[i][j][isTrue];
        
        
    }

    int countWays(int N, string S){
        
        vector<vector<vector<int>>>dp(N+1, vector<vector<int>>(N+1, vector<int>(3,-1)));
        return solve(0,N-1,1,S,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends