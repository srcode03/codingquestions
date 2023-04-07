//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int i=0;
        int j=0;
        int ans=0;
        vector<char>v(27,0);
        while(j<s.length())
        {
            v[s[j]-'a']++;
            if(v[s[j]-'a']>1)
            {
                while(v[s[j]-'a']>1)
                {
                    v[s[i]-'a']--;
                    i++;
                }
                j++;
            }
            else{
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends