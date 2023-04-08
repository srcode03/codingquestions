//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
       stack<string>st;
       for(int i=s.length()-1;i>=0;i--)
       {
           if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
           {
               string s1=st.top();
               st.pop();
               string s2=st.top();
               st.pop();
               string t="("+s1+s[i]+s2+")";
               st.push(t);
           }
           else{
                st.push(string(1,s[i]));
           }
       }
       string ans=st.top();
       return ans;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends