// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    class element{
      public:
        int value;
        int lno;
        int index;
        element(int val,int l,int ind){
            value=val;
            lno=l;
            index=ind;
        }
        
    };
     struct compare{
          bool operator()(element a,element b){
            return a.value>b.value;
          }            
        };
  
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          int range=INT_MAX,minVal=INT_MAX,maxVal=INT_MIN;
          pair<int,int>ans;

          priority_queue<element,vector<element>,compare> pq;
          for(int i=0;i<k;i++){
            element ele(KSortedArray[i][0],i,0);
            maxVal=max(maxVal,KSortedArray[i][0]);
            minVal=min(minVal,KSortedArray[i][0]);

            pq.push(ele);
          }
          range=maxVal-minVal;
          ans.first=minVal,ans.second=maxVal;
          while(!pq.empty()){
           element temp=pq.top();
           pq.pop();
           int minVal=temp.value;

           if(range>maxVal-minVal){
               ans.first=minVal;
               ans.second=maxVal;
               range=maxVal-minVal;

           }
      temp.index++;
           if(temp.index==n)break;

          element e(KSortedArray[temp.lno][temp.index],temp.lno,temp.index);
          pq.push(e);
          maxVal=max(maxVal,e.value);
          }
           return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends