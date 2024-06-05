//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
      int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes 
        int sum1 = 0, sum2 = 0;
    for(int i=0;i<n;i++) 
        sum1+=a[i];
    for(int i=0;i<m;i++) 
        sum2 += b[i];
    int val = sum1-sum2;
    if (val%2!= 0) return -1;
    int target = val/2;
    set<int>setA(a,a+n);
    for(int i=0;i<m;i++) {
        int currValue=b[i]+target;
        if(setA.find(currValue)!=setA.end()) {
            return 1; 
        }
    }

    return -1;
   }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends