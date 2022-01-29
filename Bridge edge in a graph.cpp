// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    bool dfs(int c,int d,vector<int>vec[],vector<bool>& visited)
    {
        //it's mean you are able to reach the point from start to destination node
        if(c==d)
        {
            return true;
        }
        visited[c] = true;
        for(auto x : vec[c])
        {
            if(!visited[x])
            {
                if(dfs(x,d,vec,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }

    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
                vector<int> vec[V];
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            for( auto x : adj[i])
            {
                if((x==c and i==d) || (x==d and i==c))
                {
                    continue;
                }
                vec[i].push_back(x);
            }
        }
        //take negation there because it will return answer that it will connect so if connect then actual answer is false
        return !dfs(c,d,vec,visited);

    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends