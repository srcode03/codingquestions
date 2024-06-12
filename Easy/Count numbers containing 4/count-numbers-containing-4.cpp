//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n)
    {
        // code here
         int count=0;
        
        for(int i=1;i<=n;i++){
            
            // Convert the current number in to its string representation
            string str=to_string(i);
            
             // Check if the string contains the digit '4'
            if(str.find('4') != std::string::npos){
                count++;//If it contain,then  increment the count
            }
        }
        
        //finally return the count 
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends