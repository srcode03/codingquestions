//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        stack<char>st;
        int i=0;
        string ans="";
        while(i<s.length())
        {
            if(st.empty())
            {
                st.push(s[i]);
                i++;
            }
            else{
                string t="";
                while(st.size()>=1 && i<s.length())
                {
                    if(s[i]=='(')
                    {
                        st.push(s[i]);
                        t+=s[i];
                    }
                    else if(s[i]==')')
                    {
                        st.pop();
                        if(!st.empty())
                        {
                            t+=s[i];
                        }
                    }
                    i++;
                }
                ans.append(t);
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
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends