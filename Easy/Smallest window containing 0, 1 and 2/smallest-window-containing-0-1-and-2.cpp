//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int smallestSubstring(string S) {
    int zero = 0;
    int one = 0;
    int two = 0;
    int start = 0;
    int curr_length = 0;
    int ans = INT_MAX;
    int i = 0;

    while (i < S.length()) {
        // Count occurrences of '0', '1', and '2' in the current substring
        if (S[i] == '0')
            zero++;
        if (S[i] == '1')
            one++;
        if (S[i] == '2')
            two++;

        i++;
        curr_length++;

        // Check if the current substring contains all three characters
        while (zero > 0 && one > 0 && two > 0) {
            // Update the minimum length of substring containing all characters
            ans = min(ans, curr_length);

            // Shrink the substring from the beginning
            if (S[start] == '0') zero--;
            if (S[start] == '1') one--;
            if (S[start] == '2') two--;

            curr_length--;
            start++;
        }
    }

    // If ans is still INT_MAX, no valid substring found
    if (ans == INT_MAX)
        return -1;
    return ans;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends