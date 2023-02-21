//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(int i,int l,int sum,int tar,int s,vector<int>&ds,vector<int>arr,vector<vector<int>>&ans)
  {
      if(i==l)
      {
          if(ds.size()==s && sum==tar)
          {
              ans.push_back(ds);
          }
          return;
      }
      ds.push_back(arr[i]);
      sum+=arr[i];
      solve(i+1,l,sum,tar,s,ds,arr,ans);
      ds.pop_back();
      sum-=arr[i];
      solve(i+1,l,sum,tar,s,ds,arr,ans);
  }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        int l=9;
        vector<int>arr;
        for(int i=1;i<=9;i++)
        {
            arr.push_back(i);
        }
        int sum=0;
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,l,sum,N,K,ds,arr,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends