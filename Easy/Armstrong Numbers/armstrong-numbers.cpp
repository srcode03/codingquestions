//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
         int temp = n;   // copy the original number and perform the operations on that number
        long long int ans = 0;  // initialise the ans with long long int with a value 0
        while(temp > 0){   // compute until temp < 0
            int rem = temp % 10;
            ans = ans + pow(rem, 3);
            temp /= 10;
        }
        
        return n == ans ? "Yes" : "No"; // return the string using ternary operator
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends