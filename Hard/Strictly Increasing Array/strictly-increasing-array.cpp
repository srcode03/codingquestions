//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int dp[1001][1007];
    int solve(int i,int pre,int n,vector<int>&nums){
        if(i==nums.size()) return 0;
        if(dp[i][pre+1]!=-1) return dp[i][pre+1];
        int ans=0;
        if(pre==-1){
            ans=max({ans,1+solve(i+1,i,n,nums)});
        }
        if(pre!=-1 and nums[i]>nums[pre] and nums[i]-nums[pre]>=i-pre){
            ans=max({ans,1+solve(i+1,i,n,nums)});
        }
        ans=max(ans,solve(i+1,pre,n,nums));
        return dp[i][pre+1]=ans;
    }
    int min_operations(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return nums.size()-solve(0,-1,nums.size(),nums);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends