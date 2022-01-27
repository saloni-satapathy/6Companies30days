
// In this  program the adjacency matrix is vector of vector bt if vector of vector is taken time limit exceeds for few test cases so  for array of vector declared as vector<int>adj[N]

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
 bool isCycle(int v,vector<vector<int>>adj, vector<int>&visited, vector<int>&recurStack){
   visited[v]=1;
   recurStack[v]=1;

   
   
   for(auto i= adj[v].begin();i!=adj[v].end();i++){
   if(!visited[*i]){
       if(isCycle(*i,adj,visited,recurStack)){
         return true;
       }
   }else if(recurStack[*i]){
     return true;
   }
   }


   recurStack[v]=0;
   return false;
 }

   vector<vector<int>> buildGraph(vector<pair<int,int>>preq,int N){
     vector<vector<int>>adj(N);
        for(auto x:preq){
          adj[x.second].push_back(x.first);
        }

         return adj;
   }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>adj=buildGraph(prerequisites,N);
    
	    vector<int> visited(N,0);
	    vector<int> recurStack(N,0);

           for(int i=0;i<adj.size();i++){
             for(int j=0;j<adj[i].size();j++){
                   cout<<adj[i][j];
             }
             cout<<endl;
           }
	      for(int i=0;i<N;i++){
	          if(!visited[i]){
	             if(isCycle(i,adj,visited,recurStack)){
	                 return false;
	             }
	         }
	     }
	      return true;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends`
