//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int i=0;
        int j=0;
        int c=0;
        int ans=INT_MIN;
        while(i<n && j<n)
        {
            while(k>=0 && j<n)
            {
                if(nums[j]==0)
                {
                    if(k==0)
                    {
                        break;
                    }
                    k--;
                    j++;
                    c++;
                }
                else{
                    j++;
                    c++;
                }
            }
            ans=max(ans,c);
            while(i<=j)
            {
                if(nums[i]==0)
                {
                    k++;
                    i++;
                    c--;
                    break;
                }
                else{
                i++;
                c--;
                }
            }
        }
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
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends