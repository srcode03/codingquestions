//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        string t;
        vector<string>v;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='.')
            {
                if(t.length())
                {
                    v.push_back(t);   
                }
                t.clear();
            }
            else{
                t.push_back(str[i]);
            }
        }
        if(t.length())
        {
            v.push_back(t);
        }
        if(v.size()!=4)
        {
            return false;
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i].length()>1)
            {
                if(v[i][0]=='0')
                {
                    return false;
                }
            }
            int b=stoi(v[i]);
            if(b>=0 && b<=255)
            {
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends