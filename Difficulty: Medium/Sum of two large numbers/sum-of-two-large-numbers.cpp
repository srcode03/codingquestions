//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
         reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    
    if (X.size() < Y.size()) swap(X, Y);
    
    int add = 0, r = 0, i = 0;
    
    while (i < Y.size()) {
        add = (X[i] - '0' + Y[i] - '0' + r);
        r = add / 10;
        X[i++] = char(add % 10 + 48);
    }
    
    while (i < X.size() and r) {
        add = (X[i] - '0' + r);
        r = add / 10;
        X[i++] = char(add % 10 + 48);
    } 
    
    if (r) X += "1";
    
    while (X.size() > 1 and X.back() == '0') X.pop_back(); 
    
    reverse(X.begin(), X.end());
    
    return X;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends