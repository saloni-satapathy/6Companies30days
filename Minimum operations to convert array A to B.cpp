// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int lis(vector<int> newA){
                 
                 int N=newA.size();
         vector<int>seq;
         seq.push_back(newA[0]);
          for(int i=1;i<N;i++){
              if(seq.back()<newA[i])
               seq.push_back(newA[i]);
              else{
                  int ind= lower_bound(seq.begin(),seq.end(),newA[i])- seq.begin();
                  if(ind<N)
                   seq[ind]=newA[i];
              }
          }
          return seq.size();
    }
   
    int minInsAndDel(int A[], int B[], int N, int M) {
      // if size of one array is zero then we have to insert/delete all the elements of the other array
      if(N==0)
       return M;
      if(M==0)
       return N;
// the newA conatains all the elements that are present in B
      unordered_set<int>newB;
      for(int i=0;i<M;i++)
       newB.insert(B[i]);
      
      vector<int>newA;
      for(int i=0;i<N;i++){
          if(newB.find(A[i])!=newB.end())
              newA.push_back(A[i]);
          
      }
       // if the Array A and B have no common element the we have to perform N deletion and M insertions so total is N+M
       if(newA.size()==0)
        return N+M;
        
       int LIS=lis(newA);
       return (N+M)-2*(LIS);
         
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends