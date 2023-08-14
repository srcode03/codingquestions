//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x=x^nums[i];
        }
        int cnt=0;
        while(x)
        {
            if(x&1)
            {
                break;
            }
            cnt++;
            x>>=1;
        }
        int a=0,b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&(1<<cnt))
            {
                a^=nums[i];
            }
            else{
                b^=nums[i];
            }
        }
        vector<int>ans={a,b};
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends