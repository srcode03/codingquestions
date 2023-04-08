//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string s) {

        stack<string>ans;

        for(auto it:s)

        {

           if(isalpha(it))

          {

              string temp="";

              temp+=it;

              ans.push(temp);

          }

          else

          {

              string val2=ans.top();

              ans.pop();

              string val1=ans.top();

              ans.pop();

              ans.push('(' + val1 + it + val2 + ')');

          }

        }

        return ans.top();

    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends