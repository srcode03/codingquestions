//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/
#define ll long long
class Solution
{
    int M=1E9+7;
    public:
    int subsequenceCount(string s, string t)
    {
      //Your code here
        ll int l1=s.length();
        ll int l2=t.length();
        vector<vector<ll int>>dp(l1+1,vector<ll int>(l2+1,0));
        for(ll int i=0;i<=l1;i++)
        {
            dp[i][0]=1;
        }
        for(ll int i=1;i<=l1;i++)
        {
            for(ll int j=1;j<=l2;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%M;
                }
                else{
                    dp[i][j]=dp[i-1][j]%M;
                }
            }
        }
        return dp[l1][l2];
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends