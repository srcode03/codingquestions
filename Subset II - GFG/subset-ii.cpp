//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
   void solve(int i,int n,vector<int>&ds,vector<int>arr,vector<vector<int>>&ans)
    {
        ans.push_back(ds);
        for(int j=i;j<arr.size();j++)
        {
            if(j!=i && arr[j]==arr[j-1])
            {
                continue;
            }
            ds.push_back(arr[j]);
            solve(j+1,n,ds,arr,ans);
            ds.pop_back();
        }
    }           
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        int n=nums.size();
        solve(0,n,ds,nums,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends