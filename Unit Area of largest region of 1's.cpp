// grid itself is changed for 1 to 0 once it is visited. If a separate seen/visited matric is used it causes time limit exceed


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int getarea( int row,int column, vector<vector<int>>&grid){
        
        if(row<0||column<0||row>=grid.size()||column>=grid[0].size()){
            return 0;
        }
        if(grid[row][column]==0){
            return 0;
        }
        
        //seen[row][column]=true;
        grid[row][column]=0;
        int size=1;
         for(int i=row-1;i<=row+1;i++){ 
             for(int j=column-1;j<=column+1;j++)
             { 
               if(row!=i || column!=j){   
               size+=getarea(i,j,grid);
               }
             }
         }
          return size;
    
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans= INT_MIN;
        int n=grid.size(),m=grid[0].size();
     //   vector<vector<bool>>seen(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 //if(grid[i][j]==1 && seen[i][j]==false){
                 if(grid[i][j]==1){
                int size= getarea(i,j,grid);
                 ans= max(ans,size);
                 }
             }
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends