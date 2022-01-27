class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int total=0,count=0,ans=0;
    queue<pair<int,int>>q;
   for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
       if(grid[i][j]==2){
            q.push(make_pair(i,j));
       }
       else if(grid[i][j]==0){
         total++;
        }
     }
   }  
   

   int dx[4]={0,1,-1,0};
   int dy[4]={1,0,0,-1};
   while(!q.empty()){
     int k=q.size();
     count+=k;
     while(k--){
    pair<int,int> p=q.front();
    q.pop();
   
   int a=p.first,b=p.second;
  for(int i=0;i<4;i++){
    int a=p.first,b=p.second;
    a+=dx[i],b+=dy[i];
  if(a<0 || a>m-1 || b<0 || b>n-1 || grid[a][b]!=1){
   continue;
    }else{
      if(grid[a][b]==1){
        grid[a][b]=2;
        q.push(make_pair(a,b));
      }
    }
  }
     }
   if(!q.empty())
     ans++;
   }   

   return (m*n-total)==count?ans:-1;
        
    }
};
