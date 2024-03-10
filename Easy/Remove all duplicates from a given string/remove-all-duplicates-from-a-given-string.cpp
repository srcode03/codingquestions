//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    string st = "";
	    unordered_map<char, int> mp;
	    int i = 0;
	    while(str[i]!='\0'){
	        if(mp[str[i]]==0){
	            st += str[i];
	        }
	        mp[str[i]]++;
	        i++;
	    }
	    return st;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends