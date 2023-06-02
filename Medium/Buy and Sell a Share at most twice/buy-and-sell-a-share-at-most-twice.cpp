//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            for(int k=1;k<=2;k++)
            {
                if(j==1)
                {
                    dp[i][j][k]=max(-price[i]+dp[i+1][0][k],dp[i+1][1][k]);
                }
                else{
                    dp[i][j][k]=max(price[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                }
            }
        }
    }
    return dp[0][1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends