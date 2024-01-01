//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
        int n = nums.size();
        if(n%2!=0) return false;
        map<int,int>mp;
        
        // store the modulo value


        for(auto it:nums){
            mp[it%k]++;
        }
        
        // check if abs(k-mp[val]) exist in map or not if yes then check for the other conditions
        
        for(auto it:mp){
            int val = abs(it.first-k);
            if(it.first==val && it.second%2!=0) return false;
            if(it.first==0 && it.second%2==0)continue;
            if(it.second>0 && mp.find(val)!=mp.end()){
                if(mp[val]>=it.second){
                    mp[val] -= it.second;
                    mp[it.first]-= it.second;
                    
                }
                else return false;
            }
            else if(mp.find(val)==mp.end()) return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends