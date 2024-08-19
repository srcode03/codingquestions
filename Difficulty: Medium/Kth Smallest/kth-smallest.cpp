//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        // code here
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        vector<int>res(maxi+1,0);
        for(int i=0;i<arr.size();i++){
            res[arr[i]]++;
        }
        // for(int i=0;i<res.size();i++){
        //     cout<<res[i]<<" ";
        // }
        int cnt=0;
        for(int i=1;i<=res.size();i++){
            if(res[i]==1){
                cnt++;
                if(cnt==k){
                    return i;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends