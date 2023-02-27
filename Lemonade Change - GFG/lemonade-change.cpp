//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int c1=0;
        int c2=0;
        int c3=0;
        int fg=0;
        for(int i=0;i<N;i++)
        {
            if(bills[i]==10)
            {
               if(c1==0)
               {
                   return false;
                   fg=1;
                   break;
               }
               else{
                   c2++;
                   c1--;
               }
            }
            else if(bills[i]==20)
            {
                if(c1>0 && c2>0)
                {
                    c1--;
                    c2--;
                    c3++;
                }
                else if(c1>=3)
                {
                    c1-=3;
                    c3++;
                }
                else{
                   return false;
                    fg=1;
                    break;
                }
            }
            else{
                c1++;
            }
        }
        if(fg==0)
        {
            return true;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends