//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string>ans;
	    void solve(int i,string ds,string s)
	    {
	        if(i==s.length())
	        {
	            if(ds.length())
	            {
	                ans.push_back(ds);     
	            }
	            return;
	        }
	        ds.push_back(s[i]);
	        solve(i+1,ds,s);
	        ds.pop_back();
	        solve(i+1,ds,s);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string ds;
		    solve(0,ds,s);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends