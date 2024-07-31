//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    static bool func(string a,string b)
    {
        return a.length()<b.length();
    }
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if(arr.size()==1)return arr[0];
        sort(arr.begin(),arr.end(),func);
        string s=arr[0];
        string ans;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            int fg=0;
            for(int j=1;j<arr.size();j++)
            {
                if(arr[j][i]!=ch)
                {
                    fg=1;
                    break;
                }
            }
            if(fg==0)
            {
                ans.push_back(ch);
            }
            else{
                if(ans.length()==0)return "-1";
                return ans;
            }
        }
        return "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends