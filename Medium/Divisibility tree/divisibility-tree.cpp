//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // Helper function to perform depth-first search
    // mp: Adjacency list representing the tree
    // u: Current node being visited
    // parent: Parent node of the current node
    // ans: Reference to the count of edges to be removed
    // Returns: Number of nodes in the subtree rooted at 'u'
    int dfs(std::unordered_map<int, std::vector<int>>& mp, int u, int parent, int& ans) {
        int count = 1; // Initializing count to 1 to include the current node
        
        // Iterating through the adjacent nodes of 'u'
        for (auto& i : mp[u]) {
            if (i != parent) { // If the adjacent node is not the parent
                int subtree = dfs(mp, i, u, ans); // Recursively visit the adjacent node
                if (subtree % 2 == 0) { // If the subtree rooted at the adjacent node has even number of nodes
                    ans++; // Increment the count of edges to be removed
                } else {
                    count++; // Increment the count of nodes in the current subtree
                }
            }
        }
        return count; // Return the count of nodes in the subtree rooted at 'u'
    }
    
    // Function to find the minimum number of edges to be removed
    // to convert the tree into a disjoint union tree with even-sized components
    // n: Number of nodes in the tree
    // edges: Edges of the tree represented as pairs of connected nodes
    // Returns: Minimum number of edges to be removed
    int minimumEdgeRemove(int n, std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> mp; // Adjacency list to represent the tree
        
        // Constructing the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0]; // First node of the edge
            int v = edges[i][1]; // Second node of the edge
            mp[v].push_back(u); // Adding 'u' to the adjacency list of 'v'
            mp[u].push_back(v); // Adding 'v' to the adjacency list of 'u'
        }
        
        int ans = 0; // Initializing the count of edges to be removed
        
        // Performing depth-first search starting from the root node '1'
        dfs(mp, 1, -1, ans);
        
        return ans; // Returning the minimum number of edges to be removed
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends