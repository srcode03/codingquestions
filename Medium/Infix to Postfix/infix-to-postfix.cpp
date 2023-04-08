//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int val(char ch)
    {
        if(ch=='(')
        {
            return 0;
        }
        else if(ch=='+' || ch=='-')
        {
            return 1;
        }
        else if(ch=='*' || ch=='/')
        {
            return 2;
        }
    }
    string infixToPostfix(string s) {
        // Your code here
        string ans="";
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]))
            {
                ans+=s[i];
            }
            else{
                    if(st.empty())
                    {
                        st.push(s[i]);
                    }
                    else{
                    if(s[i]==')')
                    {
                        while(!st.empty() && st.top()!='(')
                        {
                            ans+=st.top();
                            st.pop();
                        }
                        st.pop();
                    }
                    else if(s[i]=='(')
                    {
                        st.push(s[i]);
                    }
                    else if(val(s[i])<=val(st.top()))
                    {
                        while(!st.empty())
                        {
                            if(val(s[i])>val(st.top()))
                            {
                                break;
                            }
                            ans+=st.top();
                            st.pop();
                        }
                        st.push(s[i]);
                    }
                    else{
                        st.push(s[i]);
                    }
                }
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends